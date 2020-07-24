#include<iostream>
using namespace std;

bool check[1001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	check[1] = true;	// 1 은 소수가 아니므로 체크
	for (int i = 2; i < 1001; i++) {
		if (check[i]) continue;	// 소수가 아니면 continue
		for (int j = i*2; j < 1001; j+=i) {
			check[j] = true;    // 소수의 배수를 모두 체크
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