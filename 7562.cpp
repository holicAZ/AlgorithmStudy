#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n, m, z, c, a, b;
int field[301][301];


int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;	// tastcase ��
	
	for (int tast = 0; tast < n; tast++) {
		
		memset(field, 0, sizeof(field));
		queue <pair<int,pair<int, int>>> que;
				
		cin >> m;	// ü���� ũ�� m*m
		
		cin >> z >> c;	// ���� ��ġ
		cin >> a >> b;	// ���� ��ġ
		
		que.push(make_pair(0,make_pair(z, c))); // que �ʱ�ȭ 
		field[z][c]++;	// ó�� ��ġ �湮 ǥ��
		

		while (!que.empty())
		{	
			int x = que.front().second.first;
			int y = que.front().second.second;
			int cnt = que.front().first;
			que.pop();	
			
			if (x == a && y == b) {
				cout << cnt <<"\n";
				break;
			}
			
			for (int i = 0; i < 8; i++) {
				int x1 = x + dx[i];
				int y1 = y + dy[i];

				if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= m)	// m*m���� ũ�� X
					continue;

				if (field[x1][y1])	// �̹� �湮�� �ʵ�� �ѱ��
					continue;
				
				field[x1][y1] ++;
				que.push(make_pair(cnt+1,make_pair(x1, y1)));
			}
		}
		
	}

	return 0;
}