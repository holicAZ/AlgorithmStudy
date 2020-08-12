#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>* edge;		// 이차원 벡터 선행문제 저장
vector<int> inDegree;	// 진입차수 확인
priority_queue<int, vector<int>, greater<int>> result; // 결과 값 저장
int n, m;

void init() { // 초기화 함수
	edge = new vector<int>[n+1];	// 선행문제 저장배열 초기화
	inDegree.resize(n + 1);			// 진입차수 배열 resize
	fill(inDegree.begin(), inDegree.end(), 0);	// 주어진 문제 수 n만큼 0으로 채운다
}
void input(int a, int b) {	// 선행 문제 입력
	edge[a].push_back(b);
	inDegree[b]++;		// 진입차수+1
}
void print() { // 문제 푸는 순서 출력
	while(n--) {	// 총 문제 수만큼 반복
		int x = result.top(); // 우선순위 큐의 top값 저장
		result.pop();
		cout << x << " "; // top을 출력
		for (int j = 0; j < edge[x].size(); j++) { // top의 후행문제 확인해서 inDegree 업데이트
			int y = edge[x][j];
			inDegree[y]--;
			if (!inDegree[y]) result.push(y); // 업데이트 된 진입차수가 0이면 우선순위 큐에 저장
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	init(); // 문제 수 만큼 초기화
	
	while (m--) {
		int a, b;
		cin >> a >> b;
		input(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) result.push(i); // 진입차수가 0이면 노드를 우선순위 큐에 삽입
	}
	print();
	
	return 0;
}