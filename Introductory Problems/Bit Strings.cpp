//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e9 + 7;
const double E = 1e-9;

//------------------------------------------------------------------------------

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	int n;
	cin >> n;
	ll ans = 1;
	for (int i = 1; i <= n; i++)
		ans = ((ans % N) * 2) % N;
	cout << ans;
	return 0;
}
//31-07-2020 10:00:16
//------------------------------------------------------------------------------