#include <cstdio>
#include <cmath>
int main()
{
    float c, h, w;
    scanf("%f %f %f", &c, &h, &w);

    float a, b;
    a=(c*c)*(h*h/(w*w+h*h));
    b=c*c-a;

    printf("%d %d", (int)sqrt(a), (int)sqrt(b));
}
