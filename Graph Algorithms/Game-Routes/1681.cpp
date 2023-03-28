#include <bits/stdc++.h>
using namespace std;

int N, M, U, V;
vector<int> adj[200200];
int cache[200200];

int dfs(int node, int MOD = 1e9 + 7) {
	if (node == N - 1) return 1;
	if (cache[node] != -1) return cache[node];

	int answer = 0;
	for (int child : adj[node]) answer = (0ll + answer + dfs(child) % MOD) % MOD;
	return cache[node] = answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> U >> V; U--, V--;
		adj[U].push_back(V);
	}

	memset(cache, -1, sizeof(cache));
	cout << dfs(0);
	return 0;
}