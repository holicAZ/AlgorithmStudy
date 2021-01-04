#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501] = { 0, };

int main(void) {
	int n,c;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++) {
			cin >> dp[i][k];
			dp[i][k] = dp[i][k] + max(dp[i - 1][k - 1], dp[i - 1][k]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[n][i]);

	cout << ans;
}