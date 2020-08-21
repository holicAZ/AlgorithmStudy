#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
vector<int> v[1001];
vector<int> x;
int ind[1001];
queue<int> que;

int main(void) {
	cin >> n >> m;
	fill(ind, ind + n, 0);  // indegree n���� 0���� �ʱ�ȭ
	int c;
	while (m--) {
		cin >> c;
		for (int i = 0; i < c; i++) { 
			int k; cin >> k;
			x.push_back(k);  // ������ ������ �迭�� ����
		}
		for (int i = 1; i < c; i++) {
			v[x[i - 1]].push_back(x[i]); 
			ind[x[i]]++;
		}
		x.clear();
	}

	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) que.push(i);
	}

	while (!que.empty()) {
		int i = que.front();
		que.pop();
		x.push_back(i);
		for (int j = 0; j < v[i].size(); j++)
			if (--ind[v[i][j]] == 0)
				que.push(v[i][j]);
	}
	if (x.size() < n) cout << 0; // n���� x�� ����� �۴ٴ� ���� ����Ŭ�� �����Ѵٴ� ���̴�
	else {
		for(int i=0;i<n;i++) {  // n�� size�� ������ ����Ŭ�� ���� �������� �� �׷���
			cout << x[i] << "\n";
		}
	}
	return 0;
}