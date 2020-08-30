#include<iostream>
#include<queue>

using namespace std;
priority_queue<int, vector<int>, greater<int> > great;	// greater 오름차순, 낮은 값이 top
priority_queue<int, vector<int>,less<int> > les;	// 아무것도 없으면 less 내림차순, 높은 값이 top

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n--) {
		int c; cin >> c;
		if (c == 0) { 
			// 양수면 작을수록 절댓값이 작고
			// 음수면 클수록 절댓값이 작다.
			if (great.empty() && les.empty()) { cout << 0 << "\n"; continue; }
			if (les.empty()) { // 음수 큐가 비어있을 경우
				cout << great.top() << "\n";
				great.pop();
				continue;
			}
			if (great.empty()) { // 양수 큐가 비어있을 경우
				cout << les.top() << "\n";
				les.pop();
				continue;
			}
			if (great.top() < abs(les.top())) {
				cout << great.top() << "\n";
				great.pop();
				continue;
			}
			if(great.top() >= abs(les.top())){
				cout << les.top() << "\n";
				les.pop();
				continue;
			}
		}
		if (c < 0) les.push(c); // 음수이면 내림차순 저장
		else great.push(c); // 양수이면 오름차순 저장
	}
	return 0;
}
