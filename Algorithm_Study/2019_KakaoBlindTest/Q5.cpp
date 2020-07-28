#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool hCheck(vector<vector<int>> h, vector<vector<int>> v, int x, int y, int n) {
	if (y == 0)
		return true;
	else if (v[x][y + 1] == 1 && y < n - 2 || v[x - 1][y + 1] == 1 && y < n - 2 && x > 0)
		return true;
	else if (h[x][y - 1] == 1 && y > 0)
		return true;
	else
		return false;
}

bool vCheck(vector<vector<int>> h, vector<vector<int>> v, int x, int y, int n) {
	if (y == 0)
		return false;
	else if (h[x][y - 1] == 1 && y > 0 || h[x + 1][y - 1] == 1 && x < n - 2 && y > 0)
		return true;
	else if (v[x][y] == 1 || v[x - 1][y] && x > 0)
		return true;
	else
		return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	vector<vector<int>> h, v;

	vector<int> vec(n + 1);
	for (int i = 0; i <= n; i++) {
		h.push_back(vec);
		v.push_back(vec);
	}

	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];

		if (build_frame[i][2] == 0) {			//±âµÕ
			if (build_frame[i][3] == 0) {
				if(hCheck(h, v, x, y, n))
					h[x][y] = 0;
			}
			else if (build_frame[i][3] == 1) {
				if (hCheck(h, v, x, y, n))
					h[x][y] = 1;
			}
		}
		else if (build_frame[i][2] == 1) {		//º¸
			if (build_frame[i][3] == 0) {
				if (vCheck(h, v, x, y, n))
					v[x][y] = 0;
			}
			else if (build_frame[i][3] == 1) {
				if (vCheck(h, v, x, y, n))
					v[x][y] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (h[i][j] == 1)
				answer.push_back({ i, j, 0 });

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (v[i][j] == 1)
				answer.push_back({ i, j, 1 });

	sort(answer.begin(), answer.end());

	return answer;
}


int main() {
	vector<vector<int>> b = { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
	//vector<vector<int>> b = { {0,0,0,1} ,{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
	solution(5, b);

	return 0;
}