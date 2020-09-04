#include <iostream>
#include <algorithm>
using namespace std;

int field[1001][3], currTotal[1001][3];
// field : 입력
// 현재 행까지의 비용의 총 합

void dp(int N) {
	for (int i = 1; i <= N; i++) {
		// i번째 행에서 각 열마다 i-1번째 행까지의 총 비용의 최솟값을 찾아 더한다.
		currTotal[i][0] = min(currTotal[i - 1][1], currTotal[i - 1][2]) + field[i][0]; 
		currTotal[i][1] = min(currTotal[i - 1][0], currTotal[i - 1][2]) + field[i][1];
		currTotal[i][2] = min(currTotal[i - 1][0], currTotal[i - 1][1]) + field[i][2];
	}
	cout << min(min(currTotal[N][0], currTotal[N][1]), currTotal[N][2]); 
	// 결국 N번째 행에는 모든 경우의 최솟값이 저장되어 있다.
	// 그 중 가장 작은 값이 우리가 원하는 최솟값
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> field[i][j];
		}
	}
	dp(N);
}