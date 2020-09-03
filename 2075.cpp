#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq; // 우선순위 작은수 -> 큰수
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) { // n*n개의 수 입력
		int c;
		cin >> c;
		// pq의 최대크기를 n (메모리 관리)
		if(pq.size()<n) // n보다 size가 작으면 push
			pq.push(c);	// 큐에 넣어 정렬
		else // n 보다 크거나 같으면 기존 것을 pop하고 push
			if (pq.top() < c) { // 입력 값보다 기존 pq의 top값이 작으면 교체
				pq.pop();
				pq.push(c);
			} // 반복문이 종료되면 n개의 수가 오름차순으로 정렬
			  // 따라서 top에 있는 수가 n번째 큰수
	}
	cout << pq.top(); // pop후에 
	return 0;
}
