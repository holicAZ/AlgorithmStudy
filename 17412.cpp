#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 999999999
using namespace std;

int capacity[401][401]; // 간선의 용량
int flow[401][401]; // 현재 흐르는 유량
vector<int> graph[401]; // 인접리스트
int n, p, cnt=0;
int source = 1, sink = 2;

int main(void) {
	cin >> n >> p;
	for (int i = 0; i < p; i++) {
		int from, to;
		cin >> from >> to;
		capacity[from][to] = 1;
		capacity[to][from] = 0;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	
	while (1) {
		int pre[401];
		fill(pre, pre + 401, -1);
		queue<int> q;
		q.push(source);
		while (!q.empty() && pre[sink] == -1) {
			int now = q.front();
			q.pop();
			for (int nxt : graph[now]) {
				if (capacity[now][nxt] > flow[now][nxt] && pre[nxt] == -1) {
					pre[nxt] = now;
					q.push(nxt);
					if (nxt == sink) {
						break;
					}
				}
			}
		}
		if (pre[sink] == -1)break;

		int f = INF;
		for (int i = sink; i != source; i = pre[i]) 
			f = min(f, capacity[pre[i]][i] - flow[pre[i]][i]);
		for (int i = sink; i != source; i = pre[i]) {
			flow[pre[i]][i] += f;
			flow[i][pre[i]] -= f;
		}

		cnt += f;
	}
	
	cout << cnt;
	return 0;
}