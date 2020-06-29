#include <iostream>
#include <queue>
#include <algorithm>
#define INF 333333333
using namespace std;
int w[300], p[300][300];
bool inQ[300];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ans=INF;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>p[i][j];
        }
    }

    for(int i=0; i<n; i++)
	{
		priority_queue<pair<int, int> > pq;
		pq.push({-w[i], i});
		int tmp=0;
		bool v[300]={};
		while(pq.size())
		{
			int cur = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			if(v[cur]) continue;
			tmp+=cost;
			v[cur]=1;
			for(int i=0; i<n; i++)
			{
				if(!v[i])
				{
					pq.push({-min(w[i], p[cur][i]), i});
				}
			}
		}
		
		ans=min(ans, tmp);
	}
	
	cout<<ans;
}