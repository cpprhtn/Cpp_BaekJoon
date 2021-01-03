#include <iostream>
#include <cstring> //memset
using namespace std;

const int MAX = 20 + 1;

int a, b, c;
int cache[MAX][MAX][MAX];
int w(int a, int b, int c)
{
    //문제에서 제시한 기저 사례 2가지
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a >= MAX || b >= MAX || c >= MAX)
        return w(20, 20, 20);

    int &result = cache[a][b][c];

    if (result != 0)
        return result;


    //나머지 조건 2가지
    if (a < b && b < c)
        result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

    else
        result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

    return result;

}


int main(void)
{
    while (1)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;
            
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;

    }

    return 0;
}
