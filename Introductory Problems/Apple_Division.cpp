//Practice
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 25;
const ll INF = 1e9 + 5;
const ll mxN = 1000000007;
const double E = 1e-9;
 
//------------------------------------------------------------------------------
int n, a[N];
ll rec(ll i, ll sum, ll tsum)
{
	if (!i)
		return abs(tsum - 2 * sum);
	return min(rec(i - 1, sum + a[i - 1], tsum),
	           rec(i - 1, sum, tsum));
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n;
	ll t_sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		t_sum += a[i];
	}
	ll ans = rec(n, 0, t_sum);
	cout << ans;
	return 0;
}
//20-08-2020 18:50:54
//-----------------------------------------------------------------------