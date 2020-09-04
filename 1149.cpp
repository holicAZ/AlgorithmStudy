#include <iostream>
#include <algorithm>
using namespace std;

int field[1001][3], currTotal[1001][3];
// field : �Է�
// ���� ������� ����� �� ��

void dp(int N) {
	for (int i = 1; i <= N; i++) {
		// i��° �࿡�� �� ������ i-1��° ������� �� ����� �ּڰ��� ã�� ���Ѵ�.
		currTotal[i][0] = min(currTotal[i - 1][1], currTotal[i - 1][2]) + field[i][0]; 
		currTotal[i][1] = min(currTotal[i - 1][0], currTotal[i - 1][2]) + field[i][1];
		currTotal[i][2] = min(currTotal[i - 1][0], currTotal[i - 1][1]) + field[i][2];
	}
	cout << min(min(currTotal[N][0], currTotal[N][1]), currTotal[N][2]); 
	// �ᱹ N��° �࿡�� ��� ����� �ּڰ��� ����Ǿ� �ִ�.
	// �� �� ���� ���� ���� �츮�� ���ϴ� �ּڰ�
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