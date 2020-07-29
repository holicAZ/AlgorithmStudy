#include<iostream>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> oddIdx; // Ȧ�� 
priority_queue<int,vector<int>,less<int>> evenIdx;   // ¦��: cout
bool flag = false; // false�� ¦�� true�� Ȧ�� 
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (evenIdx.empty()) {
			evenIdx.push(c);
			cout << c <<"\n";
			continue;
		}
		if (oddIdx.empty()) {
			oddIdx.push(c);
			if (evenIdx.top() <= oddIdx.top()) // top���� ���ؼ� ¦���ε��� ���
				cout << evenIdx.top() << "\n";
			else // ¦�� �ε����� top ���� �� ũ�� 
			{	 // Ȧ�� �ε����� top ���� ��ȯ �� �� �� ���
				int temp = oddIdx.top();
				oddIdx.pop();
				oddIdx.push(evenIdx.top());
				evenIdx.pop();
				evenIdx.push(temp);
				cout << evenIdx.top()<<"\n";
			}
			continue;
		}
		// ���� �ϳ� �̻� ���������
		if (!flag) { // ¦�� : ��������
			evenIdx.push(c);
			flag = true;	// ������ Ȧ��
		}
		else {		// Ȧ�� : ��������
			oddIdx.push(c);
			flag = false;	// ������ ¦��	
		}
		if (evenIdx.top() <= oddIdx.top()) // top���� ���ؼ� ¦���ε��� ���
			cout << evenIdx.top() << "\n";
		else // ¦�� �ε����� top ���� �� ũ�� 
		{	 // Ȧ�� �ε����� top ���� ��ȯ �� �� �� ���
			int temp = oddIdx.top();
			oddIdx.pop();
			oddIdx.push(evenIdx.top());
			evenIdx.pop();
			evenIdx.push(temp);
			cout << evenIdx.top() << "\n";
		}
	}
	return 0;
}