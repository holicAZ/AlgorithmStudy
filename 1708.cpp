#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
// 점의 x와 y좌표를 저장하는 구조체
// x값이 작은 순서대로 정렬, 만약 x값이 동일하다면 y값이 작은 것을 먼저 저장
struct  point{ 
    ll x, y;
    bool operator < (const point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};
vector<point> all_point, convexHull; // 전자는 모든 점, 후자는 컨벡스헐에 해당하는 점

/*
    ccw : 세점이 반시계 방향을 이루는지 체크하는 함수
    a(x,y) b(x,y) c(x,y) ==>    a.x   b.x   c.x   a.x
                                a.y   b.y   c.y   a.y     
                                벡터의 크기를 구한다 
                                (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    벡터의 크기가 = 0  : 세점은 일직선상에 있다
                  < 0  : 세점은 반시계방향을 이룬다
                  > 0  : 세점은 시계방향을 이룬다
*/
int ccw(point a, point b, point c) {
    ll result = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (result == 0) return 0;
    return result < 0 ? -1 : 1;
}
ll dist(point a, point b) { // 길이를 구하는 공식
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
// all_point[0]은 기준점.
// 기준점을 기준은로 두 점이 반시계방향인 순서대로 리턴
// 만약 세점이 일직선 상에 존재한다면 거리가 기준으로 부터 가까운 순으로 리턴
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
    swap(all_point[0], *min_element(all_point.begin(), all_point.end())); // 기준점을 x,y 최소값으로 설정
    // min_element : 벡터 내 최소값을 찾는다.
    sort(all_point.begin() + 1, all_point.end(), comp); // 기준점으로부터 나머지점들을 반시계방향으로 정렬
    
    // make convex_hull
    convexHull.push_back(all_point[0]); // convexhull 벡터에 기준점을 넣는다.
    for (int i = 1; i < n; i++) {
        // 모든 점을 삽입하는 과정에서 새로 push하게 될 점이 반시계 방향을 이루지 않으면
        // == ccw() != 1 이면 마지막으로 push한 점을 pop해준다
        while (convexHull.size() >= 2 && ccw(convexHull[convexHull.size()-2], convexHull.back(), all_point[i]) <= 0)
            convexHull.pop_back();
        
        // all_point 벡터에 정렬되어있는 모든 점들을 convexhull에 넣는다
        convexHull.push_back(all_point[i]);
    }
    // push와 pop의 과정이 끝나고 convexhull에 담겨져 있는 점의 개수를 출력한다.
    cout << convexHull.size();
    return 0;
}