#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int M, N, ans = 0;

bool findBox(vector<vector<char>> &map) {		//4블록 찾기
	int idx = 0;
	vector<vector<int>> same;
	int dx[4] = { 0, 1, 0, 1 };
	int dy[4] = { 0, 0, 1, 1 };

	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == '0')
				continue;

			if (map[i][j] == map[i + 1][j] && map[i][j] == map[i][j + 1]
				&& map[i][j] == map[i + 1][j + 1]) {
				same.push_back({ i, j });
			}
		}
	}

	if (same.size() == 0) {
		return false;
	}

	for (int i = 0; i < same.size(); i++) {
		int x = same[i][0];
		int y = same[i][1];

		for (int j = 0; j < 4; j++) {
			if (map[x + dx[j]][y + dy[j]] != '0') {
				map[x + dx[j]][y + dy[j]] = '0';
				ans++;
			}
		}
	}

	return true;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	vector<vector<char>> input;

	M = m;      N = n;
	for (int i = 0; i < board.size(); i++) {
		vector<char> v(n);
		input.push_back(v);

		char * ch = strdup(board[i].c_str());

		for (int j = 0; j < n; j++)
			input[i][j] = ch[j];
	}

	while (findBox(input)) {
		for (int j = 0; j < n; j++) {			//내리기
			int zero = 0, idx = 0;
			vector<char> line;

			for (int i = m - 1; i >= 0; i--) {
				if (input[i][j] != '0')
					line.push_back(input[i][j]);
				else
					zero++;
			}

			for (int i = 0; i < zero; i++)
				line.push_back('0');

			for (int i = m - 1; i >= 0; i--) {
				input[i][j] = line[idx];
				idx++;
			}
		}
	}

	answer = ans;

	return answer;
}