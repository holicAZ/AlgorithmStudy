#include<iostream>
#include<queue>
using namespace std;

queue<int> que;
int main(void) {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		que.push(i);
	}

	while (que.size() != 1) {
		que.pop();
		int n = que.front();
		que.pop();
		que.push(n);
	}
	cout << que.front();
	return 0;
}