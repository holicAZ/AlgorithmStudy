#include<iostream>
using namespace std;
int n, m;
int E(int n) { // factorial ���
	if (n <= 0) return 1;
	return n * E(n - 1);
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a=1,b;
	cin >> n >> m;
	b = E(m); // factorial
	for (int i = 0; i < m; i++) {	// n���� m�� -1 �ϸ鼭 ��� ������
		a *= n;
		n--;
	}
	cout << a / b;
	return 0;
}