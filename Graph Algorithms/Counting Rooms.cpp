#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 1005;
const int INF = 1e18 + 7;
 
int N, M, visited[mxN][mxN];
char A[mxN][mxN];
 
void dfs(int x, int y)
{
	if (visited[x][y])
		return;
	visited[x][y] = 1;
 
	if (x + 1 <= N && A[x + 1][y] == '.')
		dfs(x + 1, y);
	if (y + 1 <= M && A[x][y + 1] == '.')
		dfs(x, y + 1);
	if (x - 1 >= 1 && A[x - 1][y] == '.')
		dfs(x - 1, y);
	if (y - 1 >= 1 && A[x][y - 1] == '.')
		dfs(x, y - 1);
	return;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
 
	memset(visited, 0, sizeof(visited));
 
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (A[i][j] == '.' && !visited[i][j])
			{
				++ans;
				dfs(i, j);
			}
		}
	}
	cout << ans;
	return 0;
}
 
//02-03-2021 10:51:35