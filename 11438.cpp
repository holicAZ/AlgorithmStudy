#include<iostream>
#include <vector>
#define N 100001
using namespace std;
vector<int> graph[N];
int n, m, depth[N], parent[N][21];

void init_depth(int node, int par) { // 노드의 레벨과 조상을 정한다
	depth[node] = depth[par] + 1; // node : 현재, par : 바로 위 조상
	parent[node][0] = par; // 조상을 저장
	
	for (int a : graph[node]) {
		if(a != par) 
		init_depth(a, node);
	}
}
int LCA(int a, int b) { // 최소 공통 조상을 찾는 함수
	if (depth[a] != depth[b]) { // 레벨이 같지 않으면 레벨을 맞춰준다
		if (depth[a] > depth[b]) swap(a, b); // 레벨 b>a 라 가정, 아닐시 swap
		for (int i = 20; i >= 0; i--) { // 레벨이 같아질때까지 반복
			if (depth[a] <= depth[parent[b][i]]) b = parent[b][i];
		}
	}
	
	int lca = a; 

	if (a != b) { // 레벨은 같은데 값이 같지 않을 경우 더 상위 조상을 찾아 비교한다
		for (int i = 20; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i]; // 조상의 조상을 비교
				b = parent[b][i];
			}
			lca = parent[a][i]; // 마지막 값이 공통 조상의 값
		}	
	}
	return lca;
}

void LCA_2() { // 2^n의 조상을 parent 배열에 저장한다 (시간의 효율성)
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}   
	}
}
void init_graph() { // 그래프를 만든다
	int n1, n2;
	depth[0] = -1; 
	for (int i = 1; i < n; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	init_depth(1, 0); // 1번의 깊이를 0
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	init_graph();
	LCA_2();
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << LCA(x, y) << "\n";
	}
	return 0;
}