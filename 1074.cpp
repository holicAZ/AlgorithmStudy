#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, r, c;
	cin >> N >> r >> c;
	
	int ans = 0;
	while (N) { // 사분면을 체크해서 계속 줄여나간다. N==0 될 때까지
		int point = pow(2, N - 1);
		int sqrt;
		if (r < point && c >= point) sqrt = 1;  // 1 사분면
		if (r < point && c < point) sqrt = 0; // 2 사분면
		if (r >= point && c < point) sqrt = 2;  // 3 사분면 
		if (r >= point && c >= point) sqrt = 3;  // 4 사분면

		r %= point; // 행, 열 축소
		c %= point; 

		ans += pow(point, 2) * sqrt; // point^2 -> 한 개의 사분면 방문 수 * sqrt 사분면에 따른 개수 추가
		N--;
	}
	cout << ans;
	return 0;
}