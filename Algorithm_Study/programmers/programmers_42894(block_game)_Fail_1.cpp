#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
};

int n, num_delete = 0, answer = 0;
vector<vector<int>> b, blocks, delete_blocks;
vector<vector<Point>> types;


void p(vector<vector<int>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

void findBlock() {
	for (int i = 0; i < blocks.size() / 4; i++) {
		vector<Point> type;
		int bx = blocks[4 * i][1];
		int by = blocks[4 * i][2];
		int num_type = 0;

		for (int j = 1; j < 4; j++) {
			int x = blocks[4 * i + j][1];
			int y = blocks[4 * i + j][2];

			type.push_back({ x - bx, y - by });

			bx = x;
			by = y;
		}

		while (num_type < 5) {		//제거 가능한 블록 찾기
			for (int j = 0; j < 3; j++) {
				if (type[j].x != types[num_type][j].x || type[j].y != types[num_type][j].y) {
					break;
				}
				if (j == 2) {
					switch (num_type) {
					case 0:
						delete_blocks.push_back({ blocks[4 * i][0], 1, num_type, blocks[4 * i + 2][1], blocks[4 * i + 2][2], blocks[4 * i + 3][1], blocks[4 * i + 3][2] });
						break;
					case 1:
						delete_blocks.push_back({ blocks[4 * i][0], 1, num_type, blocks[4 * i + 1][1], blocks[4 * i + 1][2], blocks[4 * i + 2][1], blocks[4 * i + 2][2] });
						break;
					case 2:
						delete_blocks.push_back({ blocks[4 * i][0], 1, num_type, blocks[4 * i + 1][1], blocks[4 * i + 1][2], blocks[4 * i + 3][1], blocks[4 * i + 3][2] });
						break;
					case 3:
					case 4:
						delete_blocks.push_back({ blocks[4 * i][0], 1, num_type, blocks[4 * i + 3][1], blocks[4 * i + 3][2] });
						break;

					}

					num_delete++;
					num_type = 5;
				}
			}
			num_type++;
		}
	}
}

void deleteBlock() {
	while (num_delete > 0) {
		bool bool_delete = false;
		for (int i = 0; i < delete_blocks.size(); i++) {
			if (delete_blocks[i][1] == 1) {			//제거 안된 블록
				if (delete_blocks[i][2] >= 0 && delete_blocks[i][2] <= 2) {
					int x1 = delete_blocks[i][3];
					int y1 = delete_blocks[i][4];
					int x2 = delete_blocks[i][5];
					int y2 = delete_blocks[i][6];

					while (--x1 >= 0)
						if (b[x1][y1] != 0)
							break;

					while (--x2 >= 0)
						if (b[x2][y2] != 0)
							break;

					if (x1 == -1 && x2 == -1) {		//블록 삭제
													//cout << delete_blocks[i][0] << endl;
						delete_blocks[i][1] = 0;
						num_delete--;
						bool_delete = true;
						answer++;

						for (int j = 0; j < blocks.size(); j++) {
							if (blocks[j][0] == delete_blocks[i][0]) {
								for (int k = 0; k < 4; k++) {
									//cout << blocks[j + k][1] << " " << blocks[j + k][2] << endl;
									b[blocks[j + k][1]][blocks[j + k][2]] = 0;
								}
								break;
							}
						}
					}
				}
				else if (delete_blocks[i][2] >= 4 && delete_blocks[i][2] <= 5) {
					int x1 = delete_blocks[i][3];
					int y1 = delete_blocks[i][4];

					while (--x1 >= 0)
						if (b[x1][y1] != 0)
							break;

					if (x1 == -1) {		//블록 삭제
										//cout << delete_blocks[i][0] << endl;
						delete_blocks[i][1] = 0;
						num_delete--;
						bool_delete = true;
						answer++;

						for (int j = 0; j < blocks.size(); j++) {
							if (blocks[j][0] == delete_blocks[i][0]) {
								for (int k = 0; k < 4; k++) {
									//cout << blocks[j + k][1] << " " << blocks[j + k][2] << endl;
									b[blocks[j + k][1]][blocks[j + k][2]] = 0;
								}
								break;
							}
						}
					}
				}
			}

			if (i == delete_blocks.size() - 1 && bool_delete == false) {
				return;
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	n = board.size();

	b = board;

	for (int i = 0; i < n; i++) {		//모든 색깔 블록 저장
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) {
				blocks.push_back({ board[i][j], i, j });
			}
		}
	}

	sort(blocks.begin(), blocks.end());

	types.push_back({ { 1, 0 },{ 0, 1 },{ 0, 1 } });
	types.push_back({ { 1, -2 },{ 0, 1 },{ 0, 1 } });
	types.push_back({ { 1, -1 },{ 0, 1 },{ 0, 1 } });
	types.push_back({ { 1, 0 },{ 1, 0 },{ 0, 1 } });
	types.push_back({ { 1, 0 },{ 1, 0 },{ 0, -1 } });

	findBlock();

	deleteBlock();

	//p(delete_blocks);
	//p(blocks);
	p(b);

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