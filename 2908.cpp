#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int a,b;
    string A,B;
    cin >>A>>B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    a= stoi(A);
    b= stoi(B);
    cout << (a>b?a:b);
}