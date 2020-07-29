#include<iostream>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> oddIdx; // 홀수 
priority_queue<int,vector<int>,less<int>> evenIdx;   // 짝수: cout
bool flag = false; // false면 짝수 true면 홀수 
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (evenIdx.empty()) {
			evenIdx.push(c);
			cout << c <<"\n";
			continue;
		}
		if (oddIdx.empty()) {
			oddIdx.push(c);
			if (evenIdx.top() <= oddIdx.top()) // top값을 비교해서 짝수인덱스 출력
				cout << evenIdx.top() << "\n";
			else // 짝수 인덱스의 top 값이 더 크면 
			{	 // 홀수 인덱스의 top 값과 교환 후 그 값 출력
				int temp = oddIdx.top();
				oddIdx.pop();
				oddIdx.push(evenIdx.top());
				evenIdx.pop();
				evenIdx.push(temp);
				cout << evenIdx.top()<<"\n";
			}
			continue;
		}
		// 각각 하나 이상씩 들어있을때
		if (!flag) { // 짝수 : 내림차순
			evenIdx.push(c);
			flag = true;	// 다음은 홀수
		}
		else {		// 홀수 : 오름차순
			oddIdx.push(c);
			flag = false;	// 다음은 짝수	
		}
		if (evenIdx.top() <= oddIdx.top()) // top값을 비교해서 짝수인덱스 출력
			cout << evenIdx.top() << "\n";
		else // 짝수 인덱스의 top 값이 더 크면 
		{	 // 홀수 인덱스의 top 값과 교환 후 그 값 출력
			int temp = oddIdx.top();
			oddIdx.pop();
			oddIdx.push(evenIdx.top());
			evenIdx.pop();
			evenIdx.push(temp);
			cout << evenIdx.top() << "\n";
		}
	}
	return 0;
}