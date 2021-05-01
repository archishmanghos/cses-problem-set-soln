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
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			cnt += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}
	cout << cnt;
	return 0;
}
//30-07-2020 23:57:46
//------------------------------------------------------------------------------ḍ