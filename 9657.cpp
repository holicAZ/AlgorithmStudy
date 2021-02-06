#include<iostream>
using namespace std;

int dp[1001] = { 0, };
int main(void) {
	int n;
	cin >> n;
	dp[1] = dp[3] = dp[4] = 1;
	dp[2] = 0;
	for (int i = 5; i <= n; i++) {
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4] ) {
			dp[i] = 1;
		}
		else
			dp[i] = 0;
	}
	if (dp[n])
		cout << "SK";
	else
		cout << "CY";
}