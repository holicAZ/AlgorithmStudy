#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool field[25][25];
int n, cnt = 0, total = 0;
vector <int> v;

void chain(int x, int y) {
	cnt++;	// ����ȴٴ� ���� ������ ���� �� ++
	if (x < n - 1 && field[x+1][y]) {		// ��
		field[x][y] = 0;
		chain(x + 1, y);
	}
	if (x - 1 >= 0 && field[x - 1][y]) {	// ��
		field[x][y] = 0;
		chain(x - 1, y);
	}
	if (y < n - 1 && field[x][y + 1]) {		//��
		field[x][y] = 0;
		chain(x, y + 1);
	}
	if (y - 1 >= 0 && field[x][y - 1]) {	//��
		field[x][y] = 0;
		chain(x, y - 1);
	}
	else {									// �� �� �� �� ��� 0
		field[x][y] = 0;
		return;
	}
}

void check() {

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (field[x][y]) {
				cnt = 0;	// ���� �� ���� �� �ʱ�ȭ
				total++;	// ������ �� ++
				chain(x, y);
				v.push_back(cnt); // ������ ���� ���� �� (cnt) �� ���Ϳ� ����
			}
		}
	}
	sort(v.begin(), v.end()); // �������� ����
	
	cout << total << "\n";
	for(int a : v)
		cout << a << "\n";
}

bool cast(char c) {	// char to bool
	if (c == '1')
		return true;
	else if (c == '0')
		return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;

	memset(field, false, sizeof(field));
	char c;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;	// string Ÿ������ �Է�
		for (int j = 0; j < n; j++) {
			field[i][j] = cast(s.at(j)); // char�� �ɰ��� boolŸ������ ĳ���� �� ����
		}
	}
	
	check();
}
