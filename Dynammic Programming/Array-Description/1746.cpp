#include <bits/stdc++.h>
using namespace std;

int N, M, A[100100];
int cache[102][100100];

int dp(int pre, int idx, int MOD = 1e9 + 7) {
	if (idx == N) return 1;
	int &answer = cache[pre][idx];
	if (answer != -1) return answer;

	answer = 0;
	if (idx == 0) {
		if (A[idx] == 0) {
			for (int i = 1; i <= M; i++) {
				answer = (0ll + answer + dp(i, idx + 1)) % MOD;
			}
		} else {
			answer = (0ll + answer + dp(A[idx], idx + 1)) % MOD;
		}
	} else {
		if (A[idx] == 0) {
			if (pre - 1 >= 1) answer = (0ll + answer + dp(pre - 1, idx + 1)) % MOD;
			answer = (0ll + answer + dp(pre, idx + 1)) % MOD;
			if (pre + 1 <= M) answer = (0ll + answer + dp(pre + 1, idx + 1)) % MOD;
		} else {
			if (abs(pre - A[idx]) <= 1) {
				answer = (0ll + answer + dp(A[idx], idx + 1)) % MOD;
			}
		}
	}

	return answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	memset(cache, -1, sizeof(cache));
	cout << dp(0, 0);
	return 0;
}