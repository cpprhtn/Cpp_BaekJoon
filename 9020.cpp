#include<cstdio>

int main()
{
	bool arr[10001] = {};
	for (int i = 2; i <= 10000; i++)
	{
		if (!arr[i])
		{
			int temp = i;
			while ((temp += i) <= 10000)
				arr[temp] = true;

		}
	}
    
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i=n/2; i>=2; i--)
        {
            if(!arr[i] && !arr[n-i])
            {
                printf("%d %d\n", i, n-i);
                break;
            }
        }
    }
}
