#include <iostream>
using namespace std;

double a, b;
int main() {
	cout << fixed; 
	cout.precision(10); // 소수점 자리 맞춤
	cin >> a >> b;
	cout << a / b;
	return 0;
}