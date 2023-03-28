#include <bits/stdc++.h>
using namespace std;

int N, M, U, V;
vector<int> adj[100100];
int visited[100100], dfsVisited[100100];

bool cycle(int node, vector<int> &parent, vector<int> &answer) {
	if (visited[node]) {
		if (dfsVisited[node]) {
			answer.push_back(node);
			while (parent.back() != node) {
				answer.push_back(parent.back());
				parent.pop_back();
			}
			answer.push_back(node);
			return true;
		}
		return false;
	}

	visited[node] = dfsVisited[node] = 1;
	parent.push_back(node);
	for (int child : adj[node]) {
		if (cycle(child, parent, answer)) return true;
	}
	parent.pop_back();
	dfsVisited[node] = 0;
	return false;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> U >> V;
		adj[U - 1].push_back(V - 1);
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			vector<int> answer, parent;
			if (cycle(i, parent, answer)) {
				cout << answer.size() << '\n';
				for (int i = answer.size() - 1; i >= 0; i--) cout << (answer[i] + 1) << ' ';
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}