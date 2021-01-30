#include<iostream>
using namespace std;

int dp[11];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1]+ dp[i - 2]+ dp[i - 3]; // 1, 2, 3 �� ������ ��Ÿ���� n-3, n-2, n-1 ���� �� = dp[n]
		}
		cout << dp[n] << "\n";
	}
	return 0;
}
