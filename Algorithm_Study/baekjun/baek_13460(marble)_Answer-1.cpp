#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n, answer;
int visit[10][10][10][10];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<int> r(2), b(2), o(2);
vector< vector<char> > input;

void upDown(int dir, vector<int> &v);
void leftRight(int dir, vector<int> &v);

void move() {
	queue< vector<int> > queue;			//rx, ry, bx, by
	queue.push({ r[0], r[1], b[0], b[1] });
	visit[r[0]][r[1]][b[0]][b[1]] = 1;

	while (queue.size()) {
		int size = queue.size();

		while (size--) {
			int rx = queue.front().at(0);
			int ry = queue.front().at(1);
			int bx = queue.front().at(2);
			int by = queue.front().at(3);
			queue.pop();

			if (input[rx][ry] == 'O' && input[rx][ry] != input[bx][by]) {
				return;
			}

			for (int i = 0; i < 4; i++) {
				int now_rx = rx;		int now_ry = ry;
				int now_bx = bx;		int now_by = by;

				while (input[now_rx + dx[i]][now_ry + dy[i]] != '#' && input[now_rx][now_ry] != 'O') {
					now_rx += dx[i];
					now_ry += dy[i];
				}

				while (input[now_bx + dx[i]][now_by + dy[i]] != '#' && input[now_bx][now_by] != 'O') {
					now_bx += dx[i];
					now_by += dy[i];
				}

				if (now_rx == now_bx && now_ry == now_by) {
					if (input[now_rx][now_ry] == 'O') {
						continue;
					}

					if (abs(now_rx - rx) + abs(now_ry - ry) < abs(now_bx - bx) + abs(now_by - by)) {
						now_bx -= dx[i];
						now_by -= dy[i];
					}
					else {
						now_rx -= dx[i];
						now_ry -= dy[i];
					}
				}

				if (visit[now_rx][now_ry][now_bx][now_by] == 1) {
					continue;
				}

				queue.push({ now_rx, now_ry, now_bx, now_by });
				visit[now_rx][now_ry][now_bx][now_by] = 1;
			}
		}

		if (answer == 10) {
			answer = -1;
			return;
		}

		answer++;
	}

	answer = -1;
	return;
}


int main() {
	//Input
	cin >> n >> m;
	answer = 0;

	for (int i = 0; i < n; i++) {
		vector<char> in(m);
		input.push_back(in);
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];

			if (input[i][j] == 'R') {
				r = { i, j };
			}
			else if (input[i][j] == 'B') {
				b = { i, j };
			}
			else if (input[i][j] == 'O') {
				o = { i, j };
			}
		}
	}

	move();

	cout << answer << "\n";

	return 0;
}