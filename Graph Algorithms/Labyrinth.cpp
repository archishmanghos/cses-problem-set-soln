#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 1005;
const int INF = 1e18 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debugarr(x,i,j) cerr << #x <<" "; _print(x,i,j); cerr << endl;
#else
#define debugarr(x)
#endif

void _print(int t){cerr << t;}
void _print(string t){cerr << t;}
void _print(bool t){cerr << t;}
void _print(char t){cerr << t;}
void _print(long double t){cerr << t;}
void _print(double t){cerr << t;}
void _print(unsigned long long t){cerr << t;}
template <class T> void _print(T arr[], int i, int j){cerr << "[ " ;for ( int k = i; k <= j; k++) cerr << arr[k] << ", " ;cerr << "]\n";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr << "{";_print(p.ff);cerr << ",";_print(p.ss);cerr << "}";}
template <class T> void _print(vector <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}

struct point
{
	int x, y;
};

int N, M;
char A[mxN][mxN], direction[mxN][mxN];
bool visited[mxN][mxN];
string ans = "";
point startNode, endNode;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char tellTheDirection(int i)
{
	if(i == 0)
		return 'D';
	if(i == 1)
		return 'U';
	if(i == 2)
		return 'R';
	return 'L';
}

pair<int, int> tellThePreviousPoint(char prevDirection)
{
	if(prevDirection == 'L')
		return {0, 1};
	if(prevDirection == 'R')
		return {0, -1};
	if(prevDirection == 'U')
		return {1, 0};
	return {-1, 0};
}

bool isNodeValid(point node)
{
	if(node.x < 1 || node.x > N)
		return false;
	if(node.y < 1 || node.y > M)
		return false;
	if(visited[node.x][node.y])
		return false;
	if(A[node.x][node.y] == '#')
		return false;

	return true;
}

bool bfs()
{
	queue<point> q;
	q.push(startNode);
	visited[startNode.x][startNode.y] = true;

	while(!q.empty())
	{
		point node = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			point nextNode;
			nextNode.x = node.x + dx[i];
			nextNode.y = node.y + dy[i];

			if(isNodeValid(nextNode))
			{
				if(nextNode.x == endNode.x && nextNode.y == endNode.y)
				{
					direction[nextNode.x][nextNode.y] = tellTheDirection(i);
					visited[nextNode.x][nextNode.y] = true;

					point traverseBack;
					traverseBack.x = nextNode.x;
					traverseBack.y = nextNode.y;

					while(1)
					{
						ans += direction[traverseBack.x][traverseBack.y];

						pair<int, int> nextDirection = tellThePreviousPoint(direction[traverseBack.x][traverseBack.y]);

						traverseBack.x += nextDirection.first;
						traverseBack.y += nextDirection.second;

						if(traverseBack.x == startNode.x && traverseBack.y == startNode.y)
							break;
					}

					return true;
				}

				direction[nextNode.x][nextNode.y] = tellTheDirection(i);
				visited[nextNode.x][nextNode.y] = true;
				q.push(nextNode);
			}
		}
	}

	return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			cin >> A[i][j];
			if(A[i][j] == 'A')
			{
				startNode.x = i;
				startNode.y = j;
			}
			if(A[i][j] == 'B')
			{
				endNode.x = i;
				endNode.y = j;
			}
		}
	}

	memset(visited, false, sizeof(false));
	
	if(bfs())
	{
		cout << "YES" << '\n';
		reverse(ans.begin(), ans.end());

		cout << ans.size() << '\n';
		cout << ans;
	}
	else
		cout << "NO" << '\n';


    return 0;
}