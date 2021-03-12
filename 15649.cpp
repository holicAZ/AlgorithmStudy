#include<iostream>
using namespace std;

int n, m;
bool visited[9];
int adj[9];
void dfs(int s) {
	if (s == m) {
		for (int i = 0; i < m; i++) {
			cout << adj[i] << " ";
		}
			cout << "\n";
			return;
		
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			adj[s] = i;
			dfs(s + 1);
			visited[i] = 0;
		}
	}
}
int main(void) {
	cin >> n >> m;
	dfs(0);
	return 0;
}