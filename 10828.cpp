#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main(void) {
	int n, num;
	string op;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> op;

		if (op == "push") {
			cin >> num;
			s.push(num);
		}

		if (op == "top") {
			if (!s.empty())
				cout << s.top() << "\n";
			else
				cout << -1 << "\n";
		}

		if (op == "size") {
			if (s.size() < 0)
				cout << 0 << "\n";
			else
				cout << s.size() << "\n";
		}

		if (op == "pop") {
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else
				cout << -1 << "\n";
		}

		if (op == "empty") {
			if (!s.empty())
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		}
	}
}