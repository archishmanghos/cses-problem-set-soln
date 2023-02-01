#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int INF = 1e9;
vector<int> adj[200200];

int helper(int node, int par, vector<int> &subTree) {
	int subTreeSize = 1;
	for (int child : adj[node]) {
		if (child != par) {
			subTreeSize += helper(child, node, subTree);
		}
	}

	return subTree[node] = subTreeSize;
}

void dfs(int node, int par, int &answer, int n, vector<int> &subTree) {
	vector<int> maxx(2);
	maxx[0] = -INF;
	for (int child : adj[node]) {
		if (child != par) {
			if (subTree[child] > maxx[0]) {
				maxx = {subTree[child], child};
			}
		}
	}

	assert(maxx[0] != -INF);
	if (maxx[0] > (n / 2)) dfs(maxx[1], node, answer, n, subTree);
	else answer = node;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		int U, V; cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	if (N == 1) {
		cout << 1 << '\n';
		return 0;
	}

	vector<int> subTree(N + 2, 0);
	int temp = helper(1, -1, subTree);
	int answer = -1;
	dfs(1, -1, answer, N, subTree);

	cout << answer;
	return 0;
}