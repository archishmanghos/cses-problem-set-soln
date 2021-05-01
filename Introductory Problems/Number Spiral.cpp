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
	int t;
	cin >> t;
	while (t--)
	{
		ll x, y;
		cin >> x >> y;
		if (x < y)
			cout << (y & 1 ? y * y - x + 1 : (y - 1) * (y - 1) + x ) << "\n";
		else
			cout << (x & 1 ? (x - 1) * (x - 1) + y : x * x - y + 1 ) << "\n";
	}
	return 0;
}
//31-07-2020 00:00:55
//------------------------------------------------------------------------------