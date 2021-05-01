#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;
 
int n, x, a[mxN];
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = n;
	for (int i = 1, j = n; i < j; )
	{
		if (a[i] + a[j] <= x)
		{
			++i;
			--j;
			--ans;
		}
		else
			--j;
	}
	cout << ans;
	return 0;
}
 
//25-11-2020 18:28:36