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
	vector<int> dist(v+1, INF); // 0�� ���� �ִ�� v������ ��� ����
	priority_queue<pii, vector<pii>, greater<pii> > pq; // to �� cost�� ���� �ּҰ��� ������ ����
	pq.push(pii(0,start)); // ���������� cost�� 0���� �Է�
	dist[start] = 0;

	while (!pq.empty()) { 
		int cur = pq.top().second, co = pq.top().first ; // ���� ������ cost����
		pq.pop(); 
		
		for (pii c : graph[cur]) { // �׷����� {����, �ڽ�Ʈ}
			int nxt = c.second; // cur�� ������ ����Ȯ��
			int d = c.first + co; // ���� ���������� cost�� nxt ���������� cost�� �����ش�
			if (dist[nxt] > d) { // ����Ǿ� �ִ� cost ���� ũ�� ������Ʈ
				dist[nxt] = d;
				pq.push({ d,nxt }); // ������ Ž���� ���� pq�� push
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
		graph[from].push_back(pii(cost,to)); // �׷��� ����
	}
	solve();
	return 0;
	// ����ġ�� �ִ� �׷������� �ִܰ�θ� ã������ first�� cost�� ���
}