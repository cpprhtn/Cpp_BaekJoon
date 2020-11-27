#include <iostream>

int fact(int n)
{
    int k = 1;
    for(int i = 2; i <= n; i++)
    {
        k = k * i;
    }
    return k;
}

int main(){

    int result = 0;
    int a;
    std::cin >> a;
    result = fact(a);
    std::cout << result;
}