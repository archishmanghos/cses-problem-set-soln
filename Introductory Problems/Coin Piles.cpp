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
	ll t;
	cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
		if ((a + b) % 3 == 0 && max(a, b) - min(a, b) <= min(a, b))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}
//31-07-2020 11:10:44
//------------------------------------------------------------------------------