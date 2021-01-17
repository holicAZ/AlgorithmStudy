#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, r, c;
	cin >> N >> r >> c;
	
	int ans = 0;
	while (N) { // ��и��� üũ�ؼ� ��� �ٿ�������. N==0 �� ������
		int point = pow(2, N - 1);
		int sqrt;
		if (r < point && c >= point) sqrt = 1;  // 1 ��и�
		if (r < point && c < point) sqrt = 0; // 2 ��и�
		if (r >= point && c < point) sqrt = 2;  // 3 ��и� 
		if (r >= point && c >= point) sqrt = 3;  // 4 ��и�

		r %= point; // ��, �� ���
		c %= point; 

		ans += pow(point, 2) * sqrt; // point^2 -> �� ���� ��и� �湮 �� * sqrt ��и鿡 ���� ���� �߰�
		N--;
	}
	cout << ans;
	return 0;
}