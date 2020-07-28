#include <iostream>
#include <set>

using namespace std;

bool isMove = true;
int n, l, r, num_group = 1, answer = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int map[51][51] = { 0 }, group[51][51] = { 0 }, visit[51][51][4] = { 0 };
set< pair<int, int> > inGroup;

void findinGroup(int x, int y) {
	for (int i = 0; i < 4; i++) {		//4 방향 이동
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (group[nx][ny] == 0) {
				if (abs(map[nx][ny] - map[x][y]) >= l && abs(map[nx][ny] - map[x][y]) <= r) {		//인구 차이가 범위 내에 있으면
					for (int j = 0; j < 4; j++) {		//방문 여부 체크(4방향)
						if (nx - x == dx[j] && ny - y == dy[j]) {
							if (visit[nx][ny][j] == 0) {
								visit[nx][ny][j] = 1;
								group[nx][ny] = num_group;
								inGroup.insert({ nx, ny });	//그룹에 추가

								findinGroup(nx, ny);
							}

							break;
						}
					}
				}
			}
		}
	}
}

int main() {
	cin >> n >> l >> r;		//input
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	while (isMove) {
		isMove = false;

		//cout << "================================================\n";

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (group[i][j] == 0) {
					//cout << ">> " << i << ", " << j << " >>\n";
					int sum_people = 0;

					for (int k = 0; k < 4; k++)
						visit[i][j][k] = 1;
					group[i][j] = num_group;
					inGroup.insert({ i, j });
					findinGroup(i, j);		//연합 찾기

					if (inGroup.size() > 1) {		//연합이 있으면
						set< pair<int, int> >::iterator it;
						for (it = inGroup.begin(); it != inGroup.end(); ++it)	//그룹 총 인구수 계산
							sum_people += map[it->first][it->second];
						for (it = inGroup.begin(); it != inGroup.end(); ++it)	//인구 이동
							map[it->first][it->second] = sum_people / inGroup.size();


						/*cout << "------------ " << num_group << " ---------------\n";
						for (it = inGroup.begin(); it != inGroup.end(); ++it)	//인구 이동
							cout << it->first << ", " << it->second << endl;
							*/

						isMove = true;
					}

					num_group++;
					inGroup.clear();		//초기화
					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++)
							for (int k = 0; k < 4; k++)
								visit[i][j][k] = 0;


					/*for (int x = 0; x < n; x++) {
						for (int y = 0; y < n; y++) {
							cout << group[x][y] << " ";
						}cout << endl;
					}cout << endl;*/

				}
			}
		}

		if (isMove)
			answer++;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				group[i][j] = 0;

		/*cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << visit[i][j] << " ";
			}cout << endl;
		}cout << endl << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}cout << endl;
		}cout << endl;*/
	}

	cout << answer << endl;

	return 0;
}