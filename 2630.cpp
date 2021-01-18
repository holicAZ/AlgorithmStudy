#include<iostream>
using namespace std;

int paper[128][128];
int color[2] = {0, }; // index -> 0: White, 1: Blue.

void check_color(int x, int y, int N) {
	if (!N) return;
	int paint = paper[x][y]; // first color set
	int count_color=0;
	bool flag = false;

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			if (paper[x+i][y+k] != paint) { // check same color
				i = N;
				break;
			}
			count_color++;
		}
		
	}
	if (count_color ==(N*N)) { // all color is same.
		color[paint]++;
		flag = true;
	}

	if (!flag) {
		check_color(x, y, N/2); // 2 quadrant
		check_color(x, y + N/2, N/2); // 1 quadrant
		check_color(x + N/2, y, N/2); // 3 quadrant
		check_color(x + N/2, y + N/2, N/2); // 4 quadrant
	}
	
	return;
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> paper[i][k]; // color set
		}
	}
	check_color(0, 0, n); // W, B color paper counting func.

	cout << color[0] << "\n" << color[1];
}