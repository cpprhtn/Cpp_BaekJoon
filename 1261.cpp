#include <cstdio>
#include <queue>
#define INF 11111111
using namespace std;
struct xy { int x, y; };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char map[100][101];
bool inQ[100][100];
int dist[100][100];
int m, n;

int bell()
{
	queue<xy> Q;
	Q.push({ 0, 0 });
	inQ[0][0] = 1;
	dist[0][0] = 0;
	while (Q.size())
	{
		xy cur = Q.front();
		Q.pop();
		inQ[cur.x][cur.y] = 0;

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (dist[nx][ny] > dist[cur.x][cur.y] + map[nx][ny] - '0')
			{
				dist[nx][ny] = dist[cur.x][cur.y] + map[nx][ny] - '0';
				if (!inQ[nx][ny])
					inQ[nx][ny] = 1, Q.push({ nx, ny });
			}
		}
	}

	return dist[n - 1][m - 1];
}
int main()
{
	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", map[i]);
		for (int j = 0; j < m; j++)
		{
			dist[i][j] = INF;
		}
	}

	printf("%d", bell());
}