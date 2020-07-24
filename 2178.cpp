#include<iostream>
#include<queue>
using namespace std;

queue <pair<int, int>> que;
int n, m,a,b;
int cnt = 0;
char field[101][101];	
int visit[101][101];	// 방문과 더불어 몇번째 이동인지 확인하는 배열

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int x = 0; x < n; x++) {
		cin >> field[x];	// char 형으로 받음
	}
	visit[0][0] = 1;	// 처음 위치 =1 
	que.push(make_pair(0, 0)); // 큐 시작점 초기화
	while (!que.empty()) {
		
		int x = que.front().first;
		int y = que.front().second;
		if (x == n - 1 && y == m - 1) {
			cout << visit[x][y];	// 마지막에 도달하면 visit값 반환
			break;
		}
		que.pop();
		
		for (int i = 0; i < 4; i++) {	// 위치 이동
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;

			if (visit[nx][ny]!=0) continue;	// 이동할 위치가 아직 방문하지 않았을 때만 이동

			if (field[nx][ny] != '1') continue;

			que.push(make_pair(nx, ny));
			visit[nx][ny] += visit[x][y]+1;	// 다음 위치는 이전위치에서 +1만큼 이동한 위치
			
		}
	}
}