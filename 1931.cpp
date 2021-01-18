#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;

bool compare(pii a, pii b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,cnt=1;
	cin >> n;
	while (n--) {
		int s, e;
		cin >> s >> e;

		v.push_back({ s,e });
	}
	sort(v.begin(), v.end(), compare); // ����ð� second ���� ���� ���ؼ� ���� ������ �������� �����ϸ� ���۽ð� ���� ��

	int e1 = v[0].second; // ù ���� ���� �ð�
	for (int i = 1; i < v.size(); i++) {
		if (e1 <= v[i].first) { // ���� ������ ���۽ð��� �� ������ ����ð� ���� �ڸ� ī����
			e1 = v[i].second;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}