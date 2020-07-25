#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	int arr[100];
	int strike[100];
	int ball[100];
	int answer = 0;
	

	for (int i = 0; i < n; i++) 	
		cin >> arr[i] >> strike[i] >> ball[i];
	
	for (int x = 123; x <= 987; x++) {
		int x100 = x / 100;
		int x10 = (x - (x100 * 100))/10;
		int x1 = x % 10;

		int cnt = 0;
		
		if (x100 == x10 || x100 == x1 || x10 == x1)
			continue;

		if (x10 == 0 || x1 == 0)
			continue;

		for (int i = 0; i < 100; i++) {
			int str = 0, b = 0;
			cnt++;
			
			int y100 = arr[i] / 100;
			int y10 = (arr[i] - (y100 * 100)) / 10;
			int y1 = arr[i] % 10;

			if (y1 == x1)
				str++;
			if (y10 == x10)
				str++;
			if (y100 == x100)
				str++;

			if (y10 == x1 || y100 == x1)
				b++;
			if (y1 == x10 || y100 == x10)
				b++;
			if (y1 == x100 || y10 == x100)
				b++;

			if (strike[i] == str && ball[i] == b) {
				if (cnt == n)
					answer++;
				else
					continue;
			}
			else 
				break;
		}
		
	}
	cout << answer;
}