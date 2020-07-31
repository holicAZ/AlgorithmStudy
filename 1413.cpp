#include<iostream>
using namespace std;
// [n, k] = [n - 1, k - 1] + (n - 1) * [n - 1, k] ��1�� ���и� ��ȭ��
typedef long long ll; // �޸𸮵� �Ű�� ����Ѵ�.
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
	for (int l = 1; l <= n; l++) {	// �и� n ������ ��� ���
		A += arr[n][l];
	}
	
	for (int l = 1; l <= m; l++) { // ���� n�϶� ��ź�� ���� 1���� m������ ������� 
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