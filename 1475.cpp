#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	char num[8];
	int count[10]={};
	scanf("%s", num);

	for(int i=0; num[i]; i++)
		count[num[i]-'0']++;

	int temp=(count[9]+count[6])/2+(count[9]+count[6])%2;
	count[9]=count[6]=temp;
	printf("%d", *(max_element(count, count+10)));
}
