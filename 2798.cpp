#include<iostream>
#include<vector>
#include<math.h>
#include <algorithm>
using namespace std;

vector<int> v;
int sum, dif=0;
int main(void) {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < N-2; i++) { // �տ������� 3���� ��� �� �غ���.
		for (int j = i+1; j < N-1; j++) {
			for (int k = j+1; k < N; k++) { 
				sum = v[i] + v[j] + v[k];
				if (sum <= M) {
					dif = max(dif, sum);
				}
			}
		}
	}
	cout << dif;
	return 0;
}