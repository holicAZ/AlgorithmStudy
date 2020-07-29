#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll time[101];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, c;
	cin >> n >> c;
	vector<bool> check(c+1,false);	// 폭죽쇼의 시간 c+1 만큼 bool 벡터 false로 초기화
	for (int i = 1; i <= n; i++) {
		cin >> time[i];			// 한 학생이 터뜨리는 주기 입력
	}
	
	for (ll i = 1; i <= n; i++) {
		for (ll j = time[i]; j <= c; j = j + time[i]) // 폭죽 주기 마다 check표시
			check[j] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= c; i++)
		if (check[i]) cnt++;

	cout << cnt;
	return 0;
}