#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;

bool comp(const string& a, const string& b) {  // 길이가 같으면 사전순, 다르면 짧은 것 우선
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main(void) {
	int N;
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), comp);
	v.erase(unique(v.begin(), v.end()), v.end()); // 중복 값을 제거해준다.

	for (string ans : v)
		cout << ans << "\n";

	return 0;
}