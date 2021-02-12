#include<iostream>
#include<queue>

using namespace std;
typedef pair<pair<int, int>,int> pii;

queue <pii> que;
int field[1000][1000];
int n, m, ans;

void bfs() {
	while (!que.empty()) {
		pii point = que.front();
		que.pop();
		int row = point.first.first;
		int col = point.first.second;
		int cnt = point.second; // 탐색 횟수

		if (row - 1 >= 0 && field[row - 1][col] == 0) { // 위로 이동
			field[row - 1][col] = 1;
			que.push({ {row - 1,col},cnt+1 });
		}
		if (row + 1 < n && field[row + 1][col] == 0) { // 아래로 이동
			field[row + 1][col] = 1;
			que.push({ {row + 1, col},cnt+1 });
		}
		if (col - 1 >= 0 && field[row][col - 1] == 0) { // 왼쪽으로 이동
			field[row][col - 1] = 1;
			que.push({{row, col - 1},cnt+1});
		}
		if (col + 1 < m && field[row][col + 1] == 0) { // 오른쪽으로 이동
			field[row][col + 1] = 1;
			que.push({ {row, col + 1},cnt+1 });
		}
		
		ans = cnt;
	}

}

bool check() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (field[i][k] == 0)
				return false;
		}
	}
	return true;
}

int main(void) {
	
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> field[i][k];
			if (field[i][k] == 1) {
				que.push({ { i,k }, 0 });
			}
		}
	}

	bfs();
	if (check()) {
		cout << ans;
	}
	else cout << -1;
	
	return 0;
}