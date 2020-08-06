#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int tree[100000];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = v[start];
	int mid = (start + end)/2;
	tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
	return tree[node];
}

int sum(int start, int end, int node, int left, int right) // ���� �� ���ϱ�
{
	if (left > end || right < start) return 0; // ���� �ۿ� �ִ� ���
	if (left <= start && end <= right) return tree[node]; // ���� ���� �ִ� ���

	// �ƴ� ��� �� �κ����� ������ ���� ���Ѵ�.
	// ������ ���Ѵ�.
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

//dif : ������ ��
//index : ���� ���� �����ϰ��� �ϴ� ���
void update(int start, int end, int node, int index, int dif) {	// ����� ����
	if (index <= start || index >= end) return; // ���� �ۿ� �ִ� ���

	// ���� ���� �ִ� ���
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);	// ���� �ڽ� ���
	update(mid + 1, end, node * 2 + 1, index, dif);	// ���� �ڽ� ���
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	init(0, v.size()-1, 1); // ���� �� Ʈ�� ����

	int a, b, c;
	for (int i = 0; i < (m + k); i++) {
		cin >> a;

		if (a == 1) {
			cin >> b >> c;
			int diff = c - tree[b-1];
			tree[b-1] = c;
			update(0, v.size() - 1, 1, b-1, diff);
		}

		if (a == 2) {
			cin >> b >> c;
			cout << sum(0, v.size() - 1, 1, b-1, c-1) << "\n";
		}
	}
}