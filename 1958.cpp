#include<iostream>

using namespace std;

char field[101][101][101] = { 0, };
int i, k, x;
char s[101];
char c[101];
char t[101];
int main() {
	scanf("%s", s+1);
	scanf("%s", c+1);
	scanf("%s", t+1);
	/*
		lcs �Ŀ� �� lcs�� ���ָ� �ݷ� ����
			- dababcf
			- ababdef
			- df
		������ 3���� dp�� ���
	*/
	for ( i = 1; s[i]; i++) {
		for ( k = 1; c[k]; k++) {
			for ( x = 1; t[x]; x++) {
				if (s[i]==c[k]&& s[i] == t[x]&& c[k] == t[x]) {
					field[i][k][x] = field[i - 1][k - 1][x-1] + 1; // ������ �� �� �밢 +1
				}
				else { 
					field[i][k][x] = max(field[i-1][k][x], max(field[i][k-1][x], field[i][k][x - 1]) );
				}
			}
		}
	}

	printf("%d",field[i-1][k-1][x-1]);

	return 0;
}