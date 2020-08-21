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
	fill(ind, ind + n, 0);  // indegree n까지 0으로 초기화
	int c;
	while (m--) {
		cin >> c;
		for (int i = 0; i < c; i++) { 
			int k; cin >> k;
			x.push_back(k);  // 가수들 순서를 배열에 저장
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
	if (x.size() < n) cout << 0; // n보다 x의 사이즈가 작다는 것은 사이클이 존재한다는 것이다
	else {
		for(int i=0;i<n;i++) {  // n과 size가 같을때 사이클이 없는 위상정렬 된 그래프
			cout << x[i] << "\n";
		}
	}
	return 0;
}