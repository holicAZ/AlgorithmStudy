#include<iostream>
using namespace std;
typedef long long ll;
ll dp[91];

ll fb(ll c) {
	if (c <= 1) return 1;
	if (dp[c - 1])
		return dp[c] = dp[c - 1] + dp[c - 2];
	else
		return dp[c] = fb(c - 1) + fb(c - 2);
}
int main(void) {
	ll n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	fb(n);
	cout << dp[n];
}