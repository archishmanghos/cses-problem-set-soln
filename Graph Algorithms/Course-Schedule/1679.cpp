#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	vector<int> adj[N];
	int indegree[N], idx = 0;
	memset(indegree, 0, sizeof(indegree));

	for (int i = 1; i <= M; i++) {
		int A, B; cin >> A >> B; A--, B--;
		indegree[B]++;
		adj[A].push_back(B);
	}

	vector<int> answer(N, -1);
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (!indegree[i]) q.push(i);
	}

	while (!q.empty()) {
		int node = q.front(); q.pop();
		answer[idx++] = node;
		indegree[node]--;
		for (int child : adj[node]) {
			indegree[child]--;
			if (indegree[child] == 0) q.push(child);
		}
	}

	if (answer[N - 1] == -1) cout << "IMPOSSIBLE";
	else {
		for (int i = 0; i < N; i++) cout << (answer[i] + 1) << ' ';
	}
	return 0;
}