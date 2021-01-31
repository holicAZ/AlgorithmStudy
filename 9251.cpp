#include<iostream>
#include<algorithm>
using namespace std;

int field[1001][1001] = { 0, };
int main(void) {
	string s, c;
	cin >> s >> c;
	

	for (int i = 1; i <= c.length(); i++) {
		for (int k = 1; k <= s.length(); k++) {
			if (c.at(i-1) == s.at(k-1)) {
				field[i][k] = field[i - 1][k - 1] + 1; // 같으면 좌대각 +1;
			}
			else { // 다르면 위와 왼쪽 중 더 큰 값 선택
				field[i][k] = max(field[i][k - 1], field[i - 1][k]);
			}
		}
	}

	cout << field[c.length()][s.length()];
	return 0;
}