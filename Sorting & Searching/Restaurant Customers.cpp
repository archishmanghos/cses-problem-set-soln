#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, X, Y;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<pair<int, int>> A;
	for (int i = 1; i <= N; i++)
	{
		cin >> X >> Y;
		A.push_back({X, 1});
		A.push_back({Y, -1});
	}
	sort(A.begin(), A.end());
	int ans = 0, sum = 0;
	for (auto it : A)
	{
		sum += it.second;
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}

//07-01-2021 00:09:23