#include<iostream>
using namespace std;
typedef long long int llt;

llt GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}

llt LCN(int a, int b) {
	llt c = GCD(a, b);
	return (llt)a * b / c;
}

int main(void) {
	int n;
	cin >> n;
	while (n--) {
		llt a, b;
		cin >> a >> b;

		cout << LCN(a, b) << "\n";
	}
	return 0;
}