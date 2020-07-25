#include <iostream>
using namespace std;

int n;
int check[1001][1001];	// ��带 ���� �迭
bool is_visit[1001];	// ��� �湮�� üũ�� �迭
int cnt = 0; // ���̷��� �ɸ��� ��ǻ�� ���

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

		check[x][y] = check[y][x] = 1; // ������ �ִٸ� üũ(����� ����)
	}

	DFS(1);
	cout << cnt;
}