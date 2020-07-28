#include <iostream>
#include <vector>

using namespace std;

bool isMove = true;
int n, L, R, num_group = 1, sum_people = 0, num_country = 0, answer = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int map[51][51] = { 0 };
vector<int> ave_people;

void findGroup(int x, int y, int (*arr_visit)[51], int (*arr_group)[51]) {
	arr_visit[x][y] = 1;			//�湮 ����
	arr_group[x][y] = num_group;	//���� ��ȣ
	sum_people += map[x][y];		//���� �� �� �ο���
	num_country++;					//���� �� ���� ��

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (arr_group[nx][ny] == 0) {		//�ٸ� �׷쿡 ���� ���� �ʰ�
				if (arr_visit[nx][ny] == 0) {		//�湮�� �� ����
					if (abs(map[nx][ny] - map[x][y]) >= L && abs(map[nx][ny] - map[x][y]) <= R) {	//�α� ���� ���� ���� ������
						findGroup(nx, ny, arr_visit, arr_group);
					}
				}
			}
		}
	}
}

int main() {
	cin >> n >> L >> R;		//input
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		cin >> map[i][j];

	while (isMove) {		//�α� �̵��� ���� ������
		int group[51][51] = { 0 };
		isMove = false;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (group[i][j] == 0) {
					int visit[51][51] = { 0 };
					sum_people = 0, num_country = 0;

					findGroup(i, j, visit, group);		//���� ã��

					if (num_country > 1) {		//���պ� ��� �α� ����
						ave_people.push_back(sum_people / num_country);
						isMove = true;
					}
					else {
						ave_people.push_back(sum_people);
					}

					num_group++;
				}
			}
		}

		for (int i = 0; i < n; i++)		//�α� �̵�
			for (int j = 0; j < n; j++)
				map[i][j] = ave_people[group[i][j] - 1];

		if (isMove)
			answer++;
	}

	cout << answer << endl;

	return 0;
}