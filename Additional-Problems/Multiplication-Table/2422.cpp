#include <bits/stdc++.h>
#define i64 long long

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	i64 answer = -1, low = 1, high = 1ll * N * N;

	while (low <= high) {
		i64 mid = low + (high - low) / 2;
		auto f = [&]() {
			i64 countLess = 0;
			for (int i = 1; i <= N; i++) countLess += std::min(1ll * N, mid / i);

			return (2 * countLess >= (1ll * N * N + 1));
		};

		if (f()) {
			answer = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	std::cout << answer;
	return 0;
}