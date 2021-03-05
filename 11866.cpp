#include<iostream>
#include<queue>
using namespace std;

queue<int>que;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		que.push(i);
	}

	int cnt = 1;
	cout << '<';
	while (!que.empty()) {
		
		if (cnt % k == 0) { // k만큼 반복하면 pop
			cout << que.front();
			que.pop();
			if (!que.empty())
				cout << ',' << " ";
		}
		else { // 걸리지 않으면 다시 que에 넣어준다.
			que.push(que.front());
			que.pop();
		}
		cnt++;
	}
	cout << '>';
	return 0;
}