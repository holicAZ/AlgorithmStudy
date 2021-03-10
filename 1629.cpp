#include<iostream>
using namespace std;
typedef long long ll;

int a, b, c;

ll power(int n, int t) { //2^8 -> (2^2)^2)^2
	if (t == 0)
		return 1;

	ll temp = power(n, t / 2); 
	ll ans = (temp * temp) % c; // overflow가 나지 않도록 mod
	// A * B % C => (A%C * B%C) %C

	if (t % 2) { // 지수가 홀수면 곱해지는 수를 한 번 더 곱해서 짝수로 만들어 준다.
		return (ans * n) % c;
	}
	return ans;
}
int main(void) {
	cin >> a >> b >> c;
	cout << power(a, b); 
	
	return 0;
}