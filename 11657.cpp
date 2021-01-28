#include <iostream>
#include <vector>
#define N 501
#define INF 99999999
using namespace std;
int n, m;
typedef pair<int, int> pii; // 도착 노드, 가중치
vector<pii> graph[N]; // 시작노드, 도착노드, 가중치 저장 벡터
long long dist[N]; // 최소거리 저장

bool B_F() {
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;
	bool flag = false; // 음의 사이클 생성여부 확인변수
	int loop = 1;

	while (loop <= n) { // 최단거리는 n-1까지 반복, n번째 반복해서 갱신될 경우 = 음싀 사이클 발생
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INF) continue; // 경로가 없는 곳은 넘어감
			for (pii x : graph[i]) {
				if (dist[x.first] > dist[i] + x.second) { // 최단거리 비교
					if (loop == n) { // n번째 반복인 경우 break
						flag = true;
						break;
					}
					dist[x.first] = dist[i] + x.second; // 최단거리 갱신
				}
			}
		}
		loop++;
	}
	return flag;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(pii(b,c)); 
	}
	bool cycle = B_F();
	
	if (cycle) {
		cout << -1;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF)  cout << -1 << "\n";
		else cout << dist[i] << "\n";
	}
	
	return 0;
}