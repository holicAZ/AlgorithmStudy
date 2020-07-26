#include <iostream>
#include <cstring>
using namespace std;

bool check[123456*2];

int main(void) {
	int n;
	
	while (true) {
		int cnt = 0;
		memset(check, false, sizeof(check));

		cin >> n;
		if (n == 0) break;
		if (n == 1) {
			cout << 1 << endl; 
			continue;
		}
		
		for (int i = 2; i <= 2 * n; i++) {
			if (check[i]) continue;

			for (int j = i * 2; j <= 2 * n; j += i) {
				check[j] = true;
			}

		}
		for (int i = n+1; i <= 2 * n; i++) {
			if (!check[i]) cnt++;
		}
		cout << cnt << "\n";
		
	}
	return 0;
}