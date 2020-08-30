#include <iostream>
#include <cstdlib>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, m=0, sum=0;
	int arr[45];
	
	
	for (int a = 1; a <= 45;a++) {
		m += a;
		arr[a - 1] = m;
	}
	
	
	cin >> t;
	int* k = (int *)malloc(t * sizeof(int));
	for (int n = 0; n < t; n++) {
		cin >> k[n];
	}

	for (int n = 0; n < t; n++) {
		bool flag = true;

		for (int i = 0; i < 45; i++) {
			for (int j = 0; j < 45; j++) {
				for (int l = 0; l < 45; l++) {
					sum = arr[i] + arr[j] + arr[l];
					if (sum == k[n]) {
						flag = false;
						break;
					}
				}
				if (flag == false)
					break;
			}
			if (flag == false)
				break;
		}

		if (flag == false)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	
	
}