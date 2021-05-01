//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e6 + 5;
const double E = 1e-9;

//------------------------------------------------------------------------------

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		ll a = i * i * (i * i - 1) / 2;
		ll b = 2 * (i - 2) * (2 * (i - 4) + 6);
		cout << a - b << "\n";
	}
	return 0;
}
//31-07-2020 00:02:15
//------------------------------------------------------------------------------