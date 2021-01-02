#include<iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int side, up, rightSum, leftSum, Sum;
	side = w - x;
	up = h - y;
	rightSum = min(side, up); // 위, 오른쪽 중 최소거리 계산
	leftSum = min(x, y);	  // 아래, 왼쪽 중 최소거리 계산
	Sum = min(rightSum, leftSum); // 위 두 값중 최소거리 계산
	cout << Sum;
	
	return 0;
}