#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, Q, A[mxN], Q1, Q2;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	int prefix_sum[N + 5];

	prefix_sum[1] = A[1];

	for (int i = 2; i <= N; i++)
		prefix_sum[i] = A[i] + prefix_sum[i - 1];

	while (Q--)
	{

		cin >> Q1 >> Q2;

		int x = prefix_sum[Q2];
		int y = (Q1 > 1 ? prefix_sum[Q1 - 1] : 0);

		cout << x - y << '\n';

	}

	return 0;
}

//09-04-2021 09:37:51