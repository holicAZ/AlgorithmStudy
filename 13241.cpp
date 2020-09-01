#include<iostream>
using namespace std;
typedef long long int llt;
int arr[101];
llt GCD(llt a, llt b) {
	return b ? GCD(b, a % b) : a;
}

llt LCM(llt a,llt b) {
	llt c = GCD(a, b);
	return a * b / c;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	cout << LCM(n, m);
	return 0;
}