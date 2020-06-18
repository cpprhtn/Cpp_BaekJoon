#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int no_file;
    long long cluster, ans=0;

    cin>>no_file;
    vector<long long> data;
    for(int i=0; i<no_file; i++)
    {
        long long temp;
        cin>>temp;
        data.push_back(temp);
    }

    cin>>cluster;
    for(int i=0; i<no_file; i++)
    {
        ans+=data[i]/cluster;
        if(data[i]%cluster>0)
            ans++;
    }

    cout<<cluster*ans<<endl;
    return 0;
}
