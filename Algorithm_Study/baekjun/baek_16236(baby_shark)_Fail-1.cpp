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

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

void pq(queue<Point> queue) {
	int size = queue.size();
	while (size-- > 0) {
		cout << queue.front().x << " " << queue.front().y << " " << queue.front().dis << endl;
		queue.pop();
	}cout << endl;
}

void findFish(int size_shark) {
	int size = size_shark;
	int num_eat = 0;
	bool end = false, find = false;
	vector< vector<int> > visit;

	while (end == false) {			//���� �� �ִ� ���� ��� ����

		visit.clear();					//visit �ʱ�ȭ
		for (int i = 0; i < n; i++) {
			vector<int> v(n);
			visit.push_back(v);
		}

		visit[sx][sy] = 1;
		space[sx][sy] = 0;

		if (sx > 0)		//�Ʊ� ����� ��, ��, ��, �ϸ� ť�� �ֱ�
			q.push({ sx - 1, sy, 1 });
		if (sy > 0)
			q.push({ sx, sy - 1, 1 });
		if (sy < n - 1)
			q.push({ sx, sy + 1, 1 });
		if (sx < n - 1)
			q.push({ sx + 1, sy, 1 });

		while (find == false) {				//���� �ϳ� ã��
			if (q.empty()) {				//��ü ���� ���� >> ��
				cout << "TTTTTTTTTTTThe End!!!!!!!!!!\n";
				end == true;
				return;
			}

			Point now = q.front();			//ť���� �ϳ��� �̾Ƽ�
			q.pop();

			if (visit[now.x][now.y] == 0) {			//�湮 X
				visit[now.x][now.y] = 1;

				if (space[now.x][now.y] < size && space[now.x][now.y] > 0 && space[now.x][now.y] < 7) {	//���� ����� �Ա�
					space[now.x][now.y] = 0;		//���� ����
					num_eat++;						//���� ���� ����

					if (num_eat == size) {			//ũ�� ����
						size++;
						num_eat = 0;				//���� ���� �ʱ�ȭ
					}

					sx = now.x;				//��� ��ġ ����
					sy = now.y;

					while (!q.empty())		//ť ����
						q.pop();

					answer += now.dis;		//�Ÿ� �߰�

					/*cout << "------------eat------------\n";*/
					cout << "(" << now.x << ", " << now.y << ") : " << now.dis << endl;
					cout << "eat : " << num_eat << ", size : " << size << endl;
					p(space);

					find = true;
				}
				else/* if (space[now.x][now.y] == size || space[now.x][now.y] == 0)*/ {		//���

					/*cout << "------------pass-----------\n";
					cout << now.x << ", " << now.y << endl;
					p(space);*/

					if (now.x > 0 && visit[now.x - 1][now.y] == 0)			//��, ��, ��, �� >> ť ä���
						q.push({ now.x - 1, now.y, now.dis + 1 });
					if (now.y > 0 && visit[now.x][now.y - 1] == 0)
						q.push({ now.x, now.y - 1, now.dis + 1 });
					if (now.y < n - 1 && visit[now.x][now.y + 1] == 0)
						q.push({ now.x, now.y + 1, now.dis + 1 });
					if (now.x < n - 1 && visit[now.x + 1][now.y] == 0)
						q.push({ now.x + 1, now.y, now.dis + 1 });
				}
				/*else if (space[now.x][now.y] > size) {		//ū ����� >> �� ���� �� X
					cout << "------------big fish-----------\n";
					cout << now.x << ", " << now.y << endl;
					p(space);
				}*/
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