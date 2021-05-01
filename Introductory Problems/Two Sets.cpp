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
	ll sum = n * (n + 1) / 2;
	if (sum & 1)
		cout << "NO";
	else
	{
		cout << "YES" << "\n";
		if (n & 1)
		{
			vector<int> lowest, highest;
			for (int i = 1, j = n; i < (n + 1) / 2; i++, j--)
			{
				if (i & 1)
				{	lowest.push_back(i);
					highest.push_back(j);
				}
				else
				{
					lowest.push_back(j);
					highest.push_back(i);
				}
			}
			lowest.push_back((n + 1) / 2);
			cout << (n + 1) / 2 << "\n";
			for (auto it : lowest)
				cout << it << " ";
			cout << "\n" << n / 2 << "\n";
			for (auto it : highest)
				cout << it << " ";
		}
		else
		{
			vector<int> lowest, highest;
			for (int i = 1, j = n; i <= n / 2; i++, j--)
			{
				if (i & 1)
				{	lowest.push_back(i);
					lowest.push_back(j);
				}
				else
				{
					highest.push_back(j);
					highest.push_back(i);
				}
			}
			cout << n / 2 << "\n";
			for (auto it : lowest)
				cout << it << " ";
			cout << "\n" << n / 2 << "\n";
			for (auto it : highest)
				cout << it << " ";
		}
	}
	return 0;
}
//31-07-2020 09:41:45
//------------------------------------------------------------------------------