#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;
int M, N;
int cnt;
vector<vector<int>> load;
vector<vector<int>> map;

void p(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i][0] << " " << v[i][1] << "\n";
	}
	cout << "\n";
}

bool isPassage(int px, int py, int x, int y, int fx, int fy) {
	if (map[x][y] == 0) {
		return true;
	}
	else if (map[x][y] == 1) {
		return false;
	}
	else if (map[x][y] == 2) {
		if ((x == px + 1 && y == py) && (fx == x + 1 && fy == y)) {
			return true;
		}
		else if ((x == px && y == py + 1) && (fx == x && fy == y + 1)) {
			return true;
		}
		else {
			return false;
		}
	}
}

void move(int x, int y, int px, int py) {
	int num = 0;

	if (x == M - 1 && y == N - 1) {
		cnt++;
	}
	else {
		while (num < 2) {
			if (num == 0) {
				load.push_back({ x + 1, y });

				if (isPassage(px, py, x, y, x + 1, y)) {
					if (x < M - 1) {
						move(x + 1, y, x, y);
					}
					else {
						load.pop_back();
					}
				}
				else {
					load.pop_back();
				}
				num++;
			}
			else if (num == 1) {
				load.push_back({ x, y + 1 });

				if (isPassage(px, py, x, y, x, y + 1)) {
					if (y < N - 1) {
						move(x, y + 1, x, y);
					}
					else {
						load.pop_back();
					}
				}
				else {
					load.pop_back();
				}
				num++;
			}
		}
	}
	load.pop_back();
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;

	M = m;
	N = n;
	cnt = 0;
	map = city_map;

	load.push_back({ 0, 0 });
	move(0, 0, 0, 0);

	answer = cnt % MOD;
	cout << cnt << ", " << answer << "\n";

	return answer;
}

int main()
{
	int m = 3;
	int n = 6;
	vector<vector<int>> city_map = {
		{ 0, 2, 0, 0, 0, 2 },
		{ 0, 0, 2, 0, 1, 0 },
		{ 1, 0, 0, 2, 2, 0 }
	};

	solution(m, n, city_map);
	return 0;
}

/*
int m = 3;
int n = 6;
vector<vector<int>> city_map = {
{ 0, 2, 0, 0, 0, 2 },
{ 0, 0, 2, 0, 1, 0 },
{ 1, 0, 0, 2, 2, 0 }
};
*/

/*
int m = 3;
int n = 3;
vector<vector<int>> city_map = {
{ 0, 0, 0 },
{ 0, 0, 0 },
{ 0, 0, 0 }
};
*/