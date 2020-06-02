#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10000];
pair<int, pair<int, int> > input[101];
int main()
{
	int n, x1, x2, y, ans=0;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d %d %d", &y, &x1, &x2);
		input[i]={y, {x1, x2}};	
	}
	
	sort(input, input+n);
	for(int i=0; i<n; i++)
	{
		int h=input[i].first, l=input[i].second.first, r=input[i].second.second;
		ans+=2*h-arr[l]-arr[r-1];
		
		for(int j=l; j<r; j++)
		{
			arr[j]=h;
		}
	}
		
	printf("%d", ans);
}