#include<cstdio>
using namespace std;
int main()
{
    int chess[6]={1, 1, 2, 2, 2, 8};
    for(int i=0; i<6; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%d ", chess[i]-a);
    }
}
