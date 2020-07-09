#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int st[MAX*4];
bool lazy[MAX*4];

int n, m, a;

void lazy_update(int len, int p)
{
	if(lazy[p])
	{
		st[p]=len-st[p];
		if(len>1)
		{
			lazy[p<<1]=!lazy[p<<1];
			lazy[(p<<1)+1]=!lazy[(p<<1)+1];
		}
	}

	lazy[p]=0;
}

void range_update(int s, int t, int p, int x, int y)
{
	lazy_update(y-x+1, p);
	if(s>y || t<x) return;
	if(s<=x && t>=y)
	{
		lazy[p]=1;
		lazy_update(y-x+1, p);
		return;
	}
	int mid=x+y>>1;
	range_update(s, t, p<<1, x, mid);
	range_update(s, t, (p<<1)+1, mid+1, y);
	st[p]=st[p<<1]+st[(p<<1)+1];
}

int query(int s, int t, int p, int x, int y)
{
	lazy_update(y-x+1, p);
	if(s>y || t<x) return 0;
	if(s<=x && t>=y) return st[p];
	int mid=x+y>>1;
	return query(s, t, p<<1, x, mid)+query(s, t, (p<<1)+1, mid+1, y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin>>n>>m;

	while(m--)
	{
		int o, s, t;
		cin>>o>>s>>t;
		if(o==0) range_update(s, t, 1, 1, n);
		else cout<<query(s, t, 1, 1, n)<<"\n";
	}
}
