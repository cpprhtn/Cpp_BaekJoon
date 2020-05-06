#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int no_case;
	cin >> no_case;
	for (int i = 0; i < no_case; i++)
	{
		int cho[2], baek[2];
		int r1, r2;
		int distance;
		int result;
		cin >> cho[0] >> cho[1] >> r1;
		cin >> baek[0] >> baek[1] >> r2;

		if (cho[0] == baek[0] && cho[1] == baek[1] && r1 == r2)
			result= -1;

		else
		{
			distance = pow(cho[0] - baek[0], 2) + pow(cho[1] - baek[1], 2);

			if (distance == (int)pow(r1 + r2, 2))
				result = 1;

			else if (distance > (int)pow(r1 + r2, 2))
				result = 0;

			else
				if (distance == (int)pow(abs(r1 - r2), 2))
					result = 1;

				else if (distance < (int)pow(abs(r1 - r2), 2))
					result = 0;

				else
					result = 2;

		}

		cout << result << endl;
	}

	return 0;
}
