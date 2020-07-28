#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> answer;
void hanoi(int num, int start, int by, int end);

vector<vector<int>> solution(int n) {
	hanoi(n, 1, 2, 3);

	return answer;
}

void hanoi(int num, int start, int by, int end)
{
	vector<int> ans;
	if (num == 1)
	{
		ans.push_back(start);
		ans.push_back(end);
		answer.push_back(ans);
	}
	else
	{
		hanoi(num - 1, start, end, by);
		ans.push_back(start);
		ans.push_back(end);
		answer.push_back(ans);
		hanoi(num - 1, by, start, end);
	}

}