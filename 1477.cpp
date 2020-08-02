#include <bits/stdc++.h>
using namespace std;

int arr[102];
int main()
{
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
		cin>>arr[i];

	arr[n+1]=k;
	sort(arr, arr+n+1);

	int l=1, r=k, ans=1e9;
	while(l<=r)
	{
		int mid=l+r>>1;
		int s=0, t=0;
		for(int i=1; i<=n+1; i++)
		{
			t+=(arr[i]-arr[i-1])/mid+(((arr[i]-arr[i-1])%mid)>0)-1;
			if(t>m) break;
		}

		if(t>m) l=mid+1;
		else
		{
			r=mid-1;
			ans=min(mid, ans);
		}
	}

	cout<<ans;
}