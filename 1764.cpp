#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;
vector<string> va;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n+m; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end()); // �����ϸ� �躸���� �پ��ְ� ��

	for (int i = 1; i < n+m; i++) {
		if(v[i] == v[i-1])
			va.push_back(v[i]);
		//if (find(v.begin(), v.end(), s) - v.begin() != v.size()) // ������ ��ġ�� �� �� ����.	
	}
	cout << va.size() << "\n";
	
	for (string a : va) cout << a << "\n";
}