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
int n, a, m;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n >> m;
	vector<int> b(m);
	multiset<int, greater<int>> sa;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sa.insert(a);
	}
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < m; i++)
	{
		auto it = sa.lower_bound(b[i]);
		if (it == sa.end())
			cout << -1 << "\n";
		else
		{
			cout << *it << "\n";
			sa.erase(it);
		}
	}
	return 0;
}
//22-08-2020 11:07:45
//------------------------------------------------------------------------------