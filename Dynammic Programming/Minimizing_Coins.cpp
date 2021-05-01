//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
const double E = 1e-9;
 
//------------------------------------------------------------------------------
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	ll n, x;
	cin >> n >> x;
	vector<ll> coins(n), ans(x + 1, x + 1);
	ans[0]=0;
	for (ll i = 0; i < n; i++)
		cin >> coins[i];
	for (int i = 0; i < n; i++) 
		cin >> coins[i];
	for (int i = 1; i <= x; i++)
		for (int j = 0; j < n; j++)
			if (coins[j] <= i)
				ans[i] = min(ans[i], ans[i - coins[j]] + 1);
	if (ans[x] == x+1)
		cout << -1;
	else
		cout << ans[x];
	return 0;
}
//01-08-2020 12:57:28
//------------------------------------------------------------------------------