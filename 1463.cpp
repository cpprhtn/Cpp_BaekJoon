#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	queue<int> Queue;
	int num, count=0;
	scanf("%d", &num);
	Queue.push(num);
	Queue.push(-1);
	while(1)
	{
		num=Queue.front();
		Queue.pop();
		if(num==1)
			break;

		if(num==-1)
		{
			count++;
			Queue.push(-1);
			continue;
		}

		if(num<=0)
			continue;

		if(num%3==0)
			Queue.push(num/3);

		if(num%2==0)
			Queue.push(num/2);

		Queue.push(num-1);
	}

	printf("%d", count);
}
/*cpp17 적용한 나름 숏코딩*/
#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
bool v[1000001];
int n;
int solve(int x)
{
    if(x==n) return 0;
    if(v[x]) return dp[x];
    if(x>n) return 1e9;
    v[x]=true;
    return dp[x] = 1+min({solve(x+1), solve(x*2), solve(x*3)});
}
int main()
{
    cin>>n;
    cout<<solve(1);
}
