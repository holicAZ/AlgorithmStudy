#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

queue <int> que;
int n;
int check[1001][1001];	// 노드를 담을 배열
bool is_visit[1001];	// 노드 방문을 체크할 배열

void DFS(int start) {

	is_visit[start] = 1;
	cout << start  << " ";

	for (int y = 1; y <= n; y++) {
		if (check[start][y] == 1 && !is_visit[y]) {
			DFS(y);
		}
				
	}
	
}

void BFS(int start) {
	que.push(start);
	is_visit[start] = 1;

	while (!que.empty()) {	// 큐가 empty가 아닐 동안 반복
		
		for (int y = 1; y <= n; y++) {

			if (check[que.front()][y] == 1 && !is_visit[y]) {
				que.push(y);
				is_visit[y] = 1;
			}

		}
		cout << que.front() << " ";
		que.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m, start;
	cin >> n >> m >> start;

	

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		check[x][y] = check[y][x] = 1; // 간선이 있다면 체크(양방향 간선)
	}

	DFS(start);
	memset(is_visit, 0, sizeof(is_visit));	// 방문 체크 배열 초기화
	cout << "\n";
	BFS(start);
}