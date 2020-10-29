#include <cstdio>

using namespace std;

int main()
{
    int a, b, v, pos, ans =1;
    scanf("%d %d %d",&a, &b, &v);

    pos = a;
    ans+=(v-a)/(a-b)+((v-a)%(a-b)>0);

    printf("%d\n", ans);
    return 0;
}