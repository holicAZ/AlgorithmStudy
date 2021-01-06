#include<iostream>
#include<cstdlib>
using namespace std;

int N, answer=0;
int field[15];

bool check(int x) {
	for (int i = 1; i < x; i++) {
		if (field[i] == field[x]) // ���� ��, ���� ����
			return false;
		if (abs(i - x) == abs(field[i] - field[x]))
			// �밢���� ����, Ȯ�� : ��x�� ���� �� ���� = ��y�� ���� �� ����
			return false;
	}
	return true; // ���� �� �ִ�.
}

void dfs(int row) {
	if (row == N) answer++;
	else {
		for (int i = 1; i <= N; i++) {
			field[row + 1] = i;
			if (check(row + 1)) { // ���� �� ������ ���� �� Ȯ��
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