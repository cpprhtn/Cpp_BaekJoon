#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string ans, str;
        int dp[10001]={};
        cin>>ans>>str;

        for(int i=0; i<ans.size(); i++)
        {
            if(i>=str.size()-1 && ans.substr(i-str.size()+1, str.size())==str)
                dp[i+1]=dp[i-str.size()+1]+1;

            else
                dp[i+1]=dp[i]+1;
        }

        cout<<dp[ans.size()]<<"\n";
    }
}

