#include <iostream>
#include <queue>
using namespace std;

queue<int> s;
int n, c;

void push() {
	cin >> c;
	s.push(c);
}

void front() {
	if (!s.empty())
		cout << s.front() << "\n";
	else
		cout << -1 << "\n";
}

void back() {
	if (!s.empty())
		cout << s.back() << "\n";
	else
		cout << -1 << "\n";
}

void pop() {
	if (s.empty())
		cout << -1 << "\n";
	else
	{
		cout << s.front() << "\n";
		s.pop();
	}
}

void size() {
	if (s.size() < 0)
		cout << 0 << "\n";
	else
		cout << s.size() << "\n";
}

void empty() {
	if (!s.empty())
		cout << 0 << "\n";
	else
		cout << 1 << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	string act;

	for (int i = 0; i < n; i++) {
		cin >> act;
		if (act == "push") {
			push();
		}
		if (act == "front") {
			front();
		}
		if (act == "back") {
			back();
		}
		if (act == "size") {
			size();
		}
		if (act == "empty") {
			empty();
		}
		if (act == "pop") {
			pop();
		}
	}
}
