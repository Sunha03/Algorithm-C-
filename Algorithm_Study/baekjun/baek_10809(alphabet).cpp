#include <iostream>
using namespace std;

int main()
{
	int alphabet[26];
	char word[100] = { 0 };

	cin >> word;

	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = -1;
	}

	for (int i = 0; i < 100; i++)
	{
		int index = (int)word[i] - 97;

		if (alphabet[index] == -1)
		{
			alphabet[index] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i];
		if (i != 25)
		{
			cout << " ";
		}
		else
		{
			cout << "\n";
		}
	}

	return 0;
}