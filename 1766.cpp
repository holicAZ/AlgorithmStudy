#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>* edge;		// ������ ���� ���๮�� ����
vector<int> inDegree;	// �������� Ȯ��
priority_queue<int, vector<int>, greater<int>> result; // ��� �� ����
int n, m;

void init() { // �ʱ�ȭ �Լ�
	edge = new vector<int>[n+1];	// ���๮�� ����迭 �ʱ�ȭ
	inDegree.resize(n + 1);			// �������� �迭 resize
	fill(inDegree.begin(), inDegree.end(), 0);	// �־��� ���� �� n��ŭ 0���� ä���
}
void input(int a, int b) {	// ���� ���� �Է�
	edge[a].push_back(b);
	inDegree[b]++;		// ��������+1
}
void print() { // ���� Ǫ�� ���� ���
	while(n--) {	// �� ���� ����ŭ �ݺ�
		int x = result.top(); // �켱���� ť�� top�� ����
		result.pop();
		cout << x << " "; // top�� ���
		for (int j = 0; j < edge[x].size(); j++) { // top�� ���๮�� Ȯ���ؼ� inDegree ������Ʈ
			int y = edge[x][j];
			inDegree[y]--;
			if (!inDegree[y]) result.push(y); // ������Ʈ �� ���������� 0�̸� �켱���� ť�� ����
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	init(); // ���� �� ��ŭ �ʱ�ȭ
	
	while (m--) {
		int a, b;
		cin >> a >> b;
		input(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) result.push(i); // ���������� 0�̸� ��带 �켱���� ť�� ����
	}
	print();
	
	return 0;
}