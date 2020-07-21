#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
struct state
{
	string sn;
	int c;
};
bool cmp(state &a, state &b)
{
	if(a.sn.size()!=b.sn.size())
		return a.sn.size()<b.sn.size();
	
	if(a.c!=b.c)
		return a.c<b.c;
	
	return a.sn<b.sn;
}
state arr[1000];
int main()
{
	int n; 
	string sn;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int c=0;
		cin>>sn;
		for(auto j : sn)
			if(isdigit(j))
				c+=j-'0';
		
		arr[i]={sn, c};
	}
	
	sort(arr, arr+n, cmp);
	for(int i=0; i<n; i++)
		cout<<arr[i].sn<<"\n";
}