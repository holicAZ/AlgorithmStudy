#include <iostream>
using namespace std;


int confirm(int over, int n) {
	int t;
	t = over - n;
	return t;
}

void init() { // �ð� �������ִ� �ҽ��ڵ�
			  // ���ʿ��� ����� �Լ��� ������ �����ش�.
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main(void) {
	init();

	int temp, a, b;
	int over;
	int sum = 0;
	int arr[9];
	bool check = false;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	over = sum - 100;

	for (int j = 8; j >= 0; j--) {
		temp = confirm(over,arr[j]);
		for (int k = 0; k < j; k++) {
			if (arr[k] == temp) {
				a = j;
				b = k;
				check = true;
				break;
			}
		}
		if (check == true)
			break;
	}
	arr[a] = 100;
	arr[b] = 100;
	for (int j = 0; j < 9; j++) {
		for (int k = j + 1; k < 9; k++) {
			if (arr[j] > arr[k]) {
				temp = arr[k];
				arr[k] = arr[j];
				arr[j] = temp;
			}
		}
		if(arr[j]<100)
		cout << arr[j] << "\n";
	}
	
}