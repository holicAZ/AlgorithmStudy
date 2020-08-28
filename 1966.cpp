#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
using namespace std;

queue<pii> q;
vector<int> v;
int main(void) {
	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			int w;
			cin >> w;
			q.push({ i,w });
			v.push_back(w);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		
		int idx = 0;
		int cnt = 1;

		for (int i = 0;; i++) {
			int currW = q.front().second;
			int currN = q.front().first;
			q.pop();
			
			if (v[idx] == currW) {
				if (m == currN) {
					cout << cnt << "\n";
					break;
				}
				idx++;
				cnt++;
				continue;
			}
			else {
				q.push({ currN, currW });
				continue;
			}
		}
		while (!q.empty()) q.pop();
		v.clear();
	}
	return 0;
}