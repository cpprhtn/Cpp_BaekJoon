#include <cstdio>
#include <algorithm>
using namespace std;

int arr[51];
int main()
{
	int l, num, n, ans;
	scanf("%d", &l);

	for(int i=0; i<l; i++)
	{
		scanf("%d", &num);
		arr[i]=num;
	}

	sort(arr, arr+l);
	scanf("%d", &n);

	auto it=lower_bound(arr, arr+l, n);
	if(*it==n)
		ans=0;

	else if(it==arr)
		ans=(*it-n)*n-1;

	else
		ans=(*it-n)*(n-*(it-1))-1;

	printf("%d", ans);
}
