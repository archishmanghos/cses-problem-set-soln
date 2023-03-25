#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, X; cin >> N >> X;
	int coins[N]; for (int i = 0; i < N; i++) cin >> coins[i];
	int cache[N][X + 2], MOD = 1e9 + 7;
	memset(cache, 0, sizeof(cache));
	for (int i = 0; i < N; i++) cache[i][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= X; j++) {
			if (i == 0) cache[i][j] = (j % coins[i] == 0);
			else {
				cache[i][j] = cache[i - 1][j];
				if (coins[i] <= j) {
					cache[i][j] = (0ll + cache[i][j] + cache[i][j - coins[i]]) % MOD;
				}
			}
		}
	}

	cout << cache[N - 1][X];
	return 0;
}