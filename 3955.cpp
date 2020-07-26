#include <iostream>
#include <cmath>

using namespace std;

int k, c;

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

void Extended_Euclidean_Algorithm(int a, int b) { // 유클리드 확장
	
	int q = 0, tmp = 0, r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	
	while (r2) {	// r2(나머지)가 0이 될 때까지 진행
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
		cin >> k >> c;	// k 사람 수, c 한 봉지에 들어있는 사탕 수

		if (c == 1) {	// 사탕이 1개씩 들었을때
			if (k+1 > pow(10, 9))	// 사람 수 + 1가 10^9보다 많을때
				cout << "IMPOSSIBLE" << "\n";	// 사탕을 무조건 하나 잃어버림
			else
				cout << k + 1 << "\n";
			continue;
		}

		if (k == 1) {	// 사람 수가 1명일 때
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