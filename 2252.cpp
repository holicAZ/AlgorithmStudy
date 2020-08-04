#include<iostream>
#include <algorithm>
#include <queue>

using namespace std;

int indegree[32001];
vector<int> v[32001];
queue<int> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		indegree[b]++;
		v[a].push_back(b);
	}
	
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) ans.push(i);

	while (!ans.empty()) {
		int i = ans.front(); 
		ans.pop();
		cout << i << " ";
		for (int j = 0; j < v[i].size(); j++)
			if (--indegree[v[i][j]] == 0)
				ans.push(v[i][j]);
	}
}