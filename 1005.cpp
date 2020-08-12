#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
vector<int> graph[1001];
int time[1001], indegree[1001], total[1001];
queue<int> que;
int T, N, K, goal;
void solve() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			que.push(i); // 진입차수가 0이면 삽입
			total[i] = time[i];
		}
	}
	while (!que.empty()) {
		int a = que.front();	
		que.pop();
		if (a == goal) break;
		for (int j = 0; j < graph[a].size(); j++) {
			if (--indegree[graph[a][j]] == 0) 
				que.push(graph[a][j]);

			if (total[graph[a][j]] < total[a] + time[graph[a][j]])
				total[graph[a][j]] = total[a] + time[graph[a][j]];
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		while (!que.empty()) que.pop();
		memset(time, -1, sizeof(time));
		memset(indegree, 0, sizeof(indegree));
		memset(total, 0, sizeof(total));
		for (int i = 1; i <= N; i++) {
			cin >> time[i]; // 소요시간 입력
		}
		for (int i = 0; i < K; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to); // 위상정렬을 위한 방향
			indegree[to]++;
		}
		cin >> goal;
		solve();
		cout <<  total[goal] << "\n";

		for (int i = 0; i < 1001; i++) {
			graph[i].clear();
		}
		
	}
	return 0;
}