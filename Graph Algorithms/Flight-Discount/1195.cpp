#include <bits/stdc++.h>
#define int long long
const int INF = 1e18;
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<vector<int>>> adj(n + 1);

	for (int i = 1; i <= m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		u--, v--;
		adj[u].push_back({v, wt});
	}

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0, 0, 0});
	int distance[n][2];
	for (int i = 0; i < n; i++) {
		if (i == 0) distance[i][0] = distance[i][1] = 0;
		else distance[i][0] = distance[i][1] = INF;
	}

	while (!pq.empty()) {
		auto it = pq.top(); pq.pop();
		int discountUsed = it[2], dist = it[0], node = it[1];
		if (distance[node][discountUsed] < dist) continue;
		for (auto child : adj[node]) {
			if (discountUsed) {
				if (distance[child[0]][1] > dist + child[1]) {
					distance[child[0]][1] = dist + child[1];
					pq.push({distance[child[0]][1], child[0], 1});
				}
			} else {
				if (distance[child[0]][0] > dist + child[1]) {
					distance[child[0]][0] = dist + child[1];
					pq.push({distance[child[0]][0], child[0], 0});
				}
				if (distance[child[0]][1] > dist + (child[1] / 2)) {
					distance[child[0]][1] = dist + (child[1] / 2);
					pq.push({distance[child[0]][1], child[0], 1});
				}
			}
		}
	}

	cout << distance[n - 1][1];
	return 0;
}