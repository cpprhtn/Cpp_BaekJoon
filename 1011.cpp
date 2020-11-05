#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	double x, y;
	vector<int> ans;

	scanf("%d", &t);

	while (t--) {
		scanf("%lf %lf", &x, &y);
		double i = 1, cnt = 0;

		for (;; i++) {
			if (i*i > y - x)
				break;
		}
		
		if ((i - 1)*(i - 1) == y - x) 
			cnt = 2 * (i - 1) - 1;

		else if ( (i-1)*(i-1)+((i*i - (i - 1)*(i - 1))/2) >= y-x ) 
			cnt = 2 * i - 2;
            
		else 
			cnt = 2 * i - 1;

		ans.push_back(cnt);
	}

	for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		printf("%d\n", *i);

	return 0;
}