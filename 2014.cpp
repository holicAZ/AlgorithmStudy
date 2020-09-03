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
		cin >> arr[i];  // �⺻ �Ҽ��� ����
		pq.push(arr[i]); // �Ҽ��� ���� ����
	}
	
	int cnt = 1; // ī��Ʈ ���° �Ҽ����� Ȯ��
	ll top;
	while (true) {
		top = pq.top();
		pq.pop(); // ���� ���� �� pop
		if (cnt == n) break;
		else {
			for (int i = 0; i < k; i++) {	// �Է¹��� �Ҽ��� ���� �켱���� ť�� ����
				ll a = top * arr[i]; // �Ҽ��� ���� �⺻�Ҽ��� ���ؼ� push
				pq.push(a);
				if (top % arr[i]==0) break; // �ߺ��Ǵ� �Ҽ��� ���� ����
			}
			cnt++;
		}
	} // cnt == k �� �ɶ� ���� �ݺ�
	cout << top;
	return 0;
}