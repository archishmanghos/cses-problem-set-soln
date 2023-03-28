#include <bits/stdc++.h>
using namespace std;

class DSU {
	vector<int> size, parent;
	int n, components;

	int findParent(int node) {
		if (node == parent[node]) return node;
		return parent[node] = findParent(parent[node]);
	}

public:
	DSU (int n) {
		this->n = n;
		size.assign(n, 1);
		parent.assign(n, 0);
		components = 1;
		for (int i = 0; i < n; i++) parent[i] = i;
	}

	bool unionNode (int u, int v) {
		int pu = findParent(u), pv = findParent(v);
		if (pu == pv) return false;

		components++;
		if (size[pu] >= size[pv]) {
			size[pu] += size[pv];
			parent[pv] = pu;
		} else {
			size[pv] += size[pu];
			parent[pu] = pv;
		}

		return true;
	}

	bool allConnected() {
		return components == n;
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	DSU dsu(N);
	vector<vector<int>> edges(M, vector<int>(3));
	for (int i = 0; i < M; i++) {
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
		edges[i][1]--, edges[i][2]--;
	}

	sort(edges.begin(), edges.end());
	int64_t mstCost = 0;
	for (int i = 0; i < M; i++) {
		if (dsu.unionNode(edges[i][1], edges[i][2])) mstCost += edges[i][0];
	}

	if (dsu.allConnected()) cout << mstCost;
	else cout << "IMPOSSIBLE";
	return 0;
}