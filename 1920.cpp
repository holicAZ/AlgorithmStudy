#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, A, B;
	cin >> n;
	vector<int> n_vector;
	vector<int> m_vector;

	for (int i = 0; i < n; i++) {
		cin >> A;
		n_vector.push_back(A);
	}

	sort(n_vector.begin(), n_vector.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> B;
		m_vector.push_back(B);
	}

	for (int i = 0; i < m; i++) {
		cout << binary_search(n_vector.begin(), n_vector.end(), m_vector[i]) << "\n";
	}
}