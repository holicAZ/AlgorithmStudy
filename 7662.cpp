#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, less<pii> > max_pq;
priority_queue<pii, vector<pii>, greater<pii> > min_pq;
bool check[1000001];

void clear() {
	while (!max_pq.empty())  
		max_pq.pop();
	while (!min_pq.empty())
		min_pq.pop();
}
// I : insert D : delete 1 : max -1 : min
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	int num;
	char c;
	cin >> n;
	while (n--) {
		clear(); // 초기화 필수!
		cin >> k;
		for(int i=0;i<k;i++) {
			cin >> c >> num;
			if (c == 'I') {
				max_pq.push({ num,i });
				min_pq.push({ num,i });
				check[i] = true;
			}
			else {	
				if (num == 1) {
					while (!max_pq.empty()&&!check[max_pq.top().second]) {
						max_pq.pop();
					}
					if (!max_pq.empty()) {
						check[max_pq.top().second] = false;
						max_pq.pop();
					}
				}
				else {
					while (!min_pq.empty() && !check[min_pq.top().second]) {
						min_pq.pop();
					}
					if (!min_pq.empty()) {
						check[min_pq.top().second] = false;
						min_pq.pop();
					}
				}
			}
			
		}
		while (!max_pq.empty() && !check[max_pq.top().second]) {
			max_pq.pop();
		}
		while (!min_pq.empty() && !check[min_pq.top().second]) {
			min_pq.pop();
		}
		if (max_pq.empty()) // 비어있는지는 하나만 확인하면 o
			cout << "EMPTY" << "\n";
		else {
			cout << max_pq.top().first << " " << min_pq.top().first << "\n";
		}
	}
	return 0;
}