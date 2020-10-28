#include <iostream>
int main()
{
    int a, b, c;
    std::cin>>a>>b>>c;
    std::cout<<(c>b?a/(c-b)+1:-1);
}