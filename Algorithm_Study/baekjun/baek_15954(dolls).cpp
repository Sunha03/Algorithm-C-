#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int n, k;
	double sum, avg, avgSum, var, dev, min;
	int doll[500] = { 0 };
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> doll[i];
	}

	for (int i = 0; i < n - k + 1; i++)
	{
		for (int m = k; m < n - i + 1; m++)
		{
			sum = 0;
			avgSum = 0;

			for (int j = i; j < i + m; j++)
			{
				sum += doll[j];
			}

			avg = sum / (double)m;
			for (int j = i; j < i + m; j++)
			{
				avgSum += (doll[j] - avg) * (doll[j] - avg);
			}
			var = avgSum / (double)m;
			dev = sqrt(var);

			if (i == 0 && m == k)
			{
				min = dev;
			}
			else if (min > dev)
			{
				min = dev;
			}
		}
	}

	printf("%.11lf\n", min);

	return 0;
}