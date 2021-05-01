#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, A[mxN];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	int sum = 0, ans1 = -INF, ans2 = -INF;
	for (int i = 1; i <= N; i++)
	{
		if (sum < 0 && A[i] >= 0)
			sum = A[i];
		else
			sum += A[i];
		ans1 = max(ans1, sum);
	}
	sum = 0;
	for (int i = N; i >= 1; i--)
	{
		if (sum < 0 && A[i] >= 0)
			sum = A[i];
		else
			sum += A[i];
		ans2 = max(ans2, sum);
	}
	cout << max(ans1, ans2);
	return 0;
}

//06-01-2021 22:06:07