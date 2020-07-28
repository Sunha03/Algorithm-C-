#include <iostream>
using namespace std;

#define SIZE 8

void printArr(int n[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << n[i] << " ";
	}
	cout << endl;
}

void swap(int * n1, int * n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void quick_sort(int n[], int start, int end)
{
	int *pivot = &n[start];
	int left = start + 1;
	int right = end;

	while (left < right)
	{
		while ((n[right] > *pivot) && (left < right))
		{
			right--;
		}
		while ((n[left] < *pivot) && (left < right))
		{
			left++;
		}

		if (left < right)
		{
			swap(&n[left], &n[right]);
		}
	}

	if (start < end)
	{
		swap(pivot, &n[right]);

		quick_sort(n, start, right - 1);
		quick_sort(n, right + 1, end);
	}


}

int main()
{
	int num[SIZE] = { 3, 5, 6, 4, 8, 1, 2, 7 };
	printArr(num);

	quick_sort(num, 0, SIZE - 1);

	printArr(num);


	return 0;
}