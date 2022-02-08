#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 1e5 + 5;
const int INF = 1e18 + 7;

int N, M, U, V;
vector<vector<int>> adj(mxN);
vector<bool> visited(mxN);
vector<int> ans;

bool findCycle(int node, int parent) {
    visited[node] = true;
    ans.push_back(node);

    for (int child: adj[node]) {
        if (visited[child]) {
            if (child != parent) {
                ans.push_back(child);
                return true;
            }
        } else {
            if (findCycle(child, node)) {
                return true;
            }
        }
    }

    ans.pop_back();
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> N >> M;
    adj.resize(N + 2);

    for (int i = 1; i <= M; i++) {
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    visited.assign(N + 2, false);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            if (findCycle(i, -1)) {
                int pos = 0;
                for (int i = 0; i < ans.size(); i++) {
                    if (ans[i] == ans.back()) {
                        pos = i;
                        break;
                    }
                }
                cout << ans.size() - pos << '\n';
                for (int i = pos; i < ans.size(); i++) {
                    cout << ans[i] << ' ';
                }
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}