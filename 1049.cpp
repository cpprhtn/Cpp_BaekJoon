#include <iostream>

using namespace std;
const int INF=1000000000;
int main()
{
    int n, m, ans;
    cin>>n>>m;
    int cheep_set=INF, cheep_one=INF;
    for(int i=0; i<m; i++)
    {
        int set, one;
        cin>>set>>one;

        cheep_set=(cheep_set>set?set:cheep_set);
        cheep_one=(cheep_one>one?one:cheep_one);

    }

    if(cheep_one*6<=cheep_set)
        ans=cheep_one*n;

    else if(cheep_one*(n%6)<cheep_set)
        ans=cheep_set*(n/6)+cheep_one*(n%6);

    else if(n%6==0)
        ans=cheep_set*(n/6);

    else
        ans=cheep_set*(n/6+1);

    cout<<ans<<endl;
    return 0;
}