#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    bool cup[4]={0, };
    cup[1]=1;

    int no_case;
    cin>>no_case;
    for(int i=0; i<no_case; i++)
    {
        int n1, n2;
        cin>>n1>>n2;
        swap(cup[n1], cup[n2]);
    }

    for(int i=1; i<4; i++)
    {
        if(cup[i])
        {
            cout<<i<<endl;
            break;
        }

    }
    return 0;
}
