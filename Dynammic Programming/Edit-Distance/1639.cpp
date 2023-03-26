#include <bits/stdc++.h>
using namespace std;

string S, T;
int N1, N2;
int cache[5000][5000];

int dp(int idx1, int idx2) {
	if (idx1 < 0) return idx2 + 1;
	if (idx2 < 0) return idx1 + 1;
	int &answer = cache[idx1][idx2];
	if (answer != -1) return answer;

	if (S[idx1] == T[idx2]) answer = dp(idx1 - 1, idx2 - 1);
	else {
		answer = dp(idx1, idx2 - 1) + 1;
		answer = min(answer, dp(idx1 - 1, idx2) + 1);
		answer = min(answer, dp(idx1 - 1, idx2 - 1) + 1);
	}

	return answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> S >> T;
	N1 = S.size();
	N2 = T.size();

	memset(cache, -1, sizeof(cache));
	cout << dp(N1 - 1, N2 - 1);
	return 0;
}