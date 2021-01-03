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
		if (s == "0") break; // 0이 입력되면 종료

		for (int i = 0; i < s.length(); i++) // 문자열로 입력 받은 걸 char형으로 하나씩 떼서 저장
			v.push_back(s[i]);

		reverse(v.begin(), v.end()); // 저장한 것을 뒤집는다.

		string sum = ""; 
		for (char c : v) // 뒤집은 char형 데이터를 다시 string 형으로 붙인다.
			sum += c; // + 연산하면 string 합쳐짐

		
		if (sum == s) // 입력받은 값과 뒤집은 값이 같으면 팰린드롬수
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";

		v.clear(); // vector 초기화
	}
	return 0;
}