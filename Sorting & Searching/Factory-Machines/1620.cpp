#include <bits/stdc++.h>
#define i64 int64_t

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, T; std::cin >> N >> T;
	int A[N]; for (int i = 0; i < N; i++) std::cin >> A[i];

	i64 answer = -1, low = 1, high = 1ll * (*(std::min_element(A, A + N))) * T;
	while (low <= high) {
		i64 mid = low + (high - low) / 2;
		auto f = [&]() {
			i64 products = 0;
			for (int i = 0; i < N; i++) products += 1l * (mid / A[i]);
			return products >= T;
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