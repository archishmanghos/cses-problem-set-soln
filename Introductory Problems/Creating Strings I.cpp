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
	sort(s.begin(), s.end());
	vector<string> v;
	v.push_back(s);
	while (next_permutation(s.begin(), s.end()))
		v.push_back(s);
	cout << v.size() << "\n";
	for (auto it : v)
		cout << it << "\n";
	return 0;
}
//31-07-2020 11:42:36
//------------------------------------------------------------------------------