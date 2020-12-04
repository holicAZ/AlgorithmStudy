#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int llt;

vector<llt> v;
vector<llt> divisor;
llt GCD(llt a, llt b) {
	return b ? GCD(b, a % b) : a;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, c;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());	// 오름차순 정렬을 해준다.

	for (int i = 1; i < n; i++) {
		v[i-1] = v[i] - v[i-1]; // 큰수에서 작은수를 빼서 작은 인덱스에 넣는다.
	}
	
	for (int i = 1; i < n-1; i++) { // 위의 빼는 연산은 총 수의 개수의 -1 만큼 실행
		v[i] = GCD(v[i - 1], v[i]);
	}
	llt a = v[n-2]; // GCD는 v의 최대 인덱스의 -2에 저장
	//최대 공약수의 약수를 모두 구한다.
	for (int i = 1; i * i <= a; i++) { 
		if (a % i == 0) {	// 약수를 벡터에 삽입
			divisor.push_back(i);
			if (i == a / i) continue; // 나누는 수와 몫이 같으면 하나만 삽입
			divisor.push_back(a / i);
		}
	}
	sort(divisor.begin(), divisor.end());

	for (int i = 1; i < divisor.size(); i++) { // 1보다 크다는 조건때문에 인덱스는 1부터 시작
		cout << divisor[i] << " ";
	}
	return 0;
}