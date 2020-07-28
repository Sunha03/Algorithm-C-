#include <iostream>
using namespace std;

int main()
{
	int n, x, y, z, count;
	cin >> n;

	if (n >= 1 && n < 100)
	{
		count = n;
	}
	else if (n >= 100)
	{
		count = 99;

		for (int i = 100; i <= n; i++)
		{
			x = i / 100;
			y = (i - x * 100) / 10;
			z = i - (x * 100 + y * 10);

			if ((x - y) == (y - z))
			{
				count++;
			}
		}
	}

	cout << count << "\n";
	return 0;
}