#include <bits/stdc++.h>
#define i64 int64_t

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K; std::cin >> N >> K;
	std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;
	int A[K + 2]; for (int i = 1; i <= K; i++) {
		std::cin >> A[i];
		pq.push(A[i]);
	}

	i64 answer = 0;
	while (pq.size() > 1) {
		i64 a = pq.top();
		pq.pop();
		i64 b = pq.top();
		pq.pop();

		answer += 0ll + (a + b);
		pq.push(a + b);
	}

	std::cout << answer;
	return 0;
}