#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int arr[1001][1001];
bool check[1001];
int cnt = 0;

void DFS(int start) {
	if (check[start]) {
		return;
	}
	
	check[start] = true;

	for (int i = 1; i <= n; i++) {
		if (arr[start][i] && !check[i]) {
			DFS(i);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	memset(check, false, sizeof(check));
	memset(arr, 0, sizeof(arr));
	cin >> n >>m;

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			cnt++;
			DFS(i);
		}
		
	}
	
	cout << cnt;
}