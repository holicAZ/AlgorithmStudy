#include<iostream>
#include<vector>
#define MAX 10001
using namespace std;
int n, m, k;
int dist[MAX] = { 0 };
int ans = 0;
int parent[MAX];

int find(int s) { // UNION-FIND : find() �ְ� ������� Ž��
	if (s == parent[s]) return s; // ������ �ڱ��ڽ��̸� ��ȯ
	return parent[s] = find(parent[s]);
}

void merge(int a, int b) { // ���� �μ��� ������ Ž��
	a = find(a);
	b = find(b);
	if (a == b) return; // ������ ���ٸ� ���� ����
	if (dist[a] < dist[b]) parent[b] = a; // �ٸ��� ģ���� �� ū���� ������ ���������� �ٲ�
	// �� ģ���� ģ���� �ּ� ģ���� ���� ģ���� ģ����� ����
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
		merge(from,to); // ģ���� ģ�� = ���� ����
	}
	
	for (int i = 1; i <= n;i++) {
		if (find(0) != find(i)) { // ������ 0�̾ƴϸ� ����
			ans += dist[find(i)];
			merge(0, i); // ������ 0���� �ٲ�
		}
	}
	if (ans <= k)
		cout << ans;
	else
		cout << "Oh no";
	return 0;
}