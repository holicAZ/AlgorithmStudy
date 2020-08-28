#include <iostream>
#define N 11
using namespace std;

class Trie { // TRIE 알고리즘
private : 
	Trie* word[N];
	bool terminal; // 단어가 끝나는 지점을 체크하는 변수

public:
	Trie() { // 초기화
		fill(word, word + N, nullptr);
		terminal = 0;
	}
	~Trie() { // 소멸자
		for (int i = 0; i < N; i++)
			if (word[i])
				delete word[i];
	}

	void insert(char* currWord) { // 단어를 삽입하는 함수
		if (*currWord == '\0') { // 단어가 끝나면 
			terminal = true; // 끝나는 지점이란 것을 표시
		}
		else {
			int currNum = *currWord - '0'; // index 번호를 설정한다. 초기 시작값인 0을 빼준다
			if (word[currNum] == nullptr)
				word[currNum] = new Trie();
			word[currNum]->insert(currWord+1);
		}
	}

	bool find(char* currWord) { // 번호가 있는지 찾는 함수
		if (*currWord == 0) return true;
		if (terminal==true) return false; // 긴급번호가 접두사로 가지면 false 반환
		int next = *currWord - '0';
		return word[next]->find(currWord + 1);
	}
};
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		Trie* root = new Trie();
		bool flag = true;  // 일관성 검사 하는 변수
		char number [10001][N];
		for (int i = 0; i < n; i++) {
			cin >> number[i];
		}
		for (int i = 0; i < n; i++) {
			root->insert(number[i]);
		}
		for (int i = 0; i < n; i++) {
			if (flag) flag = root->find(number[i]);
			if (!flag) break;
		}
		string s;
		if (flag) s = "YES";
		else s = "NO";

		cout << s << "\n";
		root->~Trie();
	}
	return 0;
}