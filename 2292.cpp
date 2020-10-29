#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int temp = 1;
    for(int i=1; 1; i++)
    {
        if(n <= temp)
        {
            printf("%d",i);
            break;
        }

        temp+=6*i;
    }
}