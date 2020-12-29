#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
queue<pair<pair<pii, pii>,int>> que;
char field[11][11];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;
pii initred, initblue;
pii red, blue, Ared, Ablue;
bool check[11][11][11][11] = {false,};


int solve() {
	que.push({{ initred, initblue }, 0});
	
	check[initred.first][initred.second][initblue.first][initblue.second] = true;
	while (!que.empty()) {
		Ared = que.front().first.first;
		Ablue = que.front().first.second;
		int curcnt = que.front().second;
		que.pop();

		if (field[Ared.first][Ared.second] == 'O') {
			return curcnt;
		}

		for (int i = 0; i < 4; i++) {
			red = Ared; // 네 방향의 기울임 체크
			blue = Ablue;
			int redcnt = 0, bluecnt = 0; // 공이 겹쳤을 경우 확인을 위한 움직임 카운팅

			while (field[red.first + dx[i]][red.second + dy[i]] != '#' &&
				field[red.first][red.second] != 'O') {// red 이동
				red.first += dx[i];
				red.second += dy[i];
				redcnt++;
			}

			while (field[blue.first + dx[i]][blue.second + dy[i]] != '#' &&
				field[blue.first][blue.second] != 'O') {// blue 이동
				blue.first += dx[i];
				blue.second += dy[i];
				bluecnt++;
			}

			if (field[blue.first][blue.second] == 'O') { // 이동을 마쳤는데 블루가 구멍에 빠진경우 체크
				continue;
			}

			if (red.first == blue.first && red.second == blue.second) { 
				// 공이 겹친다 = 더 많이 움직인 공이 한 칸 오버해서 움직인 것
				if (redcnt > bluecnt) { 
					red.first = red.first - dx[i];
					red.second = red.second - dy[i];
				}
				else {
					blue.first = blue.first - dx[i];
					blue.second = blue.second - dy[i];
				}
			}

			// x (redcheck[red.first][red.second] && bluecheck[blue.first][blue.second])
			if 	(check[red.first][red.second][blue.first][blue.second])
				continue;
			// 이동을 마쳤는데 red와 blue의 위치가 방문했던 곳이면 불필요한 이동을 했으므로
			// 카운팅 x

			
			if(curcnt<10){
				check[red.first][red.second][blue.first][blue.second] = true;
				que.push({ { red, blue }, curcnt+1 });
				
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> field[i][k];
			
			if (field[i][k] == 'R') {
				initred = pii({ i, k });
			}

			if (field[i][k] == 'B') {
				initblue = pii({ i, k });
			}
		}
	}
	
	cout << solve();
	return 0 ;
}