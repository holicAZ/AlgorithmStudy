#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int llt;

vector<llt> v;
vector<llt> divisor;
llt GCD(llt a, llt b) {
	return b ? GCD(b, a % b) : a;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, c;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());	// �������� ������ ���ش�.

	for (int i = 1; i < n; i++) {
		v[i-1] = v[i] - v[i-1]; // ū������ �������� ���� ���� �ε����� �ִ´�.
	}
	
	for (int i = 1; i < n-1; i++) { // ���� ���� ������ �� ���� ������ -1 ��ŭ ����
		v[i] = GCD(v[i - 1], v[i]);
	}
	llt a = v[n-2]; // GCD�� v�� �ִ� �ε����� -2�� ����
	//�ִ� ������� ����� ��� ���Ѵ�.
	for (int i = 1; i * i <= a; i++) { 
		if (a % i == 0) {	// ����� ���Ϳ� ����
			divisor.push_back(i);
			if (i == a / i) continue; // ������ ���� ���� ������ �ϳ��� ����
			divisor.push_back(a / i);
		}
	}
	sort(divisor.begin(), divisor.end());

	for (int i = 1; i < divisor.size(); i++) { // 1���� ũ�ٴ� ���Ƕ����� �ε����� 1���� ����
		cout << divisor[i] << " ";
	}
	return 0;
}