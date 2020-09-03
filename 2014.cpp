#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
priority_queue < ll, vector <ll> , greater<ll> > pq;
int arr[100];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int c;
		cin >> arr[i];  // 기본 소수를 저장
		pq.push(arr[i]); // 소수의 곱을 저장
	}
	
	int cnt = 1; // 카운트 몇번째 소수인지 확인
	ll top;
	while (true) {
		top = pq.top();
		pq.pop(); // 제일 작은 수 pop
		if (cnt == n) break;
		else {
			for (int i = 0; i < k; i++) {	// 입력받은 소수의 곱을 우선순위 큐에 저장
				ll a = top * arr[i]; // 소수의 곱과 기본소수를 곱해서 push
				pq.push(a);
				if (top % arr[i]==0) break; // 중복되는 소수의 곱은 생략
			}
			cnt++;
		}
	} // cnt == k 가 될때 까지 반복
	cout << top;
	return 0;
}