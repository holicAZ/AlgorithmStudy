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
		for (int i = 0; i < str.length(); i++) { // 괄호 문자열을 입력받는다
			if (str[i] == '(') //  '(' 문자가 있을 시 stack에 push
				s.push(str[i]);
			else {			   // ')' 문자가 있을 시 stack이 비어있는지 확인하고 비어있지 않으면 pop 한 번 실행
				if (!s.empty())
					s.pop();
				else {		   // 비어있다는 건 개괄문자 '(' 없이 ')'를 사용한 것이므로 오류
					cout << "NO" << "\n";
					flag = true; // 오류를 확인하기 위해서 flag = true 처리
					break;
				}
			}
			
		}
		if (!flag) { // 괄호 문자열이 되는지 출력
			if (s.empty())
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		while (!s.empty())  // 초기화
			s.pop();
	}
	return 0;
}