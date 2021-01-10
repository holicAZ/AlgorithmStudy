#include<iostream>
#include<cmath>
#include <algorithm>
#define MAX 1501
using namespace std;

typedef long long ll;

typedef struct point { // �ܼ��� ���� ������ �����ϴ� �ڷ���
	int x, y;

	bool operator==(const point& nxt) const {
		return (x == nxt.x && y == nxt.y);
	}
}point;

typedef struct PtoPdist {
	point a, b;
	ll dist;
}PtoPdist;

bool compare(PtoPdist& p1, PtoPdist& p2) {
	if (p1.dist == p2.dist) return (p1.a.x + p1.b.x) < (p2.a.x + p2.b.x);
	else return p1.dist < p2.dist;
}

point arr[MAX]; // ���� ������ �����ϴ� �迭
PtoPdist arr_d[3000000];

ll get_dist(point a, point b) {
	return (ll) (a.x - b.x)*(a.x - b.x) + (ll) (a.y - b.y)*(a.y - b.y);  // ���� ���� ���� ���ϴ� �Լ�
}

double get_dist2(point a, point b) {
	return (double)(sqrt((double) (a.x - b.x) * (a.x - b.x) + (double) (a.y - b.y) * (a.y - b.y)+1e-5));
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) { // ���� ������ ����
		cin >> arr[i].x >> arr[i].y;
	}

	int z = 0;

	for (int i = 0; i < n; i++) { // ���� ������ �Ÿ��� ����
		for (int k = i + 1; k < n; k++) {
			arr_d[z] = { arr[i], arr[k], get_dist(arr[i],arr[k]) };
			z++;
		}
	}

	sort(arr_d, arr_d + z, compare); // ���̰� �� �밢�� ���� �� �� �ְ� ���� ���ش�.
	double ans = -1;
	double tmp;

	//(a.x - b.x)* (a.x - b.x) + (ll)(a.y - b.y)* (a.y - b.y)
	for (int i = 0; i < z; i++) {
		for (int k = i + 1; k < z; k++) {
			if (arr_d[i].a == arr_d[k].a || 
				arr_d[i].a == arr_d[k].b || 
				arr_d[i].b == arr_d[k].a || 
				arr_d[i].b == arr_d[k].b) continue;

			//if ((arr_d[i].a.x + arr_d[i].b.x) != (arr_d[k].a.x + arr_d[k].b.x) || (arr_d[i].a.y + arr_d[i].b.y) != (arr_d[k].a.y + arr_d[k].b.y)) continue;
			if (arr_d[i].dist != arr_d[k].dist ||
				(arr_d[i].a.x + arr_d[i].b.x) != (arr_d[k].a.x + arr_d[k].b.x)) break;

			if ((arr_d[i].a.y + arr_d[i].b.y) == (arr_d[k].a.y + arr_d[k].b.y)) {
				tmp = get_dist2(arr_d[i].a, arr_d[k].a) * get_dist2(arr_d[i].a, arr_d[k].b)+(1e-5); 
				if (ans < tmp) ans = tmp;
			}
		}
	}
	printf("%.0lf", ans);
	return 0;
}


