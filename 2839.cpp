#include <iostream>
#include <algorithm>
#define MAX 2000 // MAX 값의 범위는 임의로 선정
				 // 1. MAX * 5000 < int 범위 안
				 // 2. 5000 / 3 보다 큰 값
using namespace std;

int dp[5001]; // 앞선 N값의 개수 저장

int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) dp[i] = MAX; // 최소값을 찾기위해 처음에 MAX값으로 초기화
	dp[3] = dp[5] = 1;
	
	for (int i = 6; i <= N; i++)
		dp[i] = min(dp[i - 3], dp[i - 5]) + 1; 
	
	if (dp[N] >= MAX) cout << -1;
	else cout << dp[N];
	return 0;
}