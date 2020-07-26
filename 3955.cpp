#include <iostream>
#include <cmath>

using namespace std;

int k, c;

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

void Extended_Euclidean_Algorithm(int a, int b) { // ��Ŭ���� Ȯ��
	
	int q = 0, tmp = 0, r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	
	while (r2) {	// r2(������)�� 0�� �� ������ ����
		q = r1 / r2;
		tmp = r1;
		r1 = r2;
		r2 = tmp - r2 * q;
		tmp = s1;
		s1 = s2;
		s2 = tmp - s2 * q;
		tmp = t1;
		t1 = t2;
		t2 = tmp - t2 * q;
	}
	
	for (;;) {
		if (t1 > 0)
			break;
		
		t1 += k;
	}

	if (t1 > pow(10, 9)) {
		cout << "IMPOSSIBLE" << "\n";
		return;
	}

	if (t1 > 0) {
		cout << t1 << "\n";
		return;
	}
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> k >> c;	// k ��� ��, c �� ������ ����ִ� ���� ��

		if (c == 1) {	// ������ 1���� �������
			if (k+1 > pow(10, 9))	// ��� �� + 1�� 10^9���� ������
				cout << "IMPOSSIBLE" << "\n";	// ������ ������ �ϳ� �Ҿ����
			else
				cout << k + 1 << "\n";
			continue;
		}

		if (k == 1) {	// ��� ���� 1���� ��
			cout << 1 << "\n";
			continue;
		}

		if (GCD(k, c) != 1) {
			cout << "IMPOSSIBLE" << "\n";
			continue;
		}

		Extended_Euclidean_Algorithm(k, c);
	}
	return 0;
}