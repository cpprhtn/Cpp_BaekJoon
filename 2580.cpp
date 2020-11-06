#include <cstdio>
#include <vector>
using namespace std;
int sdk[9][9];
vector<pair<int, int> > blank;
void input()
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            scanf("%d", &sdk[i][j]);
            if(!sdk[i][j])
                blank.push_back({i, j});
        }

}
bool solve()
{
    static int pos=0;
    int x=blank[pos].first, y=blank[pos].second;
    bool num[10]={};
    for(int i=0; i<9; i++)
    {
        num[sdk[x][i]]=true;
        num[sdk[i][y]]=true;
    }
    int fx=x/3*3, fy=y/3*3;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            num[sdk[fx+i][fy+j]]=true;

    for(int i=1; i<=9; i++)
    {
        if(!num[i])
        {
            sdk[x][y]=i;
            if(pos==blank.size()-1)
                return true;

            pos++;
            if(solve())
                return true;
        }

    }
    pos--, sdk[x][y]=0;
    return false;
}
void print()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            printf("%d ", sdk[i][j]);

        printf("\n");
    }
}
int main()
{
    input();
    if(!blank.empty())
        solve();
    print();
}
