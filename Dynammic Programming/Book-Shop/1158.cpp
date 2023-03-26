#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, X; cin >> N >> X;
	int H[N], S[N];
	for (int i = 0; i < N; i++) cin >> H[i];
	for (int i = 0; i < N; i++) cin >> S[i];

	int cache[N][X + 1];
	memset(cache, 0, sizeof(cache));
	for (int i = 0; i <= X; i++) cache[0][i] = (i >= H[0] ? S[0] : 0);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= X; j++) {
			cache[i][j] = cache[i - 1][j];
			if (H[i] <= j) cache[i][j] = max(cache[i][j], cache[i - 1][j - H[i]] + S[i]);
		}
	}

	cout << cache[N - 1][X];
	return 0;
}