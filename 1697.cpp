#include<iostream>
#include<queue>
using namespace std;

queue<int> que;
int field[100002] = {0, };
int n, k, time=0;

void bfs() {
	for (int i = 0; i < que.size(); i++) {
		int dx = que.front();
		que.pop();
		
		if (dx == k) {
			while (!que.empty()) que.pop(); // que clear
			break; // if find end.

		}
		// 방문하지 않았으면
		if (dx - 1 >= 0 && !field[dx - 1]) { // -1 
			que.push(dx - 1);
			field[dx - 1] = field[dx] + 1;
		}
		if (dx + 1 <= 100002 && !field[dx + 1]) { // +1 
			que.push(dx + 1);
			field[dx + 1] = field[dx] + 1;
		}
		if (dx * 2 <= 100002 && !field[dx * 2]) { // x2 
			que.push(dx * 2);
			field[dx * 2] = field[dx] + 1;
		}
	}
	time++;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	que.push(n);
	field[n] = 0;
	while (!que.empty()) {
		bfs();
	}
	cout << field[k];
}