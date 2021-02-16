#include<iostream>
using namespace std;
int dp[1001];
int arr[1001];
int MAX = 1;
int main(void) {
	int n;
	scanf("%d",&n);
	fill(dp + 1, dp + n, 1);
	for (int i = 1; i<=n; i++) {
		scanf("%d", &arr[i]);
		for (int k = 1; k < i; k++) {
			if (arr[i] > arr[k]) {
				dp[i] = max(dp[i], dp[k] + 1);
			}
		}
		MAX = max(MAX, dp[i]);
	}
	printf("%d", MAX);
}