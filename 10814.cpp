#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, string> pis;
vector<pair<int,string> > v;

bool compare(pis a, pis b) { // a는 현재원소, b는 다음원소  오름차순  a<b,  내림차순 a>b
	if (a.first < b.first)
	{
		return true;
	}
	else
		return false;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string name;
		int age;

		cin >> age >> name;

		v.push_back(make_pair(age, name));

	}
	
	stable_sort(v.begin(), v.end(),compare); // stable sort : first에 값이 같으면 그대로 둔다.
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}