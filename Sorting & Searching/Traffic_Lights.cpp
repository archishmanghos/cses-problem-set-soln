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
int x, n;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> x >> n;
	set<int> s = {0, x};
	multiset<int> ms = {x};
	vector<int> p(n, 0);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
	{
		auto it = s.upper_bound(p[i]);
		auto temp = it;
		int left = *(--temp);
		int right = *it;
		ms.erase(ms.find(right - left));
		ms.insert(p[i] - left);
		ms.insert(right - p[i]);
		s.insert(it, p[i]);
		cout << *ms.rbegin() << " ";
	}
	return 0;
}
//22-08-2020 21:21:20
//------------------------------------------------------------------------------