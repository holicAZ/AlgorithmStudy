#include<iostream>
#include <vector>
using namespace std;

typedef struct child {
	int left;
	int right;
}child;

vector<child> tree(27);

void preOrder(int node) {
	int l = tree[node].left;
	int r = tree[node].right;
	cout << static_cast<char>(node + 'A');

	if (l > 0)
		preOrder(l);
	if (r > 0)
		preOrder(r);
}

void inOrder(int node) {
	int l = tree[node].left;
	int r = tree[node].right;

	if (l > 0)
		inOrder(l);	
	cout << static_cast<char>(node + 'A');
	if (r > 0)
		inOrder(r);	
}

void postOrder(int node) {
	int l = tree[node].left;
	int r = tree[node].right;

	if (l > 0)
		postOrder(l);
	if (r > 0)
		postOrder(r);
	cout << static_cast<char>(node + 'A');
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		char node, left, right;
		cin >> node >> left >> right;
	
		tree[node - 'A'].left = left - 'A';
		tree[node - 'A'].right = right - 'A';
	}

	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);

	return 0;
}