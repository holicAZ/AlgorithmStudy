#include <iostream>
#include<string>
using namespace std;

int main() {
	int N, x;
	int bit=0;
	string s;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			bit |= (1 << x); // ��Ʈ or ����
		}
		else if (s == "remove") {
			cin >> x;
			bit &= (-1 - (1 << x));
			// -1 == 1111111... �� ���� �ش� ��Ʈ x�ڸ��� ���ش�.
			// 8bit ���� x=1 �̸� bit => 1111 1110
		}
		else if (s == "check") {
			cin >> x;
			if (bit & (1 << x)) // and���� x���� Ȯ��
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "toggle") { // xor
			cin >> x;
			bit ^= (1 << x);
		}
		else if (s == "all") {
			bit = (1 << 20) - 1;
		}
		else bit = 0;
	}
	return 0;
}