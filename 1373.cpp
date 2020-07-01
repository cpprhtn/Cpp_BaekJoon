#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    map<string, char> M;
    M["000"]='0', M["001"]='1', M["010"]='2';
    M["011"]='3', M["100"]='4', M["101"]='5';
    M["110"]='6', M["111"]='7';
    string str;
    cin>>str;
    switch(str.size()%3)
    {
    case 1:
        str="00"+str;break;
    case 2:
        str="0"+str;break;
    }

    for(int i=0; i<str.size(); i+=3)
        cout<<M[str.substr(i, 3)];
}
