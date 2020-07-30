#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	queue<int> Queue;
	int num, count=0;
	scanf("%d", &num);
	Queue.push(num);
	Queue.push(-1);
	while(1)
	{
		num=Queue.front();
		Queue.pop();
		if(num==1)
			break;

		if(num==-1)
		{
			count++;
			Queue.push(-1);
			continue;
		}

		if(num<=0)
			continue;

		if(num%3==0)
			Queue.push(num/3);

		if(num%2==0)
			Queue.push(num/2);

		Queue.push(num-1);
	}

	printf("%d", count);
}
