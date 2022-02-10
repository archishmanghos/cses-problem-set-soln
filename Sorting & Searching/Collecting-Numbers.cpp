#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    cin >> N;
    vector<int> A(N + 2), index(N + 2);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        index[A[i]] = i;
    }

    int ans = 0, prevIndex = N + 1;
    for (int i = 1; i <= N; i++) {
        if (index[i] < prevIndex) {
            ans += 1;
        }
        prevIndex = index[i];
    }

    cout << ans;

    return 0;
}