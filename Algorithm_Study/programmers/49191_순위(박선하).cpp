#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<int>> graph;

	for (int i = 0; i < n; i++)
	{
		vector<int> g(n);
		graph.push_back(g);
	}

	for (int i = 0; i < n; i++)
	{
		graph[i][i] = 1;
	}

	for (int i = 0; i < results.size(); i++)
	{
		int win = results[i][0];
		int lose = results[i][1];
		graph[win - 1][lose - 1] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[j][i] == 1)
			{
				for (int k = 0; k < n; k++)
				{
					if (graph[i][k] == 1)
					{
						graph[j][k] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int x = 1;
		for (int j = 0; j < n; j++)
		{
			if ((graph[i][j] == 0) && (graph[j][i] == 0))
			{
				x = 0;
				break;
			}
		}

		if (x == 1)
		{
			answer++;
		}
	}

	return answer;
}