#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		priority_queue<double> Q;
		double sum=0, n;
		scanf("%lf", &n);
		for(double i=0; i<n; i++)
		{
			double num;
			scanf("%lf", &num);
			sum+=num;
			Q.push(-num);
		}
		sum/=n;
		while(!Q.empty())
		{
			if(-Q.top()>sum)
				break;

			Q.pop();
		}

		double ans=(double)Q.size()/n*1000000;
		if((int)ans%10>=5)
			ans+=1;

		ans/=10000;
		printf("%.3lf%%\n", ans);

	}
}
