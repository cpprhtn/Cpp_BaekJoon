#include <iostream>

using namespace std;

int main() {
	int arr[10001] = { 0 };
	for (int i = 1; i <= 10000; ++i) {
		int cnt = 0;
		int tmp = i;
		cnt += i;
		while (tmp) {
			cnt += tmp % 10;
			tmp /= 10;
		}
        if (cnt <= 10000) {
			arr[cnt]+=1;
		}
	}
	
	for (int i = 1; i <= 10000; ++i) {
		if (arr[i] == 0) {
			printf("%d\n", i);
		}
	}
}