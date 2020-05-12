#include <cstdio>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if(a>b) puts(">");
    else if(a==b) puts("==");
    else puts("<");
}