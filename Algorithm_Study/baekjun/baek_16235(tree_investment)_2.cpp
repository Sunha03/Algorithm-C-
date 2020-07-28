#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree{
	int x;
	int y;
	int age;
};

int n, m, k, answer = 0;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int ground[11][11] = { 0 }, A[11][11] = { 0 };
vector<Tree> tree, live_tree, dead_tree;

bool cmp(Tree &t1, Tree &t2) {
	if (t1.x == t2.x) {
		if (t1.y == t2.y) {
			return t1.age < t2.age;
		}
		else {
			return t1.y < t2.y;
		}
	}
	else {
		return t1.x < t2.x;
	}
}

int main() {
	cin >> n >> m >> k;		//input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			ground[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		Tree t;

		cin >> t.x >> t.y >> t.age;
		tree.push_back(t);
	}

	while (k-- > 0) {
		sort(tree.begin(), tree.end(), cmp);

		for (int i = 0; i < tree.size(); i++) {		//봄
			int x = tree[i].x - 1, y = tree[i].y - 1, age = tree[i].age;
			if (ground[x][y] >= age) {
				ground[x][y] -= age;

				live_tree.push_back({ x + 1, y + 1, age + 1 });
				if ((age + 1) % 5 == 0) {		//가을
					for (int i = 0; i < 8; i++) {
						if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
							live_tree.push_back({ x + dx[i] + 1, y + dy[i] + 1, 1 });
						}
					}
				}
			}
			else {
				dead_tree.push_back({ x + 1, y + 1, age / 2 });
			}
		}

		for (int i = 0; i < dead_tree.size(); i++)		//여름
			ground[dead_tree[i].x - 1][dead_tree[i].y - 1] += dead_tree[i].age;

		for (int i = 0; i < n; i++)		//겨울
			for (int j = 0; j < n; j++)
				ground[i][j] += A[i][j];

		tree.clear();
		dead_tree.clear();
		tree = live_tree;
		live_tree.clear();
	}

	answer = tree.size();

	cout << answer << endl;

	return 0;
}
