#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int h, w, n, a, b, ans;
        scanf("%d %d %d", &h, &w, &n);

        a=(n+h-1)%h+1, b=(n+h-1)/h;
        ans=a*100+b;
        printf("%d\n", ans);
    }


}
