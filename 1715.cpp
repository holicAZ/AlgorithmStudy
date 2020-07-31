#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
int main(void) {
	int n; cin >> n;
	for (int i = 0; i < n;i++) {
		int c;
		cin >> c;
		pq.push(c);
	}
	if (n == 1) { // ī�� ������ �ϳ��� �� x, 0���
		cout << 0;
		return 0;
	}
	int sum = 0;
	while (true) { 
		int x = pq.top(); 
		pq.pop();
		int y = pq.top();
		pq.pop();
		int z = x + y; // �켱���� ť���� top�� �׺��� �Ѵܰ� ���� ���� ����
		sum += z; // ���ߴ� ���� ��� �������ش�.
		if (pq.empty())	// pop�� ���� ��� �� �������� ���߿� �����
			break;
		pq.push(z);	// �������� ������ ���ߴ� ���� push�ؼ� ������ �����ش�
	}
	cout << sum;
	return 0;
}