#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool field[25][25];
int n, cnt = 0, total = 0;
vector <int> v;

void chain(int x, int y) {
	cnt++;	// 실행된다는 것은 단지내 집의 수 ++
	if (x < n - 1 && field[x+1][y]) {		// 하
		field[x][y] = 0;
		chain(x + 1, y);
	}
	if (x - 1 >= 0 && field[x - 1][y]) {	// 상
		field[x][y] = 0;
		chain(x - 1, y);
	}
	if (y < n - 1 && field[x][y + 1]) {		//우
		field[x][y] = 0;
		chain(x, y + 1);
	}
	if (y - 1 >= 0 && field[x][y - 1]) {	//좌
		field[x][y] = 0;
		chain(x, y - 1);
	}
	else {									// 상 하 좌 우 모두 0
		field[x][y] = 0;
		return;
	}
}

void check() {

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (field[x][y]) {
				cnt = 0;	// 단지 내 집의 수 초기화
				total++;	// 단지의 수 ++
				chain(x, y);
				v.push_back(cnt); // 정렬을 위해 집의 수 (cnt) 를 벡터에 삽입
			}
		}
	}
	sort(v.begin(), v.end()); // 내림차순 정렬
	
	cout << total << "\n";
	for(int a : v)
		cout << a << "\n";
}

bool cast(char c) {	// char to bool
	if (c == '1')
		return true;
	else if (c == '0')
		return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;

	memset(field, false, sizeof(field));
	char c;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;	// string 타입으로 입력
		for (int j = 0; j < n; j++) {
			field[i][j] = cast(s.at(j)); // char로 쪼개서 bool타입으로 캐스팅 후 저장
		}
	}
	
	check();
}
