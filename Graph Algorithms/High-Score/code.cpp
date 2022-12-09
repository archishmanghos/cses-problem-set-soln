#include <bits/stdc++.h>
#define int long long
const int INF = 1e17;
const int NINF = -1e17;
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> edges(m);
	vector<int> dist(n, INF);
	for (int i = 0; i < m; i++) {
		int u, v, wt; cin >> u >> v >> wt;
		edges[i] = {u - 1, v - 1, -wt};
	}

	dist[0] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (auto e : edges) {
			int u = e[0], v = e[1], wt = e[2];
			if (dist[u] == INF) {
				continue;
			}

			dist[v] = min(dist[v], dist[u] + wt);
			dist[v] = max(dist[v], NINF);
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (auto e : edges) {
			int u = e[0], v = e[1], wt = e[2];
			if (dist[u] == INF) {
				continue;
			}

			dist[v] = max(dist[v], NINF);
			if (dist[v] > dist[u] + wt) {
				dist[v] = NINF;
			}
		}
	}

	cout << (dist[n - 1] == NINF ? -1 : -dist[n - 1]);
	return 0;
}