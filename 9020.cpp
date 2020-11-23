#include<cstdio>

int main()
{
    bool str[10001] = {0};
    for (int i = 2; i < 10000; i++)
    {
        if (!str[i])
        {
            int t = i;
            while ((t += i) <= 10000)
            {
                str[t] = true;
            }
        }
    }

    int n;
    scanf(" %d", &n);

    while(n--)
    {
        int k;
        scanf(" %d", &k);

        for (int i = k/2; i >= 2; i--)
        {
            if(!str[i] && !str[k-i])
            {
                printf("%d %d\n", i, k-i);
                break;
            }
        }
    }
    return 0;
}