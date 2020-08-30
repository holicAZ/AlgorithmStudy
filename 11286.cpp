#include<iostream>
#include<queue>

using namespace std;
priority_queue<int, vector<int>, greater<int> > great;	// greater ��������, ���� ���� top
priority_queue<int, vector<int>,less<int> > les;	// �ƹ��͵� ������ less ��������, ���� ���� top

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n--) {
		int c; cin >> c;
		if (c == 0) { 
			// ����� �������� ������ �۰�
			// ������ Ŭ���� ������ �۴�.
			if (great.empty() && les.empty()) { cout << 0 << "\n"; continue; }
			if (les.empty()) { // ���� ť�� ������� ���
				cout << great.top() << "\n";
				great.pop();
				continue;
			}
			if (great.empty()) { // ��� ť�� ������� ���
				cout << les.top() << "\n";
				les.pop();
				continue;
			}
			if (great.top() < abs(les.top())) {
				cout << great.top() << "\n";
				great.pop();
				continue;
			}
			if(great.top() >= abs(les.top())){
				cout << les.top() << "\n";
				les.pop();
				continue;
			}
		}
		if (c < 0) les.push(c); // �����̸� �������� ����
		else great.push(c); // ����̸� �������� ����
	}
	return 0;
}
