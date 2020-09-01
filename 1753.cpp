#include<iostream>
#include<vector>
#include<queue>
#define  N 20001
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
vector<pii> graph[N];
int v, e, start;

void solve() {
	vector<int> dist(v+1, INF); // 0은 없고 최대는 v번까지 경로 저장
	priority_queue<pii, vector<pii>, greater<pii> > pq; // to 와 cost를 저장 최소값을 가리기 위해
	pq.push(pii(0,start)); // 시작지점의 cost는 0으로 입력
	dist[start] = 0;

	while (!pq.empty()) { 
		int cur = pq.top().second, co = pq.top().first ; // 현재 정점과 cost저장
		pq.pop(); 
		
		for (pii c : graph[cur]) { // 그래프의 {정점, 코스트}
			int nxt = c.second; // cur과 인접한 정점확인
			int d = c.first + co; // 현재 정점까지의 cost와 nxt 정점까지의 cost를 더해준다
			if (dist[nxt] > d) { // 저장되어 있는 cost 보다 크면 업데이트
				dist[nxt] = d;
				pq.push({ d,nxt }); // 나머지 탐색을 위해 pq에 push
			}
		}
	}
	
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) {
			cout << "INF" << "\n";
		}
		else cout << dist[i] << "\n";
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> v >> e >> start;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back(pii(cost,to)); // 그래프 생성
	}
	solve();
	return 0;
	// 가중치가 있는 그래프에서 최단경로를 찾으려면 first에 cost를 사용
}