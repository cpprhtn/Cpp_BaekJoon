#include <bits/stdc++.h>
using namespace std;

char arr[20][21], tmp[20][21];
const double K=8.0;
double T=1.0;
int ans;
int main()
{
	int n;
	cin>>n;
	int cnt=0;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		for(int j=0; j<n; j++)
		{
			if(arr[i][j]=='T') cnt++;
		}
	}

	ans=cnt;
	while(T>0.01)
	{
		int new_cnt=0;
		int pick=rand()%n;
		memcpy(tmp, arr, sizeof(arr));
		for(int i=0; i<n; i++)
		{
			tmp[i][pick]=(tmp[i][pick]=='H'?'T':'H');
		}
		for(int i=0; i<n; i++)
		{
			int sub=0;
			for(int j=0; j<n; j++)
			{
				sub+=(tmp[i][j]=='T');
			}

			if(sub>n-sub)
			{
				for(int j=0; j<n; j++)
				{
					tmp[i][j]=(tmp[i][j]=='H'?'T':'H');
				}

				sub=n-sub;
			}

			new_cnt+=sub;
		}
		
		int p=(exp((cnt-new_cnt)/(K*T)))*10000;
		int q=rand()%10000;
		if(ans>new_cnt) ans=new_cnt;
		if(p>q)
		{
			memcpy(arr, tmp, sizeof(arr));
			cnt=new_cnt;
		}

		T*=0.9999;
	}

	cout<<ans;
}