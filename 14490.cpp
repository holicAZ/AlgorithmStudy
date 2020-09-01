#include<iostream>
#include<string>

using namespace std;
typedef long long ll;

ll GCD(ll a, ll b) {
	return b ? GCD(b, a % b) : a;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string n, a, b;
	cin >> n;
	int idx = n.find(':');	// 문자열을 입력받고 ':'의 위치를 찾는다.
	a = n.substr(0, idx);	// 문자열의 시작 - ':' 까지의 문자열을 저장
	b = n.substr(idx + 1, n.length()); // ':' 다음부터 문자열의 끝까지의 문자열을 저장
	ll x = stoull(a);	// 저장한 문자열의 unsigned long long 형태로 형변환
	ll y = stoull(b);
	ll z = GCD(x, y);	// 형변환한 수의 최대공약수를 구해서 나눠준다.
	cout << x / z << ":" << y / z;
	return 0;
}