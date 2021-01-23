#include<iostream>
#include<stack>
using namespace std;

stack<char> s;

int main(void) {
	int T;
	
	cin >> T;
	while (T--) {
		string str;
		bool flag = false; 
		cin >> str;
		for (int i = 0; i < str.length(); i++) { // ��ȣ ���ڿ��� �Է¹޴´�
			if (str[i] == '(') //  '(' ���ڰ� ���� �� stack�� push
				s.push(str[i]);
			else {			   // ')' ���ڰ� ���� �� stack�� ����ִ��� Ȯ���ϰ� ������� ������ pop �� �� ����
				if (!s.empty())
					s.pop();
				else {		   // ����ִٴ� �� �������� '(' ���� ')'�� ����� ���̹Ƿ� ����
					cout << "NO" << "\n";
					flag = true; // ������ Ȯ���ϱ� ���ؼ� flag = true ó��
					break;
				}
			}
			
		}
		if (!flag) { // ��ȣ ���ڿ��� �Ǵ��� ���
			if (s.empty())
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		while (!s.empty())  // �ʱ�ȭ
			s.pop();
	}
	return 0;
}