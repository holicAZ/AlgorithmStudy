#include<iostream>
#include<vector>
using namespace std;

typedef struct {
	int One_cnt=0, Zero_cnt=0;
	bool check = false;
}arr;

arr cnt[41];
arr total1,total2,TOTAL;

arr dp(int n) {
	if (cnt[n].check) {
		return cnt[n];
	}
	cnt[n].check = true;

	if (n == 0) {
		cnt[n].Zero_cnt++;
		return cnt[0];
	}
	if (n == 1) {
		cnt[n].One_cnt++;
		return cnt[1];
	}
	else {
		total1 = dp(n - 1);
		total2 = dp(n - 2);
		cnt[n].One_cnt = total1.One_cnt + total2.One_cnt;
		cnt[n].Zero_cnt = total1.Zero_cnt + total2.Zero_cnt;
		return cnt[n];
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		TOTAL = dp(m);
		cout << TOTAL.Zero_cnt << " " << TOTAL.One_cnt << "\n";
	}
	return 0;
}

// �Ǻ���ġ ������ 0�� 1�� ������ ���� ��ü�� �ִ�
// N��° ���� 1�� ������ N�� �Ǻ���ġ �� 
// N��° ���� 0�� ������ N-1�� �Ǻ���ġ ��