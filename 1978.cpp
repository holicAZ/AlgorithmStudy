#include<iostream>
using namespace std;

bool check[1001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	check[1] = true;	// 1 �� �Ҽ��� �ƴϹǷ� üũ
	for (int i = 2; i < 1001; i++) {
		if (check[i]) continue;	// �Ҽ��� �ƴϸ� continue
		for (int j = i*2; j < 1001; j+=i) {
			check[j] = true;    // �Ҽ��� ����� ��� üũ
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		
		if (!check[m]) cnt++;

	}
	cout << cnt << "\n";
	return 0;
}