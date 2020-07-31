#include<iostream>
#include<vector>

using namespace std;
vector<int> v;
typedef long long int llt;

llt GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}
int main(void) {
	int t, n ,c;
	cin >> t;
	

	while (t--) {
		cin >> n;
		llt sum = 0;
		for (int k = 0; k < n; k++) {
			cin >> c;
			v.push_back(c);
		}
		for (int i = 0; i < n-1;i++) {
			for (int j = i+1; j < n; j++) {
				sum += GCD(v[i], v[j]);
			}
		}
		cout << sum << "\n";
		v.clear();
	}
}