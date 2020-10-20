#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    char c;
    cin >> n;
    while(n--)
    {
        cin >> c;
        sum += (c- '0');
    }
    cout << sum;
}