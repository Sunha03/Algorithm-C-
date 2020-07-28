#include <iostream>
using namespace std;

int main()
{
	int x, y, day;
	int sum = 0;
	cin >> x >> y;

	for (int i = 1; i < x; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 31)
		{
			sum += 31;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11)
		{
			sum += 30;
		}
		else if (i == 2)
		{
			sum += 28;
		}
	}
	sum += y;
	day = sum % 7;

	switch (day)
	{
	case 1:
		cout << "MON\n";
		break;
	case 2:
		cout << "TUE\n";
		break;
	case 3:
		cout << "WED\n";
		break;
	case 4:
		cout << "THU\n";
		break;
	case 5:
		cout << "FRI\n";
		break;
	case 6:
		cout << "SAT\n";
		break;
	case 0:
		cout << "SUN\n";
		break;
	}

	return 0;
}