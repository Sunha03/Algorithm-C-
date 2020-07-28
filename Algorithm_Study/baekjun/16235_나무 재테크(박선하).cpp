#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
	int x;
	int y;
	int z;
};

bool cmp(Tree &t1, Tree &t2) {
	if (t1.x == t2.x) {
		if (t1.y == t2.y) {
			return t1.z < t2.z;
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
	int n, m, k, answer = 0;
	int nutrient[11][11];
	int A[11][11];
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	vector<Tree> tree, live_tree, dead_tree, breeding;

	cin >> n >> m >> k;				//input & init
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			nutrient[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		Tree t;

		cin >> t.x;			cin >> t.y;			cin >> t.z;
		tree.push_back(t);
	}

	while (k-- != 0) {
		sort(tree.begin(), tree.end(), cmp);

		//Spring
		//양분 주기 & 나이++ or 죽음
		for (int i = 0; i < tree.size(); i++) {
			int x = tree[i].x;
			int y = tree[i].y;
			int age = tree[i].z;

			if (age <= nutrient[x - 1][y - 1]) {		//양분 주기
				nutrient[x - 1][y - 1] -= age;
				tree[i].z++;

				if (tree[i].z % 5 == 0)
					breeding.push_back({ x, y, tree[i].z });

				live_tree.push_back({ x, y, tree[i].z });
			}
			else {				//죽은 나무 저장
				dead_tree.push_back({ x, y, age / 2 });
			}
		}

		//Summer
		//죽은 나무 나이 / 2 >> 양분
		for (int i = 0; i < dead_tree.size(); i++)
			nutrient[dead_tree[i].x - 1][dead_tree[i].y - 1] += dead_tree[i].z;

		//Fall
		//나이 == 5의 배수 >> 주변에 나무 추가
		for (int i = 0; i < breeding.size(); i++) {
			int x = breeding[i].x;
			int y = breeding[i].y;

			for (int j = 0; j < 8; j++)
				if (x + dx[j] > 0 && x + dx[j] <= n && y + dy[j] > 0 && y + dy[j] <= n)
					live_tree.push_back({ x + dx[j], y + dy[j], 1 });
		}

		//Winter
		//양분 추가
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				nutrient[i][j] += A[i][j];

		tree = live_tree;
		live_tree.clear();
		dead_tree.clear();
		breeding.clear();
	}

	answer = tree.size();
	cout << answer << endl;

	return 0;
}