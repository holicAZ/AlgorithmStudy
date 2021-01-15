#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	for (auto& a : v)
		cout << a << "\n";
	return 0;
}