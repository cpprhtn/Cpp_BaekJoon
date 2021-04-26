#include <iostream>
#include <stack>

int n, Ieast, y[500000] = {};

int main() {
	int x;
	std::cin >> n;
	for (int i = 0; i < n; i++) {

		std::cin >> x >> y[i];
	}

	std::stack<int> s1;
	for (int i = 0; i <= n; i++) {
		for (; !s1.empty() && s1.top() > y[i]; Ieast++) {
			s1.pop();
		}

		if (!s1.empty() && s1.top() == y[i])
			continue;

		s1.push(y[i]);
	}
	std::cout << Ieast << std::endl;
}