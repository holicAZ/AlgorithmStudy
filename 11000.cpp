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
		pq.push(p(s, t)); // first : ����, second : ���� �ð�
	}
	Tpq.push(pq.top().second); // �ʱⰪ
	pq.pop(); // �ʱⰪ ���� �� ���� ���� ���۽ð��� ���� pop
	while (!pq.empty()) { // ���� ������ ���� �� ���� �ݺ�
		int end = Tpq.top(); 
		if (end <= pq.top().first) {  // �������� ���۽ð��� �������� ����ð� ��
			Tpq.pop();
			Tpq.push(pq.top().second);
			pq.pop();
		}
		else { // ���۽ð��� ����ð� ���� ������ ���ο� ���ǽ� �߰�
			Tpq.push(pq.top().second);
			pq.pop();
		}	
	}
	cout << Tpq.size();
	
}