#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 100000
using namespace std;

int st[4*MAX], arr[MAX+1];
int n, m, s;

void update(int p, int x)
{
	p+=s;
	while(p)
	{
		st[p]+=x;
		p>>=1;
	}
}

int query(int l, int r, int p, int x, int y)
{
	if(l>y || r<x) return 0;
	if(l<=x && r>=y) return st[p];
	int mid=(x+y)>>1;
	return query(l, r, p<<1, x, mid)+query(l, r, (p<<1)+1, mid+1, y);
}
int main()
{
	cin>>n;
	s=1<<int(ceil(log2(n)));
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		arr[x]=i;
		update(i, 1);
	}

	for(int i=0; i<n; i++)
	{
		int x;
		if(i%2)
		{
			x=arr[n-(i/2)];
			update(x, -1);
			cout<<query(x, n-1, 1, 0, s-1)<<"\n";
		}
		else
		{
			x=arr[(i/2)+1];
			update(x, -1);
			cout<<query(0, x, 1, 0, s-1)<<"\n";
		}
	}
}
