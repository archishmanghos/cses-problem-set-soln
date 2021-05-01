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
	if (n > 1 && n < 4)
	{
		cout << "NO SOLUTION";
		return 0;
	}
	if (n == 4)
	{
		cout << "3 1 4 2";
		return 0;
	}
	for (ll i = 1; i <= n; i += 2)
		cout << i << " ";
	for (int i = 2; i <= n; i += 2)
		cout << i << " ";
	return 0;
}
//30-07-2020 23:59:08
//------------------------------------------------------------------------------