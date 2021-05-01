//Practice
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 205;
const ll INF = 1e9 + 5;
const ll mxN = 1000000007;
const double E = 1e-9;

//------------------------------------------------------------------------------
int n;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	++dp[0];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (i >= j)
				dp[i] = ((dp[i] % mxN) + (dp[i - j] % mxN)) % mxN;
		}
	}
	cout << dp[n];
	return 0;
}
//20-08-2020 17:42:50
//------------------------------------------------------------------------------