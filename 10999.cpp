#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n, m, k;
llt seg[1 << 21];
llt lazy[1 << 21];

void update_lazy(int node, int start, int end) {
	if (!lazy[node]) return; // 업데이트 요청이 없으면 종료

	// 업데이트 요청이 저장되어 있으면 실행

	seg[node] += (end - start + 1) * lazy[node]; // 노드의 값을 저장해 준다.

	if (start != end) {	// 리프 노드가 아니라면 자식으로 업데이트 요청을 전파
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	lazy[node] = 0;	// 업데이트 값을 처리 했으므로 초기화한다.
	return;

}

void update(int node, int start, int end, int left, int right, llt v) {
	
	update_lazy(node, start, end); // 업데이트 해 줄때 마다 레이지에 값이 있는지 확인 해주는 역할

	if (left > end || right < start) return;

	if (left <= start && end <= right) {
		seg[node] += (end - start + 1) * v;
		
		if (start != end) {
			lazy[node * 2] += v;
			lazy[node * 2 + 1] += v;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, v);
	update(node * 2 + 1, mid+1, end, left, right, v);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

llt query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	// update 이후 남은 lazy를 sum 할 때 없데이트 해줘야한다.
	if (end < left || right < start)return 0;
	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;  // == >> 1
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	const int sz = pow(2, (int)log2(n - 1) + 1);
	for (int i = 0; i < n; i++) cin >> seg[sz + i];
	for (int i = sz - 1; i > 0; i--) seg[i] = seg[i * 2] + seg[i * 2 + 1];
	
	int a, b, c, d;
	for(int i=0;i<m+k;i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, 1, sz, b, c, d);
		}
		else {
			cin >> b >> c;
			cout << query(1, 1, sz, b, c) << "\n";
		}
	}
	
	return 0;
}