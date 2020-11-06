#include <bits/stdc++.h>
using namespace std;

bool p[1001];
int main()
{
	p[1]=1;
	for(int i=2; i<=35; i++)
	{
		if(p[i]==0)
		{
			int t=i*i;
			while(t<=1000)
			{
				p[t]=1;
				t+=i;
			}
		}
	}
	int n;
	cin>>n;

	int ans=0;
	while(n--) 
	{
		int x;
		cin>>x;
		ans+=!p[x];
	}
	cout<<ans;
}