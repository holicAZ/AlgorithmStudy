#include <iostream>
#include <algorithm>
using namespace std;

char arr[51][51];
int n;

int Max = 1;

void row_find(int a, int b, int cnt) {
	if (arr[a][b] == arr[a + 1][b])
		row_find(a + 1, b, cnt + 1);
	else
		Max = max(Max, cnt);

}
void line_find(int a, int b, int cnt) {
	if (arr[a][b] == arr[a][b+1])
		line_find(a, b+1, cnt + 1);
	else
		Max = max(Max, cnt);
}
void find_max() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == arr[i][j + 1])
				line_find(i, j, 1);
			if (arr[i][j] == arr[i + 1][j])
				row_find(i, j, 1);
		}
	}
}
int x[] = { 1,0 };
int y[] = { 0,1 };

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	find_max();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 2; k++) {
				int f = i + x[k];
				int s = j + y[k];

				if (f >= n || s >= n) continue;

				if (arr[i][j] != arr[f][s]) {
					swap(arr[i][j], arr[f][s]);

					find_max();
						
					swap(arr[i][j], arr[f][s]);
				}
			}
		}
	}

	cout << Max;
}