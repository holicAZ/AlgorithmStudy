#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<memory.h>
#define N 100001
using namespace std;

int dfsn[N], cnt, sn[N], scctotal, indegree[N]; // scctotal : scc�� �� ����, sn: index�� ���� scc�� ��ȣ�� ����
bool notscc[N]; // scc�� ������ ���� �Ǻ��ϴ� ����
vector<int> graph[N];
stack<int> s;

int dfs(int cur) {
	dfsn[cur] = ++cnt;  // dfsn�� ������ ��ȣ�� �ű�� ����
	s.push(cur);		// ���ÿ� �ϳ��� ����

	int ret = dfsn[cur]; // �ڽŰ� �ڽ��� dfsn�� ���ؼ� ���� ���� ����
						 // �� ����Ŭ �߻��� ������ ���� ret�� ����
	for (int i = 0; i < graph[cur].size();i++) {
		int n = graph[cur][i];
		if (dfsn[n]==0) // ���� �湮 x
			ret = min(ret, dfs(n));
		else if (!notscc[n]) // �湮�� ������ scc�� ���� x
			ret = min(ret, dfsn[n]);
	}

	if (ret == dfsn[cur]) { // ����Ŭ�� �߻��Ͽ� scc�� ������ ���
		
		while (true) {
			int x = s.top();
			s.pop();
			notscc[x] = true;	  // scc�� ���� ���� ǥ��
			sn[x] = scctotal+1;
			// �ڱ��ڽ��� ������ ������ ���� �������� �ϳ��� scc�� ����
			if (x == cur) // ���ÿ��� �ڱ��ڽ� cur�� ���ö����� pop���ش�
				break;
		}
		scctotal++; // �� scc ���� ++
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for(int i = 0; i < N; i++) {
			graph[i].clear();
		}
		memset(sn, 0, sizeof(sn));
		memset(dfsn, 0, sizeof(dfsn));
		memset(notscc, false, sizeof(notscc));
		cnt = 0, scctotal =0;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
		}

		for (int i = 1; i <= n; i++) { // scc�� Ȯ���Ѵ�
			if (dfsn[i] == 0)
				dfs(i);
		}
		memset(indegree, 0, sizeof(indegree));

		for (int i = 1; i <= n; i++) {
			for (int j : graph[i]) {
				if (sn[i] != sn[j]) // ���� scc�� �������� �ʴ� ���
					indegree[sn[j]]++; // ���������� + ���ش�
			}
		}

		int start = 0;
		for (int i = 0; i < scctotal; i++) {
			if (indegree[i] == 0) // ���������� 0�ΰ�츦 ī�������ش�
				start++;
		}

		cout << start << "\n";
	}
	return 0;
}