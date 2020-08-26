#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int dx[]={0, 1, 0, -1};
    int dy[]={1, 0, -1, 0};
    int t;
    scanf("%d", &t);

    while(t--)
    {
        char c[501];
        int maxx=0, maxy=0, minx=0, miny=0;
        int d=0, x=0, y=0;
        scanf("%s", c);

        for(int i=0; c[i]; i++)
        {
            char &cmd=c[i];
            if(cmd=='F')
                x+=dx[d], y+=dy[d];

            else if(cmd=='B')
                x-=dx[d], y-=dy[d];

            else if(cmd=='L')
                d=(d+3)%4;

            else
                d=(d+1)%4;

            maxx=max(maxx, x), maxy=max(maxy, y);
            minx=min(minx, x), miny=min(miny, y);
        }

        int ans=(maxx-minx)*(maxy-miny);
        printf("%d\n", ans);
    }
}
