#include <bits/stdc++.h>
#define i64 int64_t

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K; std::cin >> N >> K;
	int A[N]; for (int i = 0; i < N; i++) std::cin >> A[i];


	i64 answer = -1, low = *(std::max_element(A, A + N)), high = std::accumulate(A, A + N, 0l);
	while (low <= high) {
		i64 mid = low + (high - low) / 2;
		auto f = [&]() {
			int subarrays = 1;
			i64 sum = 0;
			for (int i = 0; i < N; i++) {
				if (sum + A[i] > mid) {
					sum = A[i];
					subarrays++;
				} else {
					sum += A[i];
				}
			}

			return subarrays <= K;
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