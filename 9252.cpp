#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

stack<char> st;
int field[1001][1001] = { 0, };
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s, c;
	cin >> s >> c;

	for (int i = 1; i <= c.length(); i++) {
		for (int k = 1; k <= s.length(); k++) {
			if (c.at(i - 1) == s.at(k - 1)) {
				field[i][k] = field[i - 1][k - 1] + 1; // ������ �´밢 +1;
			}
			else { // �ٸ��� ���� ���� �� �� ū �� ����
				field[i][k] = max(field[i][k - 1], field[i - 1][k]);
			}
		}
	}
	int i = c.length();
	int k = s.length(); // ���� ���ڸ�
	int cnt = field[c.length()][s.length()];
	while (true) {
		if (cnt == 0) break;

		if (field[i][k] == field[i-1][k - 1]) {// �´밢�̶� ������ �̵�
			k--;
			i--;
			continue;
		}
		if (field[i][k] == field[i][k - 1]) {// �����̶� ������ �̵�
			k--;
			continue;
		}
		else if (field[i][k] == field[i - 1][k]) {// �����̶� ������ �̵�
			i--;
			continue;
		}

		// �� ���ǿ� �ɸ��� �ʴ´ٸ� stack�� ����
		if (field[i][k] == cnt)
			st.push(c.at(i-1));

		i--;
		k--;
		cnt--;
	}
		
	
	if (field[c.length()][s.length()] == 0) {
		cout << 0;
	}
	
	else {
		int size = st.size();
		cout << field[c.length()][s.length()] << "\n";
		for (int i = 0; i < size ; i++) {
			cout << st.top();
			st.pop();
		}
	}
	
	return 0;
}