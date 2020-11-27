#include <cstdio>

int main()
{
    int sum = 0;
    char arr[5] = { 0 };
    for (int i = 0; i < 5; i++)
    {
        int k = 40;
        int n = 0;
        scanf("%d",&n);
        arr[i] = (n > k ? n : k);
        sum += arr[i];
    }
    printf("%d", sum/5);
}