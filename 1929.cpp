#include<iostream>
using namespace std;

bool arr[1000001] = {true,true,}; // 1 은 소수가 아님

void func(int e) {
	for (int i = 2; i <= e; i++) {		
		if (arr[i]) continue;
		for (int j = i*2; j <= e; j+=i) {
			arr[j] = true;
		}
	}
}
int main(void) {
	int s, e;
	cin >> s >> e;
	func(e);
	for (int i = s; i <= e; i++) {
		if (!arr[i]) cout << i << "\n";
	}

	return 0;
}