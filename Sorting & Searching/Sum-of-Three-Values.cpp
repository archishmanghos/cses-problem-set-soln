#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debugarr(x,i,j) cerr << #x <<" "; _print(x,i,j); cerr << endl;
#else
#define debugarr(x)
#endif

void _print(int t){cerr << t;}
void _print(string t){cerr << t;}
void _print(bool t){cerr << t;}
void _print(char t){cerr << t;}
void _print(long double t){cerr << t;}
void _print(double t){cerr << t;}
void _print(unsigned long long t){cerr << t;}
template <class T> void _print(T arr[], int i, int j){cerr << "[ " ;for ( int k = i; k <= j; k++) cerr << arr[k] << ", " ;cerr << "]\n";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr << "{";_print(p.first);cerr << ",";_print(p.second);cerr << "}";}
template <class T> void _print(vector <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}

int N, target;
vector<pair<int, int>> A(mxN);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> target;
	for(int i = 1; i <= N; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin() + 1, A.begin() + N + 1);
	vector<int> ans;
	bool found = false;
	for(int i = 1; i < N - 1; i++)
	{
		int j = i + 1, k = N, rem = target - A[i].first;
		while(j < k)
		{
			int sum = A[j].first + A[k].first;
			if(sum == rem)
			{
				ans.push_back(A[i].second);
				ans.push_back(A[j].second);
				ans.push_back(A[k].second);
				found = true;
				break;
			}
			else if(sum > rem)
				k -= 1;
			else
				j += 1;
		}
		if(found)
			break;
	}

	if(found)
	{
		sort(ans.begin(), ans.end());
		for(int i : ans)
			cout << i << ' ';
	}
	else
		cout << "IMPOSSIBLE";

    return 0;
}