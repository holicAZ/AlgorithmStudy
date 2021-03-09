#include<iostream>
#include<algorithm>

using namespace std;
int arr[1000];

int main(void) {
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	int sum = 0;
	for (int i = n; i >= 1; i--) {
		sum += (arr[n-i] * i);
		
	}
	cout << sum;
	return 0;
}