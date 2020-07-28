#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
	int x;
	int y;
	int z;
};

bool cmp(Tree t1, Tree t2) {
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
	vector<Tree> dead_tree, tree;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			nutrient[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		Tree inputTree;

		cin >> inputTree.x;		cin >> inputTree.y;		cin >> inputTree.z;
		tree.push_back(inputTree);
	}

	while (k-- != 0) {
		sort(tree.begin(), tree.end(), cmp);

		//Spring
		vector<Tree> ::iterator it = tree.begin();
		while (it != tree.end()) {
			int x = it->x;
			int y = it->y;
			int age = it->z;

			if (age <= nutrient[x][y]) {		//양분 주기
				nutrient[x][y] -= age;
				it->z++;
				it++;
			}
			else {						//죽은 나무 저장
				it = tree.erase(it);
				dead_tree.push_back({ x + 1,  y + 1, age / 2 });
			}
		}

		//Summer
		for (int i = 0; i < dead_tree.size(); i++)
			nutrient[dead_tree[i].x - 1][dead_tree[i].y - 1] += dead_tree[i].z;

		dead_tree.clear();

		//Fall
		for (int i = 0; i < tree.size(); i++) {
			int age = tree[i].z;

			if (age % 5 == 0) {			//나무 추가
				int x = tree[i].x;
				int y = tree[i].y;

				for (int j = 0; j < 8; j++)
					if (x + dx[j] > 0 && x + dx[j] <= n && y + dy[j] > 0 && y + dy[j] <= n)
						tree.push_back({ x + dx[j], y + dy[j], 1 });
			}
		}

		//Winter
		for (int i = 0; i < n; i++)		//양분 추가
			for (int j = 0; j < n; j++)
				nutrient[i][j] += A[i][j];
	}

	answer = tree.size();
	cout << answer << endl;

	return 0;
}