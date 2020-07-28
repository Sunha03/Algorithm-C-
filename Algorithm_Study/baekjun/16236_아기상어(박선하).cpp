#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
	int x;
	int y;
	int dis;
};

int n, sx = -1, sy = -1, answer = 0;
vector< vector<int> > space;
queue<Point> q;

void findFish(int size_shark) {
	int size = size_shark;
	int num_eat = 0;
	bool end = false, find = false;
	vector< vector<int> > visit;

	while (end == false) {			//먹을 수 있는 먹이 모두 먹음

		visit.clear();					//visit 초기화
		for (int i = 0; i < n; i++) {
			vector<int> v(n);
			visit.push_back(v);
		}

		visit[sx][sy] = 1;
		space[sx][sy] = 0;

		if (sx > 0)		//아기 상어의 상, 좌, 우, 하를 큐에 넣기
			q.push({ sx - 1, sy, 1 });
		if (sy > 0)
			q.push({ sx, sy - 1, 1 });
		if (sy < n - 1)
			q.push({ sx, sy + 1, 1 });
		if (sx < n - 1)
			q.push({ sx + 1, sy, 1 });

		while (find == false) {				//먹이 하나 찾기
			if (q.empty()) {				//전체 먹이 먹음 >> 끝
				end == true;
				return;
			}

			Point now = q.front();			//큐에서 하나씩 뽑아서
			q.pop();

			if (visit[now.x][now.y] == 0) {			//방문 X
				visit[now.x][now.y] = 1;

				if (space[now.x][now.y] < size && space[now.x][now.y] > 0 && space[now.x][now.y] < 7) {	//작은 물고기 먹기
					space[now.x][now.y] = 0;		//먹이 먹음
					num_eat++;						//먹이 개수 저장

					if (num_eat == size) {			//크기 증가
						size++;
						num_eat = 0;				//먹이 개수 초기화
					}

					sx = now.x;				//상어 위치 갱신
					sy = now.y;

					while (!q.empty())		//큐 비우기
						q.pop();

					answer += now.dis;		//거리 추가

					find = true;			//먹이 하나 찾음
				}
				else {		//(space[now.x][now.y] == size || space[now.x][now.y] == 0) >> 통과
					if (now.x > 0 && visit[now.x - 1][now.y] == 0)			//상, 좌, 우, 하 >> 큐 채우기
						q.push({ now.x - 1, now.y, now.dis + 1 });
					if (now.y > 0 && visit[now.x][now.y - 1] == 0)
						q.push({ now.x, now.y - 1, now.dis + 1 });
					if (now.y < n - 1 && visit[now.x][now.y + 1] == 0)
						q.push({ now.x, now.y + 1, now.dis + 1 });
					if (now.x < n - 1 && visit[now.x + 1][now.y] == 0)
						q.push({ now.x + 1, now.y, now.dis + 1 });
				}
			}
		}

		find = false;
	}
}

int main() {
	cin >> n;		//input
	for (int i = 0; i < n; i++) {
		vector<int> s(n);
		space.push_back(s);
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];

			if (space[i][j] == 9) {
				sx = i;
				sy = j;
			}
		}
	}

	findFish(2);

	cout << answer << endl;


	return 0;
}