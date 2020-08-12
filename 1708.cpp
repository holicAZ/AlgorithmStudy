#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
// ���� x�� y��ǥ�� �����ϴ� ����ü
// x���� ���� ������� ����, ���� x���� �����ϴٸ� y���� ���� ���� ���� ����
struct  point{ 
    ll x, y;
    bool operator < (const point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};
vector<point> all_point, convexHull; // ���ڴ� ��� ��, ���ڴ� �������濡 �ش��ϴ� ��

/*
    ccw : ������ �ݽð� ������ �̷���� üũ�ϴ� �Լ�
    a(x,y) b(x,y) c(x,y) ==>    a.x   b.x   c.x   a.x
                                a.y   b.y   c.y   a.y     
                                ������ ũ�⸦ ���Ѵ� 
                                (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    ������ ũ�Ⱑ = 0  : ������ �������� �ִ�
                  < 0  : ������ �ݽð������ �̷��
                  > 0  : ������ �ð������ �̷��
*/
int ccw(point a, point b, point c) {
    ll result = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (result == 0) return 0;
    return result < 0 ? -1 : 1;
}
ll dist(point a, point b) { // ���̸� ���ϴ� ����
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
// all_point[0]�� ������.
// �������� �������� �� ���� �ݽð������ ������� ����
// ���� ������ ������ �� �����Ѵٸ� �Ÿ��� �������� ���� ����� ������ ����
bool comp(point a, point b) {
    if (ccw(all_point[0], a, b) != 0) {
        return ccw(all_point[0], a, b) > 0;
    }
    else if (ccw(all_point[0], a, b) == 0) {
        return dist(all_point[0], a) < dist(all_point[0], b);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    ll a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        point c;
        cin >> a >> b;
        c.x = a;
        c.y = b;
        all_point.push_back(c);
    }
    swap(all_point[0], *min_element(all_point.begin(), all_point.end())); // �������� x,y �ּҰ����� ����
    // min_element : ���� �� �ּҰ��� ã�´�.
    sort(all_point.begin() + 1, all_point.end(), comp); // ���������κ��� ������������ �ݽð�������� ����
    
    // make convex_hull
    convexHull.push_back(all_point[0]); // convexhull ���Ϳ� �������� �ִ´�.
    for (int i = 1; i < n; i++) {
        // ��� ���� �����ϴ� �������� ���� push�ϰ� �� ���� �ݽð� ������ �̷��� ������
        // == ccw() != 1 �̸� ���������� push�� ���� pop���ش�
        while (convexHull.size() >= 2 && ccw(convexHull[convexHull.size()-2], convexHull.back(), all_point[i]) <= 0)
            convexHull.pop_back();
        
        // all_point ���Ϳ� ���ĵǾ��ִ� ��� ������ convexhull�� �ִ´�
        convexHull.push_back(all_point[i]);
    }
    // push�� pop�� ������ ������ convexhull�� ����� �ִ� ���� ������ ����Ѵ�.
    cout << convexHull.size();
    return 0;
}