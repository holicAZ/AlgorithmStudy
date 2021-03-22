#include<iostream>
#include<vector>
#define MAX 10001
using namespace std;
int n, m, k;
int dist[MAX] = { 0 };
int ans = 0;
int parent[MAX];

int find(int s) { // UNION-FIND : find() 최고 조상까지 탐색
	if (s == parent[s]) return s; // 조상이 자기자신이면 반환
	return parent[s] = find(parent[s]);
}

void merge(int a, int b) { // 받은 두수의 조상을 탐색
	a = find(a);
	b = find(b);
	if (a == b) return; // 조상이 같다면 같은 집합
	if (dist[a] < dist[b]) parent[b] = a; // 다르면 친구비가 더 큰값의 조상을 작은값으로 바꿈
	// 즉 친구의 친구는 최소 친구비를 가진 친구의 친구비로 통일
	else parent[a] = b;
	return;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> dist[i];
	}
	for (int i = 1; i <= n; i++) parent[i] = i;
	
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		merge(from,to); // 친구의 친구 = 같은 집합
	}
	
	for (int i = 1; i <= n;i++) {
		if (find(0) != find(i)) { // 조상이 0이아니면 실행
			ans += dist[find(i)];
			merge(0, i); // 조상을 0으로 바꿈
		}
	}
	if (ans <= k)
		cout << ans;
	else
		cout << "Oh no";
	return 0;
}