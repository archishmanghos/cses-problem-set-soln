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

int N, M, U, V, parent[mxN];
bool visited[mxN];
vector<int> adj[mxN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M;
	for(int i = 1; i <= M; i++)
	{
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	queue<int> q;
	memset(visited, false, sizeof(visited));
	memset(parent, -1, sizeof(parent));
	bool path = false;
	q.push(1);
	visited[1] = true;

	while(!q.empty())
	{
		int node = q.front();
		q.pop();

		for(int i : adj[node])
		{
			if(visited[i])
				continue;
			visited[i] = true;
			if(parent[i] == -1)
				parent[i] = node;
			if(i == N)
			{
				path = true;
				break;
			}
			q.push(i);
		}
		if(path)
			break;
	}

	if(path)
	{
		vector<int> ans;
		int node = N;
		while(parent[node] != -1)
		{
			ans.push_back(node);
			node = parent[node];
		}
		ans.push_back(1);
		reverse(ans.begin(), ans.end());

		cout << ans.size() << '\n';
		for(int i : ans)
			cout << i << ' ';
	}
	else
		cout << "IMPOSSIBLE";

    return 0;
}