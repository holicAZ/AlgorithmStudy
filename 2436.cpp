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

	llt n, m; // n�� �ִ� �����, m�� �ּ� �����
	cin >> n >> m;
	
	llt k = m / n; // �ּ� ����� / �ִ� �����
	
	for (llt i = 1; i*i <= k; i++) { // k�� ��� ���ϱ�
		if (k % i == 0 && GCD(k/i,i)==1) {	// k���� ������� ¦�� ���� ���μ� �����ΰ� 
			// ��� ������ �ݺ��ϸ� �ᱹ �ּڰ���
			// �߰� ���� �����ϰ� ����
			x = i;
			y = (llt)k / i;
		}
	}
	
	cout << (llt)x * n << " " << (llt)y * n;
	return 0;
}