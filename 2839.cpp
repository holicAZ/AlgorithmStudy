#include <iostream>
#include <algorithm>
#define MAX 2000 // MAX ���� ������ ���Ƿ� ����
				 // 1. MAX * 5000 < int ���� ��
				 // 2. 5000 / 3 ���� ū ��
using namespace std;

int dp[5001]; // �ռ� N���� ���� ����

int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) dp[i] = MAX; // �ּҰ��� ã������ ó���� MAX������ �ʱ�ȭ
	dp[3] = dp[5] = 1;
	
	for (int i = 6; i <= N; i++)
		dp[i] = min(dp[i - 3], dp[i - 5]) + 1; 
	
	if (dp[N] >= MAX) cout << -1;
	else cout << dp[N];
	return 0;
}