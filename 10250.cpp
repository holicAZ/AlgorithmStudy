#include<iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int h, w, n;
		cin >> h >> w >> n;

		int hroom, wroom;
		hroom = n % h;
		wroom = n / h;
		
		if (hroom == 0) {
			cout << h ;
			wroom -= 1;
		}
		else cout << hroom;
		wroom < 9 ? cout << 0 << wroom + 1 : cout << wroom + 1;
		cout << "\n";
	}
	return 0;
}