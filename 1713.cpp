#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

typedef struct {
	int num;
	int cnt;
	int order;
}cndi;

vector <cndi> v;
int od = 0;

bool compareCount(cndi a, cndi b) {
	return a.num < b.num;
}

bool compareOrder(cndi a, cndi b) {
	if (a.cnt == b.cnt) 
		return a.order > b.order;
	else 
		return a.cnt > b.cnt;
}
int n;

void set(int s) {
	cndi a;

	a.num = s;
	a.cnt = 1;
	a.order = ++od;		// set이 실행될때 마다 order ++;
	
	for (int i = 0; i < v.size(); i++) {

		if (v[i].num == a.num) {	// Vector가 비어있지 않을 경우, 이미 있는 후보인지 확인	
			v[i].cnt++;		// 후보의 투표수 ++, order은 업데이트 하지 않는다. 
			return;
		}

	}

	

	if (v.size() >= n) {
		sort(v.begin(), v.end(), compareOrder); // 벡터를 삭제하기 위해 오름차순 정렬
												// 1번 조건 투표받은 수, 2번 조건 등록순서
		v.back().cnt = 0;
		v.pop_back();
		
	}

	v.push_back(a);	// a를 벡터에 삽입
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m, vote;

	cin >> n;
	cin >> m;

	for (int j = 0; j < m; j++) {
		cin >> vote;
		set(vote);
	}

	sort(v.begin(), v.end(), compareCount);

	for (int i=0; i < v.size(); i++)
		cout << v[i].num << " ";
}