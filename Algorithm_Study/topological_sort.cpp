#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	int indegree[101] = { 0 };
	vector<vector<int>> graph;
	queue<int> q;

	for (int i = 0; i <= n; i++)
	{
		vector<int> g;
		graph.push_back(g);
	}

	for (int i = 0; i < n; i++)
	{
		int win, lose;
		win = results[i][0];
		lose = results[i][1];

		indegree[lose]++;
		graph[win].push_back(lose);
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << " ";

		for (int i = 0; i < graph[now].size(); i++)
		{
			indegree[graph[now][i]]--;
			if (indegree[graph[now][i]] == 0)
			{
				q.push(graph[now][i]);
			}
		}
	}

	/*for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}*/


	return answer;
}

int main()
{
	vector<vector<int>> v = {
		{ 4, 3 },
		{ 4, 2 },
		{ 3, 2 },
		{ 1, 2 },
		{ 2, 5 } };

	solution(5, v);
}