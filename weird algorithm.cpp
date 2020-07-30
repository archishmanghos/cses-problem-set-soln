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
	cout << n << " ";
	while (n > 1)
	{
		if (n & 1)
			n = n * 3 + 1;
		else
			n /= 2;
		cout << n << " ";
	}
	return 0;
}
//30-07-2020 23:53:19
//------------------------------------------------------------------------------