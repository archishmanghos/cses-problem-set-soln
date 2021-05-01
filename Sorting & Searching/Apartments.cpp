//Practice
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
const ll INF = 1e9 + 5;
const ll mxN = 1000000007;
const double E = 1e-9;

//------------------------------------------------------------------------------
int n, m, k, a, b;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n >> m >> k;
	multiset<int> sa, sb;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sa.insert(a - k);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b;
		sb.insert(b);
	}
	int ans = 0;
	for (auto it : sa)
	{
		if (sb.lower_bound(it) == sb.end())
			continue;
		else
		{
			if (*sb.lower_bound(it) - it <= 2 * k)
			{
				sb.erase(sb.lower_bound(it));
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}
//21-08-2020 11:25:38
//------------------------------------------------------------------------------