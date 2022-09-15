#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;
	vector<vector<int>> v(M, vector<int>(3));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}

	vector<int> dist(N + 1, 1e9), parent(N + 1, -1);
	dist[1] = 0;
	int lastNode;

	for (int i = 1; i <= N; i++) {
		lastNode = -1;
		for (auto edge : v) {
			int u = edge[0], v = edge[1], wt = edge[2];
			if (dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
				parent[v] = u;
				lastNode = v;
			}
		}
	}

	if (lastNode != -1) {
		cout << "YES" << '\n';
		for (int i = 1; i <= N; i++) {
			lastNode = parent[lastNode];
		}
		vector<int> printCyle;
		int firstNode = lastNode;
		while (printCyle.size() == 0 or lastNode != firstNode) {
			printCyle.push_back(lastNode);
			lastNode = parent[lastNode];
		}

		reverse(printCyle.begin(), printCyle.end());
		printCyle.push_back(printCyle[0]);
		for (int i : printCyle) cout << i << ' ';
	} else {
		cout << "NO";
	}

	return 0;
}