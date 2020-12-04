#include<iostream>
using namespace std;
typedef long long ll;
int arr[101];
ll GCD(ll a, ll b) {
	return b ? GCD(b, a % b) : a;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 2; i <= n; i++) {
		ll k = GCD(arr[1], arr[i]);
		cout << arr[1] / k << "/" << arr[i] / k << "\n";
	}
	return 0;
}