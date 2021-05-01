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
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 5; i <= n; i *= 5)
		ans += n / i;
	cout << ans;
	return 0;
}
//31-07-2020 10:18:39
//------------------------------------------------------------------------------