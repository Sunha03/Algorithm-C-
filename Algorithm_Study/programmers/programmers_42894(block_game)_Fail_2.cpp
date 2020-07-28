#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
};

int n, num_delete = 0;
int block_number[201] = { 0 };
vector<vector<int>> blocks, Board;
vector<vector<Point>> types;

void p(vector<vector<int>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

bool blackBlock(int x, int y) {
	int nx = 0;
	bool end = false;

	while (nx != x) {
		if (Board[nx][y] == 0)
			nx++;
		else
			return false;
	}

	if (nx == x)
		return true;
}

int solution(vector<vector<int>> board) {
	int answer = 0;

	Board = board;
	n = board.size();
	types.push_back({ {-99, -99}, {-99, -99}, {-99, -99} });
	types.push_back({ { 1, 0 },{ 0, 1 },{ 0, 1 } });
	types.push_back({ { 1, -2 },{ 0, 1 },{ 0, 1 } });
	types.push_back({ { 1, -1 },{ 0, 1 },{ 0, 1 } });
	types.push_back({ { 1, 0 },{ 1, 0 },{ 0, 1 } });
	types.push_back({ { 1, 0 },{ 1, 0 },{ 0, -1 } });

	for (int i = 0; i < n; i++) {			//블록 색깔, x, y >> 2차원 vector로 저장
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) {
				blocks.push_back({ board[i][j], i, j });
				block_number[board[i][j]] = -1;
			}
		}
	}

	sort(blocks.begin(), blocks.end());

	for (int i = 0; i < blocks.size() / 4; i++) {		//제거 가능 블록 찾기
		vector<Point> now;
		for (int j = 0; j < 3; j++) {
			int x = blocks[i * 4 + j + 1][1] - blocks[i * 4 + j][1];
			int y = blocks[i * 4 + j + 1][2] - blocks[i * 4 + j][2];
			now.push_back({ x, y });
		}

		for (int j = 1; j <= 5; j++) {
			bool inTypes;
			for (int k = 0; k < 3; k++) {
				inTypes = false;
				if (types[j][k].x == now[k].x && types[j][k].y == now[k].y) {
					if (k == 2) {		//제거할 수 있는 5가지 블록 중 하나
						inTypes = true;
						block_number[blocks[i * 4][0]] = j;
						num_delete++;
					}
				}
				else {
					break;
				}
			}

			if (inTypes == true)
				break;
		}
	}

	bool end = false;
	while (num_delete > 0) {
		end = false;

		for (int i = 0; i < blocks.size() / 4; i++) {
			switch (block_number[blocks[i * 4][0]]) {
			case 1:
				if (blackBlock(blocks[i * 4 + 2][1], blocks[i * 4 + 2][2]) &&	//블록 제거
					blackBlock(blocks[i * 4 + 3][1], blocks[i * 4 + 3][2])) {
					for (int j = 0; j < 4; j++)
						board[blocks[i * 4 + j][1]][blocks[i * 4 + j][2]] = 0;
					block_number[blocks[i * 4][0]] = -1;
					num_delete--;
					end = true;
					Board = board;
					answer++;
				}

				break;
			case 2:
				if (blackBlock(blocks[i * 4 + 1][1], blocks[i * 4 + 1][2]) &&	//블록 제거
					blackBlock(blocks[i * 4 + 2][1], blocks[i * 4 + 2][2])) {
					for (int j = 0; j < 4; j++)
						board[blocks[i * 4 + j][1]][blocks[i * 4 + j][2]] = 0;
					block_number[blocks[i * 4][0]] = -1;
					num_delete--;
					end = true;
					Board = board;
					answer++;
				}
				break;
			case 3:
				if (blackBlock(blocks[i * 4 + 1][1], blocks[i * 4 + 1][2]) &&	//블록 제거
					blackBlock(blocks[i * 4 + 3][1], blocks[i * 4 + 3][2])) {
					for (int j = 0; j < 4; j++)
						board[blocks[i * 4 + j][1]][blocks[i * 4 + j][2]] = 0;
					block_number[blocks[i * 4][0]] = -1;
					num_delete--;
					end = true;
					Board = board;
					answer++;
				}
				break;
			case 4:
				if (blackBlock(blocks[i * 4 + 3][1], blocks[i * 4 + 3][2])) {
					for (int j = 0; j < 4; j++)
						board[blocks[i * 4 + j][1]][blocks[i * 4 + j][2]] = 0;
					block_number[blocks[i * 4][0]] = -1;
					num_delete--;
					end = true;
					Board = board;
					answer++;
				}
				break;
			case 5:
				if (blackBlock(blocks[i * 4 + 2][1], blocks[i * 4 + 2][2])) {
					for (int j = 0; j < 4; j++)
						board[blocks[i * 4 + j][1]][blocks[i * 4 + j][2]] = 0;
					block_number[blocks[i * 4][0]] = -1;
					num_delete--;
					end = true;
					Board = board;
					answer++;
				}
				break;
			}
		}

		if (end == false)
			break;
	}

	/*for (int i = 1; i < 10; i++) {
		cout << i << " : " << block_number[i] << endl;
	}cout << endl;*/

	//p(blocks);
	//p(board);

	cout << answer << endl;

	return answer;
}

int main() {
	vector<vector<int>> b = {
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,4,0,0,0 },
		{ 0,0,0,0,0,4,4,0,0,0 },
		{ 0,0,0,0,3,0,4,0,0,0 },
		{ 0,0,0,2,3,0,0,0,5,5 },
		{ 1,2,2,2,3,3,0,0,0,5 },
		{ 1,1,1,0,0,0,0,0,0,5 }
	};
	solution(b);

	return 0;
}