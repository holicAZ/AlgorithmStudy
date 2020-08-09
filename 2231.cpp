#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, min=0;
	int sum = 0, cnt = 0;
	bool flag = true;
	cin >> n;
	m = n;

	while (m!=0) {
		m /= 10;
		cnt++;
	}
	m = n - (9 * cnt);


	for (int i = m; i < n; i++) {
		sum += i;
		int s = i;		
		while (s > 0) {
			sum += (s % 10);			
			s /= 10;			
		}
		if (sum == n) {
			min = i;
			flag = false;
		}
		sum = 0;	

		if (flag == false)
			break;
	}
	cout << min;
	
}