#include<iostream>
using namespace std;
typedef long long int llt;
llt x,y;
llt GCD(llt a, llt b) {
	return b ? GCD(b, a % b) : a;
}

llt LCM(llt a, llt b) {
	llt c = GCD(a, b);
	return a * b / c;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	llt n, m; // n은 최대 공약수, m은 최소 공배수
	cin >> n >> m;
	
	llt k = m / n; // 최소 공배수 / 최대 공약수
	
	for (llt i = 1; i*i <= k; i++) { // k의 약수 구하기
		if (k % i == 0 && GCD(k/i,i)==1) {	// k값의 약수들의 짝이 서로 서로소 관계인것 
			// 계속 저장을 반복하면 결국 최솟값인
			// 중간 값을 저장하고 종료
			x = i;
			y = (llt)k / i;
		}
	}
	
	cout << (llt)x * n << " " << (llt)y * n;
	return 0;
}