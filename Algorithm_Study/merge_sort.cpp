#include <iostream>
using namespace std;

#define SIZE 5

void printNum(int n[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << n[i] << " ";
	}
	cout << "\n";
}

void merge(int num[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	int temp[SIZE] = { 0 };

	while (i <= mid && j <= right)
	{
		if (num[i] < num[j])
		{
			temp[k] = num[i];
			i++;
		}
		else
		{
			temp[k] = num[j];
			j++;
		}
		k++;
	}

	if (i > mid)
	{
		for (int m = j; m <= right; m++)
		{
			temp[k] = num[m];
			k++;
		}
	}
	else
	{
		for (int m = i; m <= mid; m++)
		{
			temp[k] = num[m];
			k++;
		}
	}

	for (int m = left; m < right; m++)
	{
		num[m] = temp[m];
	}
}

void merge_sort(int num[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		merge_sort(num, left, mid);
		merge_sort(num, mid + 1, right);
		merge(num, left, mid, right);
	}

}

int main()
{
	int num[SIZE] = { 5, 2, 4, 3, 1 };

	printNum(num);

	merge_sort(num, 0, SIZE - 1);

	printNum(num);

	return 0;
}