#include<iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;

		int res = a % 10;	// 일의 자리 수만 확인하면 된다.
		int cycle = b % 4;	// 보통 네 번이면 일의 자리 숫자 순환

		if(cycle==0) cycle = 4;
		
		for (int i = 1; i < cycle; i++) {
			res *= a;
			res %= 10;
		}

		res == 0 ? cout << 10 << "\n" : cout << res << "\n";
	}
	return 0;
}