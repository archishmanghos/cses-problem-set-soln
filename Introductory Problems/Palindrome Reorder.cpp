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
	map<char, int> mp;
	for (auto it : s)
		++mp[it];
	if (s.size() & 1)
	{
		int odd = 0, even = 0;
		for (auto it : mp)
		{
			odd += (it.second & 1);
			even += (it.second % 2 == 0 && it.second != 0);
		}
		if (odd == 1)
		{
			vector<char> soja, ulto;
			sort(s.begin(), s.end());
			for (int i = 0; i < s.size(); i++)
			{
				if (mp[s[i]] & 1)
					continue;
				else
				{
					for (int j = 1; j <= mp[s[i]] / 2; j++)
					{
						soja.push_back(s[i]);
						ulto.push_back(s[i]);
					}
					i += mp[s[i]] - 1;
				}
			}
			for (auto it : mp)
			{
				if (it.second & 1)
				{
					for (int i = 1; i <= (it.second + 1) / 2; i++)
						soja.push_back(it.first);
					for (int i = 1; i <= it.second / 2; i++)
						ulto.push_back(it.first);
				}
			}
			reverse(ulto.begin(), ulto.end());
			for (auto it : soja)
				cout << it;
			for (auto it : ulto)
				cout << it;
		}
		else
		{
			cout << "NO SOLUTION";
			return 0;
		}
	}
	else
	{
		int odd = 0, even = 0;
		for (auto it : mp)
		{
			odd += (it.second & 1);
			even += (it.second % 2 == 0 && it.second != 0);
		}
		if (odd == 0)
		{
			vector<char> soja, ulto;
			sort(s.begin(), s.end());
			for (int i = 0; i < s.size(); i++)
			{
				for (int j = 1; j <= mp[s[i]] / 2; j++)
				{
					soja.push_back(s[i]);
					ulto.push_back(s[i]);
				}
				i += mp[s[i]] - 1;
			}
			reverse(ulto.begin(), ulto.end());
			for (auto it : soja)
				cout << it;
			for (auto it : ulto)
				cout << it;
		}
		else
		{
			cout << "NO SOLUTION";
			return 0;
		}
	}
	return 0;
}
//31-07-2020 11:37:42
//------------------------------------------------------------------------------