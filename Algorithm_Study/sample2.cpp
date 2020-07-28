#include <iostream>
#include <set>

using namespace std;

bool isMove = true;
int n, l, r, answer = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int map[51][51] = { 0 }, visit[51][51] = { 0 };
set< pair<int, int> > group;

void findGroup(int x, int y) {
	/*group.push_back({ x, y });	//그룹에 추가

	if (visit[x][y] == 1)		//방문 여부
		return;
	else
		visit[x][y] = 1;*/

	for (int i = 0; i < 4; i++) {		//4 방향 이동
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (abs(map[nx][ny] - map[x][y]) >= l && abs(map[nx][ny] - map[x][y]) <= r) {
				if (visit[nx][ny] == 0) {		//방문 X이면
					visit[nx][ny] = 1;
					group.insert({ x, y });
					//group.push_back({ x, y });	//그룹에 추가

					findGroup(nx, ny);
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
		//cout << "=====================================================\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) {
					int sum_people = 0;

					visit[i][j] = 1;
					group.insert({ i, j });
					findGroup(i, j);		//연합 찾기

					//cout << "( " << i << ", " << j << " )\n";

					if (group.size() > 1) {		//연합이 있으면
						set< pair<int, int> >::iterator it;
						for (it = group.begin(); it != group.end(); ++it)	//그룹 총 인구수 계산
							sum_people += map[it->first][it->second];
						for (it = group.begin(); it != group.end(); ++it)	//인구 이동
							map[it->first][it->second] = sum_people / group.size();

						/*cout << "------------- " << i << ", " << j << " -----------\n";
						for (it = group.begin(); it != group.end(); ++it)
							cout << it->first << ", " << it->second << endl;
						cout << endl;*/

						isMove = true;
					}

					group.clear();		//초기화
				}
			}
		}

		for (int i = 0; i < n; i++)		//방문 초기화
			for (int j = 0; j < n; j++)
				visit[i][j] = 0;

		if (isMove)
			answer++;

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