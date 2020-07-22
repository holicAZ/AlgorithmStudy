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
	a.order = ++od;		// set�� ����ɶ� ���� order ++;
	
	for (int i = 0; i < v.size(); i++) {

		if (v[i].num == a.num) {	// Vector�� ������� ���� ���, �̹� �ִ� �ĺ����� Ȯ��	
			v[i].cnt++;		// �ĺ��� ��ǥ�� ++, order�� ������Ʈ ���� �ʴ´�. 
			return;
		}

	}

	

	if (v.size() >= n) {
		sort(v.begin(), v.end(), compareOrder); // ���͸� �����ϱ� ���� �������� ����
												// 1�� ���� ��ǥ���� ��, 2�� ���� ��ϼ���
		v.back().cnt = 0;
		v.pop_back();
		
	}

	v.push_back(a);	// a�� ���Ϳ� ����
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