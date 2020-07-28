#include <vector>
#include <iostream>

using namespace std;

int width;
int height;
int area;
vector<vector<int>> input;

void findArea(int x, int y, int color)
{
	if (input[x][y] == color)
	{
		area++;
		input[x][y] = 0;
	}
	else
	{
		return;
	}

	if (x > 0)
	{
		findArea(x - 1, y, color);
	}
	if (y > 0)
	{
		findArea(x, y - 1, color);
	}
	if (y < width - 1)
	{
		findArea(x, y + 1, color);
	}
	if (x < height - 1)
	{
		findArea(x + 1, y, color);
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	height = m;
	width = n;
	input = picture;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (input[i][j] != 0)
			{
				area = 0;
				findArea(i, j, input[i][j]);

				number_of_area++;

				if (max_size_of_one_area < area)
				{
					max_size_of_one_area = area;
				}
			}
		}
	}
	cout << "영역 개수 : " << number_of_area << ", 최대 영역 사이즈 : " << max_size_of_one_area << "\n";

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main()
{
	vector<vector<int>> input = {
		{1, 1, 1, 0},
		{1, 2, 2, 0},
		{1, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 3},
		{0, 0, 0, 3}
	};

	solution(6, 4, input);

	return 0;
}