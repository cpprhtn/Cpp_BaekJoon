#include <cstdio>
int fi(int num) 
{
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    return fi(num-2) + fi(num-1);
}

int main() 
{
    int num;
    scanf("%d",&num);
    printf("%d",fi(num));
}