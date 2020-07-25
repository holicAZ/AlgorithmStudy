#include <iostream>
using namespace std;

int n;
int check[1001][1001];	// 노드를 담을 배열
bool is_visit[1001];	// 노드 방문을 체크할 배열
int cnt = 0; // 바이러스 걸리는 컴퓨터 대수

void DFS(int start) {

	is_visit[start] = 1;

	for (int y = 1; y <= n; y++) {
		if (check[start][y] == 1 && !is_visit[y]) {
			DFS(y);
			cnt++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		check[x][y] = check[y][x] = 1; // 간선이 있다면 체크(양방향 간선)
	}

	DFS(1);
	cout << cnt;
}