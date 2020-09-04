#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 999999
int dp[1000001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	
	fill(dp, dp + N, MAX); // N��ŭ MAX�� �ʱ�ȭ
	dp[1] = 0; // 1�� ���� x
	dp[2] = dp[3]= 1; 

	if (N == 1) {
		cout << 0;
		return 0;
	}
	
	for (int i = 4; i <= N; i++) {
		int tmp1 = MAX, tmp2 = MAX;// tmp1,2 �� �ӽ� �����
		// 2�� ��������, 3���� ��������, -1������ ��� �Ͼ ���� �ֱ⶧���� if�� ó��
		if (i % 2 == 0) { 
			tmp1 = dp[i / 2]+1;
		}

		if (i % 3 == 0) {
			tmp2 = dp[i / 3]+1;
		}
		
		dp[i] = min(min(tmp1, tmp2), dp[i - 1]+1); // �� ���� ���� �� �ּ� ���� ������ ���Ѵ�.
	}
	
	cout << dp[N];
	return 0;
}