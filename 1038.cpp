#include <iostream>
using namespace std;

int dp[11][10];

int main()
{
	int n;
	cin>>n;
	
	for(int i=0; i<=9; i++)
	{
		dp[1][i]=i+1;
	}

	for(int i=2; i<=10; i++)
	{
		dp[i][i-2]=dp[i-1][9];
		for(int j=i-1; j<=9; j++)
		{
			dp[i][j]=dp[i-1][j-1]-dp[i-2][9]+dp[i][j-1];
		}
	}

	n++;
	bool chk=0;
	int c=10;
	for(int i=10; i>0; i--)
	{
		if(dp[i-1][9]>=n) continue;
		for(int j=i-1; j<c; j++)
		{
			if(dp[i][j]>=n)
			{
				chk=true;
				cout<<j;
				if(i>1) n-=(j==i-1?dp[i-1][9]:dp[i][j-1])-dp[i-2][9];
				c=j;
				break;
			}
		}
	}

	if(!chk) cout<<-1;
}