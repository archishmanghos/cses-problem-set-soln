#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;
 
int N, X;
vector<pair<int, int>> A(mxN);
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> X;
	map<int, int> mp;
	map<int, int> index;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
		++mp[A[i].first];
		index[A[i].first] = i;
	}
	sort(A.begin() + 1, A.begin() + N + 1);
	for (int i = 1; i <= N; i++)
	{
		if (mp[X - A[i].first])
		{
			if (X - A[i].first == A[i].first && mp[X - A[i].first] > 1)
			{
				if (i > 1 && A[i].first == A[i - 1].first)
					cout << min(A[i].second, A[i - 1].second) << ' ' << max(A[i].second, A[i - 1].second);
				else if (i < N && A[i + 1].first == A[i].first)
					cout << min(A[i].second, A[i + 1].second) << ' ' << max(A[i].second, A[i + 1].second);
			}
			else if (X - A[i].first != A[i].first)
				cout << min(A[i].second, index[X - A[i].first]) << ' ' << max(A[i].second, index[X - A[i].first]);
			else
				continue;
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
 
//06-01-2021 21:56:54