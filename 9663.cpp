#include<iostream>
#include<cstdlib>
using namespace std;

int N, answer=0;
int field[15];

bool check(int x) {
	for (int i = 1; i < x; i++) {
		if (field[i] == field[x]) // 같은 행, 열에 존재
			return false;
		if (abs(i - x) == abs(field[i] - field[x]))
			// 대각선에 존재, 확인 : ㅣx축 끼리 뺀 값ㅣ = ㅣy축 끼리 뺀 값ㅣ
			return false;
	}
	return true; // 놓을 수 있다.
}

void dfs(int row) {
	if (row == N) answer++;
	else {
		for (int i = 1; i <= N; i++) {
			field[row + 1] = i;
			if (check(row + 1)) { // 놓을 수 있으면 다음 열 확인
				dfs(row + 1);
			}
			else
				field[row + 1] = 0;
		}
	}
	field[row] = 0;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		field[1] = i;
		dfs(1);
	}
	cout << answer;
	return 0;
}