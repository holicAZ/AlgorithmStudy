#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int card[500000];

int lowerBound(int n)
{
	int s = 0, e = N - 1, mid;
	while(s<e)
	{
		mid = (s + e) / 2;

		if (card[mid] >= n) e = mid;
		else s = mid + 1;
	}
	return e;
}

int upperBound(int n)
{
	int s = 0, e = N - 1, mid;
	while(s<e)
	{
		mid = (s + e) / 2;

		if (card[mid] <= n) s = mid + 1;
		else e = mid;
	}
	return e;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> card[i];
	sort(card, card + N);

	cin >> M;
	int n;
	for (int i = 0; i < M; i++)
	{
		cin >> n;
		
		int low = lowerBound(n);
		int up = upperBound(n);

		if (up == N - 1 && n == card[N - 1])
			up++;
		cout << up - low << " ";
	}

	return 0;
}