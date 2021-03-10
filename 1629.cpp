#include<iostream>
using namespace std;
typedef long long ll;

int a, b, c;

ll power(int n, int t) { //2^8 -> (2^2)^2)^2
	if (t == 0)
		return 1;

	ll temp = power(n, t / 2); 
	ll ans = (temp * temp) % c; // overflow�� ���� �ʵ��� mod
	// A * B % C => (A%C * B%C) %C

	if (t % 2) { // ������ Ȧ���� �������� ���� �� �� �� ���ؼ� ¦���� ����� �ش�.
		return (ans * n) % c;
	}
	return ans;
}
int main(void) {
	cin >> a >> b >> c;
	cout << power(a, b); 
	
	return 0;
}