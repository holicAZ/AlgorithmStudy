#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v1;
vector<int> v2;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	while (n--) {
		int x;
		cin >> x;
		v1.push_back(x);
	}

	v2.assign(v1.begin(), v1.end()); // ����
	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end()); // �ߺ�����

	for (int a : v2) {
		cout << lower_bound(v1.begin(), v1.end(), a) - v1.begin() << " "; // �̺�Ž��
	}
	return 0;
}