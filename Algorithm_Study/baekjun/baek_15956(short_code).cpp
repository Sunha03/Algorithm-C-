#include <iostream>
#include <vector>
using namespace std;

#define SIZE 1000000

string findRight(char ch[], int start)
{
	int end;
	char chRes[SIZE];
	string res;

	for (int i = start; i < SIZE; i++)
	{
		if (ch[i] == '=' || ch[i] == '!' || ch[i] == '&')
		{
			end = i - 1;
			break;
		}
	}

	for (int i = 0; i < end - start + 1; i++)
	{
		chRes[i] = ch[start + i];
	}
	res = chRes;

	return res;
}

int main()
{
	int index = 0;
	char str[SIZE] = { 0 };
	vector<string, string> sam;
	vector<string, string> dif;
	cin >> str;

	for (int i = 0; i < SIZE; i++)
	{
		if (str[i] == '\0')
		{
			printf("The End!!!!!!!!!!!!!!!!\n");
			break;
		}

		if ((str[i] == '=') && (str[i + 1] == '='))					//==
		{
			for (int j = index; j < i; j++)
			{
				string right = findRight(str, i + 2);				//sam 벡터에 양쪽 데이터를 저장


				index = i + 2;
			}
		}
		else if ((str[i] == '!') && (str[i + 1] == '='))			//!=
		{

		}
		else if ((str[i] == '&') && (str[i + 1] == '&'))			//&&
		{

		}
	}

	return 0;
}