#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num;
    int k;
    cin>>num>>k;

    queue<string> Q;
    Q.push(num);

    while(k--)
    {
        int size=Q.size();
        if(!size) break;
        unordered_set<string> S;
        while(size--)
        {
            string cur=Q.front();
            Q.pop();
            for(int i=0; i<cur.size(); i++)
            {
                for(int j=i+1; j<cur.size(); j++)
                {
                    if(i==0 && cur[j]=='0') continue;
                    swap(cur[i], cur[j]);
                    if(S.find(cur)==S.end())
                    {
                        S.insert(cur);
                        Q.push(cur);
                    }
                    swap(cur[i], cur[j]);
                }
            }
        }

    }

    if(Q.empty())
    {
        cout<<-1;
        return 0;
    }
    string ans="";
    while(Q.size())
    {
        ans=max(ans, Q.front());
        Q.pop();
    }

    cout<<ans;
}