#include <iostream>
using namespace std;
typedef long long ll;

ll save_fibo[100] = {0,};

ll fibo(int n) {
	if (n < 2) {
		return 1;
	}

	if (save_fibo[n]!=0) {
		return save_fibo[n];
	}

	else {
		save_fibo[n] = fibo(n - 1) + fibo(n - 2);
		return save_fibo[n];
	}
}
int main(void) {
	int n;
	cin >> n;
	ll ans = (ll)(fibo(n) * 2) + (fibo(n - 1) * 2);
	cout << ans;
}