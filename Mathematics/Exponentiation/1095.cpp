#include <bits/stdc++.h>
#define int long long

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--) {
		int A, B; std::cin >> A >> B;
		int answer = 1, MOD = 1e9 + 7;

		while (B) {
			if (B & 1) answer = (answer * A) % MOD;
			A = (A * A) % MOD;
			B >>= 1;
		}

		std::cout << answer << '\n';
	}
	return 0;
}