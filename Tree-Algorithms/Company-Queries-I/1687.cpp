#include <bits/stdc++.h>
using namespace std;

const int mxn = 500500;
const int LOG = 19;
int parent[mxn], up[mxn][LOG];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q; cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> parent[i];
	}

	up[1][0] = -1;
	for (int i = 2; i <= n; i++) up[i][0] = parent[i];
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			if (up[i][j - 1] != -1) up[i][j] = up[ up[i][j - 1] ][j - 1];
			else up[i][j] = -1;
		}
	}

	while (q--) {
		int u, k; cin >> u >> k;
		for (int i = 0; i < LOG; i++) {
			if ((k >> i) & 1) {
				u = up[u][i];
				if (u == -1) break;
			}
		}

		cout << u << '\n';
	}

	return 0;
}