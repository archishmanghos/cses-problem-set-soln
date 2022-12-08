#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q, k, maxx = 1e18;
	cin >> q;
	auto power = [](int a) {
		int ans = 1;
		while (a--) {
			ans *= 10;
		}

		return ans;
	};

	while (q--) {
		cin >> k;
		for (int i = 10, j = 1; i < maxx; i *= 10, j += 1) {
			int ub = i - 1, lb = (i / 10);
			int digits = (ub - lb + 1) * j;
			if (digits >= k) {
				int number = lb + ((k + j - 1) / j) - 1;
				int digit = j - (k % j == 0 ? j : k % j);
				cout << ((number / power(digit)) % 10) << '\n';
				break;
			} else {
				k -= digits;
			}
		}
	}
	return 0;
}