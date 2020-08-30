#include<iostream>
#include<queue>

using namespace std;
priority_queue<int, vector<int>, less<int>> ls;	// less�� ��������, ���� ���� top

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n--) {
		int c; cin >> c;
		if (c == 0) {
			if (ls.empty()) { cout << 0 << "\n"; continue; }
			cout << ls.top() << "\n";
			ls.pop(); continue;
		}
		ls.push(c);
	}
	return 0;
}
