#include <cstdio>
int main()
{
    int n, a, b, ans=0;
    scanf("%d %d %d", &n, &a, &b);
    a--, b--;
    while(a!=b)
        a/=2, b/=2, ans++;

    printf("%d", ans);
}
