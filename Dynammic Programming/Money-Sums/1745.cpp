#include <bits/stdc++.h>
using namespace std;

int N, A[105];
int cache[105][100100];
set<int> s;

void dp(int idx, int sum) {
	if (idx == N) {
		if (sum > 0) s.insert(sum);
		return;
	}
	if (cache[idx][sum] != -1) return;

	cache[idx][sum] = 1;
	dp(idx + 1, sum + A[idx]);
	dp(idx + 1, sum);
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	memset(cache, -1, sizeof(cache));
	dp(0, 0);
	cout << s.size() << '\n';
	for (int i : s) cout << i << ' ';
	return 0;
}