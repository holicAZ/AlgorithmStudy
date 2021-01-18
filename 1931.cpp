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
	sort(v.begin(), v.end(), compare); // 종료시간 second 값을 먼저 비교해서 작은 값부터 오름차순 동일하면 시작시간 빠른 순

	int e1 = v[0].second; // 첫 강의 종료 시간
	for (int i = 1; i < v.size(); i++) {
		if (e1 <= v[i].first) { // 다음 강의의 시작시간이 앞 강의의 종료시간 보다 뒤면 카운팅
			e1 = v[i].second;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}