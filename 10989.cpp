#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int num,tmp;
    int count[10001] = {0};
    scanf("%d",&num);

    for(int i = 0; i < num; i++)
    {
        scanf("%d",&tmp);
        count[tmp]++;
    }

    for(int i = 0; i < 10001; i++)
        for(int j = 0; j < count[i]; j++)
            printf("%d\n",i);
}