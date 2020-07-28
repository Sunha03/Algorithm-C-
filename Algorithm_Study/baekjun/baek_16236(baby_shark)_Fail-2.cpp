#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, sx = -1, sy = -1, num_eat = 0, size_shark = 2, answer = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector< vector<int> > map, eat_fish, visit;

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

bool move(int nx, int ny) {
	bool end = false;
	int count = 0;
	queue< pair<int, int> > q;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		visit.push_back(v);
	visit[nx][ny] = 1;
	q.push({ nx, ny });

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		//cout << x << ", " << y << endl;

		if (map[x][y] < size_shark) {		//물고기 먹기
			num_eat++;		//먹은 물고기 수 + 1

			if (num_eat == size_shark) {	//상어 크기 + 1
				num_eat = 0;
				size_shark++;
			}

			map[sx][sy] = 0;		//상어 이동
			sx = x;		sy = y;
			map[sx][sy] = 9;

			answer += count;

			end = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
				if (map[x + dx[i]][y + dy[i]] <= size_shark && visit[x + dx[i]][y + dy[i]] == 0) {
					
					q.push({ x + dx[i], y + dy[i] });
				}
				visit[x + dx[i]][y + dy[i]] = 1;
			}
		}
		count++;
	}

	return end;
}

/*void find_fish() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] < size_shark && map[i][j] >= 1 && map[i][j] <= 6) {	//먹을 수 있는 물고기
				vector<int> v(n);
				for (int k = 0; k < n; k++)
					visit.push_back(v);
				
				visit[sx][sy] = 1;
				//eat_fish.push_back({ go_point(sx, sy, i, j), i, j });
			}
		}
	}
}

void move_shark() {
	while (1) {
		find_fish();		//먹을 수 있는 물고기 찾기

		sort(eat_fish.begin(), eat_fish.end());

		if (eat_fish[eat_fish.size() - 1][0] == -1)		//먹을 수 있는 물고기 X
			return;
		
		for (int i = 0; i < eat_fish.size(); i++) {
			if (eat_fish[i][0] != -1) {
				num_eat++;		//먹은 물고기 수 + 1

				if (num_eat == size_shark) {	//상어 크기 + 1
					num_eat = 0;
					size_shark++;
				}

				map[sx][sy] = 0;		//상어 이동
				sx = eat_fish[i][1];		sy = eat_fish[i][2];
				map[sx][sy] = 9;

				answer += eat_fish[i][0];

				break;
			}
		}
	}
}*/

int main() {
	cin >> n;		//input
	for (int i = 0; i < n; i++) {
		vector<int> v(n);
		map.push_back(v);

		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {	//아기 상어 위치
				sx = i;		sy = j;
			}
		}
	}

	//move_shark();

	while (move(sx, sy)) {

	}

	//p(visit);

	cout << answer << endl;

	return 0;
}