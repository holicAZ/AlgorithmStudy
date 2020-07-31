#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
int main(void) {
	int n; cin >> n;
	for (int i = 0; i < n;i++) {
		int c;
		cin >> c;
		pq.push(c);
	}
	if (n == 1) { // 카드 묶음이 하나면 비교 x, 0출력
		cout << 0;
		return 0;
	}
	int sum = 0;
	while (true) { 
		int x = pq.top(); 
		pq.pop();
		int y = pq.top();
		pq.pop();
		int z = x + y; // 우선순위 큐에서 top과 그보다 한단계 낮은 값을 더함
		sum += z; // 더했던 값은 계속 갱신해준다.
		if (pq.empty())	// pop을 했을 경우 딱 떨어지면 도중에 멈춘다
			break;
		pq.push(z);	// 떨어지지 않으면 더했던 값을 push해서 개수를 맞춰준다
	}
	cout << sum;
	return 0;
}