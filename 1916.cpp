#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
typedef pair<int, int> pii; // pair <cost, to>
vector<pii> adj[20001];

int n, m, start, fin;
void dik(int s) {
	vector<int> dist(n + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	dist[s] = 0;
	pq.push({ 0,s });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curd = pq.top().first;
		pq.pop();
		for (pii c : adj[cur]) {
			int nxt = c.second;
			int d = c.first+curd;
			if (dist[nxt] > d) {
				dist[nxt] = d;
				pq.push({ d,nxt });
			}
		}
	}
	cout << dist[fin];
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m ;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ cost, to });
	}
	cin >> start >> fin;
	dik(start);
		
	return 0;
}