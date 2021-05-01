#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 2e6 + 5;
const int INF = 1e18 + 7;
 
int T, n;
bool prime[mxN];
 
void soe(int N)
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= N; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= N; j += i)
				prime[j] = false;
		}
	}
}
 
void solve()
{
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		if (prime[i])
		{
			if (i * i * i > n)
				break;
			int cnt = 1;
			while (n % i == 0)
			{
				n /= i;
				++cnt;
			}
			ans *= cnt;
		}
	}
	if (prime[n])
		ans *= 2;
	else
	{
		int sq = sqrt(n);
		if (sq * sq == n && prime[sq])
			ans *= 3;
		else if (n != 1)
			ans *= 4;
	}
	cout << ans << "\n";
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	soe(1000005);
	cin >> T;
	while (T--)
		solve();
	return 0;
}
//25-09-2020 21:48:59