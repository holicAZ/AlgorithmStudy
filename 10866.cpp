#include <iostream>
#include <deque>
using namespace std;

deque<int> s;
int n, c;

void push_front() {
	cin >> c;
	s.push_front(c);
}
void push_back() {
	cin >> c;
	s.push_back(c);
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

void pop_front() {
	if (s.empty())
		cout << -1 << "\n";
	else
	{
		cout << s.front() << "\n";
		s.pop_front();
	}
}

void pop_back() {
	if (s.empty())
		cout << -1 << "\n";
	else
	{
		cout << s.back() << "\n";
		s.pop_back();
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
		if (act == "push_front") {
			push_front();
		}
		if (act == "push_back") {
			push_back();
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
		if (act == "pop_front") {
			pop_front();
		}
		if (act == "pop_back") {
			pop_back();
		}
	}
}
