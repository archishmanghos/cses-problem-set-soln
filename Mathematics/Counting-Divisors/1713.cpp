#include <bits/stdc++.h>
#define int long long

int countDiv[1000100];

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	for (int i = 1; i <= 1000000; i++) countDiv[i] = 1;
	for (int i = 2; i <= 1000000; i++) {
		countDiv[i]++;
		for (int j = 2 * i; j <= 1000000; j += i) countDiv[j]++;
	}

	while (T--) {
		int N; std::cin >> N;
		std::cout << countDiv[N] << '\n';
	}
	return 0;
}