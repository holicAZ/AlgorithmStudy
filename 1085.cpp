#include<iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int side, up, rightSum, leftSum, Sum;
	side = w - x;
	up = h - y;
	rightSum = min(side, up); // ��, ������ �� �ּҰŸ� ���
	leftSum = min(x, y);	  // �Ʒ�, ���� �� �ּҰŸ� ���
	Sum = min(rightSum, leftSum); // �� �� ���� �ּҰŸ� ���
	cout << Sum;
	
	return 0;
}