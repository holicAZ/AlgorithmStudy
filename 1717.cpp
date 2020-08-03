#include<iostream>
using namespace std;
int n,m;
int parent[1000001];
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
	for (int i = 0; i < m; i++) {
		int op,a,b;
		cin >> op >> a >> b;
		if (op) cout << (find(a) == find(b) ? "YES\n" : "NO\n");
		else Union(a, b);
	}
	return 0;
}