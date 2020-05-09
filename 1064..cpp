#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cross(ll x1, ll y1, ll x2, ll y2)
{
    return x1*y2-x2*y1;
}

int main()
{
    ll x[3], y[3];
    double _min=1e22, _max=0;

    cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];

    for(int i=0; i<3; i++)
    {
        ll x1=x[(i+1)%3]-x[i], y1=y[(i+1)%3]-y[i], x2=x[(i+2)%3]-x[i], y2=y[(i+2)%3]-y[i];
        if(cross(x1, y1, x2, y2)==0) continue;
        double c=(sqrt(x1*x1+y1*y1)+sqrt(x2*x2+y2*y2))*2;
        _min=min(_min, c);
        _max=max(_max, c);
    }

    cout.precision(30);
    if(_max==0) cout<<-1;
    else cout<<_max-_min;
}