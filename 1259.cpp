#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<char> v;

int main(void) {
	while (true) {
		string s;
		cin >> s;
		if (s == "0") break; // 0�� �ԷµǸ� ����

		for (int i = 0; i < s.length(); i++) // ���ڿ��� �Է� ���� �� char������ �ϳ��� ���� ����
			v.push_back(s[i]);

		reverse(v.begin(), v.end()); // ������ ���� �����´�.

		string sum = ""; 
		for (char c : v) // ������ char�� �����͸� �ٽ� string ������ ���δ�.
			sum += c; // + �����ϸ� string ������

		
		if (sum == s) // �Է¹��� ���� ������ ���� ������ �Ӹ���Ҽ�
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";

		v.clear(); // vector �ʱ�ȭ
	}
	return 0;
}