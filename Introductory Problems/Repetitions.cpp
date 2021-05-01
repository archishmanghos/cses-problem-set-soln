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
	string s;
	cin >> s;
	int ans = 0, cnt = 1;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
			++cnt;
		else
		{
			ans = max(ans, cnt);
			cnt = 1;
		}
	}
	ans = max(ans, cnt);
	cout << ans;
	return 0;
}
//30-07-2020 23:56:24
//------------------------------------------------------------------------------