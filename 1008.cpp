#include <iostream>
using namespace std;

double a, b;
int main() {
	cout << fixed; 
	cout.precision(10); // �Ҽ��� �ڸ� ����
	cin >> a >> b;
	cout << a / b;
	return 0;
}