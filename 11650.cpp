#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> pii;

vector<pii> v;

bool compare(pii a, pii b) { // x 부터 비교, 같으면 y 비교
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main(void) {
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), compare);

	for (pii i : v)
		cout << i.first << " " <<i.second << "\n";
}