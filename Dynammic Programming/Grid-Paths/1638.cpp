#include <bits/stdc++.h>
using namespace std;

int N;
char A[1000][1000];
int cache[1000][1000];

int dp(int r, int c, int MOD = 1e9 + 7) {
	auto possible = [&](int x, int y) {
		return (x >= 0 and x < N and y >= 0 and y < N);
	};

	if (!possible(r, c)) return 0;
	if (A[r][c] == '*') return 0;
	if (cache[r][c] != -1) return cache[r][c];
	if (r == N - 1 and c == N - 1) return 1;

	int answer = (0ll + dp(r + 1, c) % MOD + dp(r, c + 1) % MOD) % MOD;
	return cache[r][c] = answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));
	cout << dp(0, 0);
	return 0;
}