#include<iostream>
#include<vector>
using namespace std;
int n,m;
int parent[201];
int x[1001];

void init() {
	for (int i = 1; i <= n; i++) parent[i] = i;
}
int find(int x) {
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	parent[b] = a;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	init();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int c; cin >> c;
			if (c == 1) {
				Union(i, j);
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> x[i];
	}
	
	for (int i = 1; i <= m-1; i++) {
		if (find(x[i + 1]) != find(x[i])) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}