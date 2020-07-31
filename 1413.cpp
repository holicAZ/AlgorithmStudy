#include<iostream>
using namespace std;
// [n, k] = [n - 1, k - 1] + (n - 1) * [n - 1, k] 제1종 스털링 점화식
typedef long long ll; // 메모리도 신경써 줘야한다.
ll arr[21][21] = { 1 };
ll A = 0, B = 0;

ll GCD(ll a, ll b) {
	return b ? GCD(b, a % b) : a;
}
void Stiring(int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + (i - 1) * arr[i - 1][j]);
		}
	}
	for (int l = 1; l <= n; l++) {	// 분모 n 가지의 모든 경우
		A += arr[n][l];
	}
	
	for (int l = 1; l <= m; l++) { // 분자 n일때 폭탄의 수가 1부터 m까지의 누적경우 
		B += arr[n][l];
	}
	ll c = GCD(B, A);

	cout << B / c << "/" << A / c;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	Stiring(n, m);
	return 0;
}