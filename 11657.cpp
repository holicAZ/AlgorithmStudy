#include <iostream>
#include <vector>
#define N 501
#define INF 99999999
using namespace std;
int n, m;
typedef pair<int, int> pii; // ���� ���, ����ġ
vector<pii> graph[N]; // ���۳��, �������, ����ġ ���� ����
long long dist[N]; // �ּҰŸ� ����

bool B_F() {
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;
	bool flag = false; // ���� ����Ŭ �������� Ȯ�κ���
	int loop = 1;

	while (loop <= n) { // �ִܰŸ��� n-1���� �ݺ�, n��° �ݺ��ؼ� ���ŵ� ��� = ���� ����Ŭ �߻�
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INF) continue; // ��ΰ� ���� ���� �Ѿ
			for (pii x : graph[i]) {
				if (dist[x.first] > dist[i] + x.second) { // �ִܰŸ� ��
					if (loop == n) { // n��° �ݺ��� ��� break
						flag = true;
						break;
					}
					dist[x.first] = dist[i] + x.second; // �ִܰŸ� ����
				}
			}
		}
		loop++;
	}
	return flag;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(pii(b,c)); 
	}
	bool cycle = B_F();
	
	if (cycle) {
		cout << -1;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF)  cout << -1 << "\n";
		else cout << dist[i] << "\n";
	}
	
	return 0;
}