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
	int a[n];
	map<int, int> mp;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> a[i];
		++mp[a[i]];
	}
	for (int i = 1; i <= n; i++)
	{
		if (!mp[i])
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
//30-07-2020 23:54:25
//------------------------------------------------------------------------------