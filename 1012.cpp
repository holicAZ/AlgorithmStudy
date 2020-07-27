#include <iostream>
#include <cstring>
using namespace std;

int field[50][50];
int cnt = 0;
int t, m, n, k;


void leftright(int x, int y) {
	
	if (x < n - 1 && field[x + 1][y]) { //  아래쪽 탐색			 
		field[x][y] = 0;
		leftright(x + 1, y);
	}
	if (x - 1 >= 0 && field[x - 1][y]) { //  위쪽 탐색
		field[x][y] = 0;
		leftright(x - 1, y);
	}

	if (y < m-1 && field[x][y + 1] ) {	// 우측 탐색	 
		field[x][y] = 0;
		leftright(x, y + 1);
	}
	if (y-1 >= 0 && field[x][y - 1]) { //  좌측 탐색		 
		field[x][y] = 0;
		leftright(x, y - 1);
	}
	else {
		field[x][y] = 0;
		return ;
	}
}

void larva() {
	cnt = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (field[x][y]) { // 배추가 심어져있으면 실행
				cnt++;
				leftright(x,y);
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b;
	cin >> t;

	for (int i = 0; i < t; i++) {
		
		cin >> m >> n >> k;
		
		memset(field, 0, sizeof(field));

		for (int spot = 0; spot < k; spot++) {	// 배추가 심어진 좌표 true로 설정
			cin >> a >> b;
			field[b][a] = 1;
		}
		
		larva();
		cout << cnt <<"\n";
	}
	return 0;
}