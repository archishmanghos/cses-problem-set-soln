#include <bits/stdc++.h>
using namespace std;

class DSU {
	vector<int> size, parent;
	int n, components, maxSize;

	int findParent(int node) {
		if (node == parent[node]) return node;
		return parent[node] = findParent(parent[node]);
	}

public:
	DSU (int n) {
		this->n = n;
		size.assign(n, 1);
		parent.assign(n, 0);
		for (int i = 0; i < n; i++) parent[i] = i;
		components = n;
		maxSize = 1;
	}

	bool unionNode (int u, int v) {
		int pu = findParent(u), pv = findParent(v);
		if (pu == pv) return true;

		components--;
		if (size[pu] >= size[pv]) {
			size[pu] += size[pv];
			maxSize = max(maxSize, size[pu]);
			parent[pv] = pu;
		} else {
			size[pv] += size[pu];
			maxSize = max(maxSize, size[pv]);
			parent[pu] = pv;
		}

		return false;
	}

	pair<int, int> component() {
		return {components, maxSize};
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	DSU dsu(N);

	while (M--) {
		int U, V; cin >> U >> V; U--, V--;
		dsu.unionNode(U, V);
		auto answer = dsu.component();
		cout << answer.first << ' ' << answer.second << '\n';
	}
	return 0;
}