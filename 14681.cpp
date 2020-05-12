#include <cstdio>
using namespace std;
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if(a>0 && b>0){
		printf("1\n");
	}
	else if(a<0 && b>0){
		printf("2");
	}
	else if(a<0 && b<0){
		printf("3");
	}
	else{
		printf("4");
	}
	return 0;
}
