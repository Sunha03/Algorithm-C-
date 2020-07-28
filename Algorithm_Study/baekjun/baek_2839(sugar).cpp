#include <iostream>
using namespace std;

int main()
{
	int n = 0, max = 0, min = -1, sum = 0;

	cin >> n;

	max = n / 5;
	for (int i = 0; i <= max; i++) {
		int remainder = n - (5 * i);
		if ((remainder % 3) == 0)
		{
			sum = i + (remainder / 3);
			if (sum <= min)
			{
				min = sum;
			}
			else if (min < 0)
			{
				min = sum;
			}
		}
	}

	if (sum == 0)
	{
		min = -1;
	}

	cout << "최소 봉지 개수 : " << min << endl;


	return min;
}