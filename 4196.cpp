#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<memory.h>
#define N 100001
using namespace std;

int dfsn[N], cnt, sn[N], scctotal, indegree[N]; // scctotal : scc의 총 개수, sn: index가 속한 scc의 번호를 저장
bool notscc[N]; // scc가 형성된 정점 판별하는 역할
vector<int> graph[N];
stack<int> s;

int dfs(int cur) {
	dfsn[cur] = ++cnt;  // dfsn은 정점의 번호를 매기는 역할
	s.push(cur);		// 스택에 하나씩 저장

	int ret = dfsn[cur]; // 자신과 자식의 dfsn을 비교해서 작은 값을 저장
						 // 즉 사이클 발생시 최초의 값을 ret에 저장
	for (int i = 0; i < graph[cur].size();i++) {
		int n = graph[cur][i];
		if (dfsn[n]==0) // 아직 방문 x
			ret = min(ret, dfs(n));
		else if (!notscc[n]) // 방문은 했으나 scc에 포함 x
			ret = min(ret, dfsn[n]);
	}

	if (ret == dfsn[cur]) { // 사이클이 발생하여 scc가 형성된 경우
		
		while (true) {
			int x = s.top();
			s.pop();
			notscc[x] = true;	  // scc에 사용된 정점 표시
			sn[x] = scctotal+1;
			// 자기자신이 나오기 전까지 나온 정점들은 하나의 scc를 형성
			if (x == cur) // 스택에서 자기자신 cur이 나올때까지 pop해준다
				break;
		}
		scctotal++; // 총 scc 개수 ++
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for(int i = 0; i < N; i++) {
			graph[i].clear();
		}
		memset(sn, 0, sizeof(sn));
		memset(dfsn, 0, sizeof(dfsn));
		memset(notscc, false, sizeof(notscc));
		cnt = 0, scctotal =0;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
		}

		for (int i = 1; i <= n; i++) { // scc를 확인한다
			if (dfsn[i] == 0)
				dfs(i);
		}
		memset(indegree, 0, sizeof(indegree));

		for (int i = 1; i <= n; i++) {
			for (int j : graph[i]) {
				if (sn[i] != sn[j]) // 같은 scc에 속해있지 않는 경우
					indegree[sn[j]]++; // 진입차수를 + 해준다
			}
		}

		int start = 0;
		for (int i = 0; i < scctotal; i++) {
			if (indegree[i] == 0) // 진입차수가 0인경우를 카운팅해준다
				start++;
		}

		cout << start << "\n";
	}
	return 0;
}