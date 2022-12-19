#include <bits/stdc++.h>
using namespace std;

const int mxn = 500500;
const int LOG = 19;
int parent[mxn], up[mxn][LOG], depth[mxn];
vector<int> adj[mxn];

void dfs(int node) {
	up[node][0] = parent[node];
	for (int j = 1; j < LOG; j++) {
		if (up[node][j - 1] != -1) up[node][j] = up[up[node][j - 1]][j - 1];
		else up[node][j] = -1;
	}

	for (int child : adj[node]) {
		if (child != parent[node]) {
			depth[child] = depth[node] + 1;
			dfs(child);
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q; cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> parent[i];
		adj[parent[i]].push_back(i);
	}
	parent[1] = -1;

	memset(depth, 0, (n + 1) * sizeof(int));
	dfs(1);

	while (q--) {
		int u, v; cin >> u >> v;

		if (depth[u] < depth[v]) swap(u, v);
		int k = depth[u] - depth[v];
		for (int i = 0; i < LOG; i++) {
			if ((k >> i) & 1) {
				u = up[u][i];
			}
		}

		if (u == v) {
			cout << u << '\n';
			continue;
		}

		for (int i = LOG - 1; i >= 0; i--) {
			int nu = up[u][i], nv = up[v][i];
			if (nu != nv) {
				u = nu, v = nv;
			}
		}

		cout << up[u][0] << '\n';
	}

	return 0;
}