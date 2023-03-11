#include <bits/stdc++.h>
#define int long long

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, Q; std::cin >> N >> Q;
	int parent[N + 2]; for (int i = 1; i <= N; i++) std::cin >> parent[i];

	int up[N + 2][31];
	for (int i = 1; i <= N; i++) up[i][0] = parent[i];
	for (int j = 1; j < 31; j++) {
		for (int i = 1; i <= N; i++) {
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}

	while (Q--) {
		int node, K; std::cin >> node >> K;
		for (int i = 30; i >= 0; i--) {
			if ((K >> i) & 1ll) {
				node = up[node][i];
			}
		}

		std::cout << node << '\n';
	}
	return 0;
}