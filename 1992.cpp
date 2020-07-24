#include<iostream>
using namespace std;

char c[64][64];
int n;

void quad(int sx,int sy, int size) {
	char first = c[sx][sy];

	bool flag = true;
	for (int i = sx; i < sx+size; i++) {
		for (int j = sy; j < sy+size; j++) {
			if (first != c[i][j]) { // 다른게 있으면 분할해서 본다
				flag = false;
			}
		
		}
	}
	if (flag) {
		cout << first ;
		return;
	}
	else {
		cout << "(";
		quad(sx,sy,size/2); // 왼쪽위
		quad(sx, sy + size / 2, size / 2);  // 오른쪽위
		quad(sx+size / 2, sy, size / 2);// 왼쪽 아래
		quad(sx+size/2, sy+size/2, size / 2);	//오른쪽 아래
		cout << ")";
		return;
	}
}
	
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> c[i];

	quad(0,0,n);
}