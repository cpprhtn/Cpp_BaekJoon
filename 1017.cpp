#include <bits/stdc++.h>
using namespace std;

int arr[51], p[51];
bool v[51], prime[2001], l[51];
int n;
bool dfs(int x)
{
	v[x]=1;
	for(int i=2; i<=n; i++)
	{
		if(i==x || p[i]==x || l[i] || prime[arr[x]+arr[i]]) continue;
		if(!p[i] || (!v[p[i]] && dfs(p[i])))
		{
			p[i]=x;
			p[x]=i;
			return true;
		}
	}
	return false;
}
int main()
{
	prime[1]=1;
	for(int i=2; i<=100; i++)
	{
		if(!prime[i])
		{
			int t=i;
			while((t+=i)<=2000)
			{
				prime[t]=1;
			}
		}
	}

	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
	}
	sort(arr+2, arr+n+1);
	bool chk=false;
	for(int j=2; j<=n; j++)
	{
		if(prime[arr[1]+arr[j]]) continue;
		memset(p, 0, 4*51);
		l[j]=1;
		int i=2;
		for(; i<=n; i++)
		{
			memset(v, 0, n+1);
			if(p[i]!=0 || l[i]) continue;
			if(!dfs(i)) break;
		}

		if(i==n+1) chk=true, cout<<arr[j]<<" ";
		l[j]=0;
	}
	
	if(chk==false) cout<<-1;
}