#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

struct coordinate {
    int x, y;
};

string
recreatePath(int distanceToCover, coordinate start, vector<vector<coordinate>> &from, vector<vector<char>> &direction) {

    string ans = "";
    while (distanceToCover > 0) {
        char dirGiven = direction[start.x][start.y];
        ans += dirGiven;
        start = from[start.x][start.y];
        distanceToCover -= 1;
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, M;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    char dir[4] = {'U', 'R', 'D', 'L'};

    cin >> N >> M;
    char A[N + 2][M + 2];
    vector<vector<int>> distMonst(N + 2, vector<int>(M + 2));
    vector<vector<int>> distA(N + 2, vector<int>(M + 2));
    vector<vector<coordinate>> from(N + 2, vector<coordinate>(M + 2));
    vector<vector<char>> direction(N + 2, vector<char>(M + 2));

    queue<coordinate> q;
    for (int i = 1; i <= N + 1; i++) {
        distMonst[i].assign(M + 2, INF);
        distA[i].assign(M + 2, INF);
        from[i].assign(M + 2, {-1, -1});
        direction[i].assign(M + 2, '0');
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'M') {
                q.push({i, j});
                distMonst[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        coordinate curCell = q.front();
        int x = curCell.x;
        int y = curCell.y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (A[x1][y1] == '.' or A[x1][y1] == 'A') {
                if (distMonst[x1][y1] > distMonst[x][y] + 1) {
                    distMonst[x1][y1] = distMonst[x][y] + 1;
                    q.push({x1, y1});
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i][j] == 'A') {
                q.push({i, j});
                distA[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        coordinate curCell = q.front();
        int x = curCell.x;
        int y = curCell.y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (A[x1][y1] == '.') {
                if (distA[x1][y1] > distA[x][y] + 1) {
                    distA[x1][y1] = distA[x][y] + 1;
                    from[x1][y1] = {x, y};
                    direction[x1][y1] = dir[i];
                    q.push({x1, y1});
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (distA[i][1] < distMonst[i][1]) {
            string ans = recreatePath(distA[i][1], {i, 1}, from, direction);
            cout << "YES" << '\n';
            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            cout << ans;
            return 0;
        } else if (distA[i][M] < distMonst[i][M]) {
            string ans = recreatePath(distA[i][M], {i, M}, from, direction);
            cout << "YES" << '\n';
            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            cout << ans;
            return 0;
        }
    }

    for (int i = 1; i <= M; i++) {
        if (distA[1][i] < distMonst[1][i]) {
            string ans = recreatePath(distA[1][i], {1, i}, from, direction);
            cout << "YES" << '\n';
            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            cout << ans;
            return 0;
        } else if (distA[N][i] < distMonst[N][i]) {
            string ans = recreatePath(distA[N][i], {N, i}, from, direction);
            cout << "YES" << '\n';
            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            cout << ans;
            return 0;
        }
    }

    cout << "NO";
    return 0;
}