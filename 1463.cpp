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
	
	fill(dp, dp + N, MAX); // N만큼 MAX로 초기화
	dp[1] = 0; // 1은 연산 x
	dp[2] = dp[3]= 1; 

	if (N == 1) {
		cout << 0;
		return 0;
	}
	
	for (int i = 4; i <= N; i++) {
		int tmp1 = MAX, tmp2 = MAX;// tmp1,2 는 임시 저장소
		// 2로 나눠지고, 3으로 나눠지고, -1연산이 모두 일어날 수도 있기때문에 if문 처리
		if (i % 2 == 0) { 
			tmp1 = dp[i / 2]+1;
		}

		if (i % 3 == 0) {
			tmp2 = dp[i / 3]+1;
		}
		
		dp[i] = min(min(tmp1, tmp2), dp[i - 1]+1); // 세 개의 연산 중 최소 값의 연산을 택한다.
	}
	
	cout << dp[N];
	return 0;
}