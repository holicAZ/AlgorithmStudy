#include<iostream>
#include<queue>
using namespace std;

queue <pair<int, int>> que;
int n, m,a,b;
int cnt = 0;
char field[101][101];	
int visit[101][101];	// �湮�� ���Ҿ� ���° �̵����� Ȯ���ϴ� �迭

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int x = 0; x < n; x++) {
		cin >> field[x];	// char ������ ����
	}
	visit[0][0] = 1;	// ó�� ��ġ =1 
	que.push(make_pair(0, 0)); // ť ������ �ʱ�ȭ
	while (!que.empty()) {
		
		int x = que.front().first;
		int y = que.front().second;
		if (x == n - 1 && y == m - 1) {
			cout << visit[x][y];	// �������� �����ϸ� visit�� ��ȯ
			break;
		}
		que.pop();
		
		for (int i = 0; i < 4; i++) {	// ��ġ �̵�
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;

			if (visit[nx][ny]!=0) continue;	// �̵��� ��ġ�� ���� �湮���� �ʾ��� ���� �̵�

			if (field[nx][ny] != '1') continue;

			que.push(make_pair(nx, ny));
			visit[nx][ny] += visit[x][y]+1;	// ���� ��ġ�� ������ġ���� +1��ŭ �̵��� ��ġ
			
		}
	}
}