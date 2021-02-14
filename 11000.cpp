#include<iostream>
#include<queue>
using namespace std;
typedef long long int llt;
typedef pair<llt, llt> p;
priority_queue <pair<llt,llt>, vector<pair<llt,llt>>, greater<pair<llt,llt> > > pq;
priority_queue <llt, vector<llt>, greater<llt> > Tpq;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int s, t, n, cnt=0;
	cin >> n;
	while (n--) {
		cin >> s >> t;
		pq.push(p(s, t)); // first : 시작, second : 종료 시간
	}
	Tpq.push(pq.top().second); // 초기값
	pq.pop(); // 초기값 설정 후 제일 빠른 시작시간의 강의 pop
	while (!pq.empty()) { // 강의 개수가 없을 때 까지 반복
		int end = Tpq.top(); 
		if (end <= pq.top().first) {  // 다음강의 시작시간과 이전강의 종료시간 비교
			Tpq.pop();
			Tpq.push(pq.top().second);
			pq.pop();
		}
		else { // 시작시간이 종료시간 보다 작으면 새로운 강의실 추가
			Tpq.push(pq.top().second);
			pq.pop();
		}	
	}
	cout << Tpq.size();
	
}