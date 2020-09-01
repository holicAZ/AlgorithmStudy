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
	int idx = n.find(':');	// ���ڿ��� �Է¹ް� ':'�� ��ġ�� ã�´�.
	a = n.substr(0, idx);	// ���ڿ��� ���� - ':' ������ ���ڿ��� ����
	b = n.substr(idx + 1, n.length()); // ':' �������� ���ڿ��� �������� ���ڿ��� ����
	ll x = stoull(a);	// ������ ���ڿ��� unsigned long long ���·� ����ȯ
	ll y = stoull(b);
	ll z = GCD(x, y);	// ����ȯ�� ���� �ִ������� ���ؼ� �����ش�.
	cout << x / z << ":" << y / z;
	return 0;
}