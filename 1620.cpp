#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

string vec[100001];
map<string, int> MAP;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		MAP[s] = i;
		vec[i] = s;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s.at(0) >= '0' && s.at(0) <= '9') {
			cout << vec[stoi(s)] << "\n";
		}
		else {
			cout << MAP[s] << "\n";
		}
	}
	return 0;
}