#include<iostream>
#include<queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> great;	// greater ��������, ���� ���� top

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n--) {
		int c; cin >> c;
		if (c == 0) {
			if (great.empty()) { cout << 0 << "\n"; continue; }
			cout << great.top() << "\n"; 
			great.pop(); continue;
		}
		great.push(c);
	}
	return 0;
}
