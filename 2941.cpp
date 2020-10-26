#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    int ans=0;
    cin>>str;

    for(int i=0; i<str.size(); i++)
    {
        if(i<str.size()-2 && str[i]=='d' && str[i+1]=='z' && str[i+2]=='=')
            i+=2;

        else if(i<str.size()-1)
        {
            if(str[i]=='c' &&(str[i+1]=='=' || str[i+1]=='-'))
                i++;

            else if(str[i]=='d' && str[i+1]=='-')
                i++;

            else if((str[i]=='l' || str[i]=='n') && str[i+1]=='j')
                i++;

            else if((str[i]=='s' || str[i]=='z') && str[i+1]=='=')
                i++;

        }

        ans++;
    }

    printf("%d", ans);
}
