#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
int r, c;
char map[50][51];
queue<pair<int, int> > sq, wq;
void wbfs()
{
    int size=wq.size();
    while(size--)
    {
        int x=wq.front().first, y=wq.front().second;
        wq.pop();

        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && nx<r && ny>=0 && ny<c && map[nx][ny]=='.')
                map[nx][ny]='*', wq.push({nx, ny});
        }
    }
}

bool sbfs()
{
    int size=sq.size();
    while(size--)
    {
        int x=sq.front().first, y=sq.front().second;
        sq.pop();

        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && nx<r && ny>=0 && ny<c)
            {
                if(map[nx][ny]=='D')
                    return true;
                if(map[nx][ny]=='.')
                    map[nx][ny]='S', sq.push({nx, ny});
            }

        }
    }
    return false;
}
int main()
{
    scanf("%d %d", &r, &c);
    int count=0;
    for(int i=0; i<r; i++)
    {
        scanf("%s", map[i]);
        for(int j=0; j<c; j++)
        {
            if(map[i][j]=='S')
                sq.push({i, j});

            else if(map[i][j]=='*')
                wq.push({i, j});
        }
    }
    while(!sq.empty())
    {
        count++;
        wbfs();
        int ans=sbfs();
        if(ans)
        {
            printf("%d", count);
            return 0;
        }
    }
    printf("KAKTUS");
}
