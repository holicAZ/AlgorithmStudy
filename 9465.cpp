#include<iostream>
#include<cmath>
using namespace std;

int dp[2][100001] = { 0, }, s[2][100001];
int main(void) {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int k = 0; k < n; k++) {
				cin >> s[i][k];
			}
		}

		dp[0][1] = s[0][0];
		dp[1][1] = s[1][0];

		for (int i = 2; i <= n; i++) {
			dp[0][i] = s[0][i - 1] + max(dp[1][i - 2], dp[1][i - 1]);
			dp[1][i] = s[1][i - 1] + max(dp[0][i - 2], dp[0][i - 1]);
		}

		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}