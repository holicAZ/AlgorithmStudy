#include <iostream>
#define N 11
using namespace std;

class Trie { // TRIE �˰���
private : 
	Trie* word[N];
	bool terminal; // �ܾ ������ ������ üũ�ϴ� ����

public:
	Trie() { // �ʱ�ȭ
		fill(word, word + N, nullptr);
		terminal = 0;
	}
	~Trie() { // �Ҹ���
		for (int i = 0; i < N; i++)
			if (word[i])
				delete word[i];
	}

	void insert(char* currWord) { // �ܾ �����ϴ� �Լ�
		if (*currWord == '\0') { // �ܾ ������ 
			terminal = true; // ������ �����̶� ���� ǥ��
		}
		else {
			int currNum = *currWord - '0'; // index ��ȣ�� �����Ѵ�. �ʱ� ���۰��� 0�� ���ش�
			if (word[currNum] == nullptr)
				word[currNum] = new Trie();
			word[currNum]->insert(currWord+1);
		}
	}

	bool find(char* currWord) { // ��ȣ�� �ִ��� ã�� �Լ�
		if (*currWord == 0) return true;
		if (terminal==true) return false; // ��޹�ȣ�� ���λ�� ������ false ��ȯ
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
		bool flag = true;  // �ϰ��� �˻� �ϴ� ����
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