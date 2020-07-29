#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll time[101];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, c;
	cin >> n >> c;
	vector<bool> check(c+1,false);	// ���׼��� �ð� c+1 ��ŭ bool ���� false�� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		cin >> time[i];			// �� �л��� �Ͷ߸��� �ֱ� �Է�
	}
	
	for (ll i = 1; i <= n; i++) {
		for (ll j = time[i]; j <= c; j = j + time[i]) // ���� �ֱ� ���� checkǥ��
			check[j] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= c; i++)
		if (check[i]) cnt++;

	cout << cnt;
	return 0;
}