#include <iostream>
using namespace std;

int fn(int n) {

	if (n == 0)
		return 0;

	else if (n == 1)
		return 1;

	return fn(n - 1) + fn(n - 2);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	cout << fn(n);
}