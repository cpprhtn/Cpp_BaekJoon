#include <bits/stdc++.h>
using namespace std;

bool v[1000001];
int p[1000001];
vector<int> kms;
int main()
{
	priority_queue<int, vector<int>, greater<int> > pq;
	queue<int> Q;
	pq.push(4);
	pq.push(7);

	int n;
	cin>>n;
	while(pq.top()<=n)
	{
		int cur=pq.top();
		pq.pop();
		v[cur]=1;
		Q.push(cur);
		kms.push_back(cur);
		pq.push(cur*10+4);
		pq.push(cur*10+7);
	}

	bool chk=false;
	while(Q.size())
	{
		int cur=Q.front();
		Q.pop();
		if(cur==n)
		{
			chk=true;
			goto out;
		}

		for(int i : kms)
		{
			if(cur+i>n || v[cur+i]) continue;
			Q.push(cur+i);
			v[cur+i]=1;
			p[cur+i]=cur;
		}
	}

	out:;
	vector<int> ans;
	if(chk)
	{
		for(int x=n; x!=0; x=p[x])
		{
			ans.push_back(x-p[x]);
		}
		
		sort(ans.begin(), ans.end());

		for(int i : ans)
			cout<<i<<' ';
	}
	else cout<<-1;

}