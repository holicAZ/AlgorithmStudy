#include<iostream>
#include <vector>
#define N 100001
using namespace std;
vector<int> graph[N];
int n, m, depth[N], parent[N][21];

void init_depth(int node, int par) { // ����� ������ ������ ���Ѵ�
	depth[node] = depth[par] + 1; // node : ����, par : �ٷ� �� ����
	parent[node][0] = par; // ������ ����
	
	for (int a : graph[node]) {
		if(a != par) 
		init_depth(a, node);
	}
}
int LCA(int a, int b) { // �ּ� ���� ������ ã�� �Լ�
	if (depth[a] != depth[b]) { // ������ ���� ������ ������ �����ش�
		if (depth[a] > depth[b]) swap(a, b); // ���� b>a �� ����, �ƴҽ� swap
		for (int i = 20; i >= 0; i--) { // ������ ������������ �ݺ�
			if (depth[a] <= depth[parent[b][i]]) b = parent[b][i];
		}
	}
	
	int lca = a; 

	if (a != b) { // ������ ������ ���� ���� ���� ��� �� ���� ������ ã�� ���Ѵ�
		for (int i = 20; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i]; // ������ ������ ��
				b = parent[b][i];
			}
			lca = parent[a][i]; // ������ ���� ���� ������ ��
		}	
	}
	return lca;
}

void LCA_2() { // 2^n�� ������ parent �迭�� �����Ѵ� (�ð��� ȿ����)
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}   
	}
}
void init_graph() { // �׷����� �����
	int n1, n2;
	depth[0] = -1; 
	for (int i = 1; i < n; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	init_depth(1, 0); // 1���� ���̸� 0
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