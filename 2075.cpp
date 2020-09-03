#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq; // �켱���� ������ -> ū��
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) { // n*n���� �� �Է�
		int c;
		cin >> c;
		// pq�� �ִ�ũ�⸦ n (�޸� ����)
		if(pq.size()<n) // n���� size�� ������ push
			pq.push(c);	// ť�� �־� ����
		else // n ���� ũ�ų� ������ ���� ���� pop�ϰ� push
			if (pq.top() < c) { // �Է� ������ ���� pq�� top���� ������ ��ü
				pq.pop();
				pq.push(c);
			} // �ݺ����� ����Ǹ� n���� ���� ������������ ����
			  // ���� top�� �ִ� ���� n��° ū��
	}
	cout << pq.top(); // pop�Ŀ� 
	return 0;
}
