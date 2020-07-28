#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
	int x;
	int y;
	int z;
};

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

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
	vector<Tree> tree, dead_tree, breeding;

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
		vector<Tree> ::iterator it = tree.begin();
		while (it != tree.end()) {
			int x = it->x;
			int y = it->y;
			int age = it->z;

			if (age <= nutrient[x - 1][y - 1]) {		//��� �ֱ�
				nutrient[x - 1][y - 1] -= age;
				it->z++;

				if (it->z % 5 == 0)
					breeding.push_back({ x, y, it->z });

				it++;
			}
			else {						//���� ���� ���� & ����
				it = tree.erase(it);
				dead_tree.push_back({ x, y, age / 2 });
			}
		}

		//Summer
		for (int i = 0; i < dead_tree.size(); i++)
			nutrient[dead_tree[i].x - 1][dead_tree[i].y - 1] += dead_tree[i].z;

		//Fall
		for (int i = 0; i < breeding.size(); i++) {
			int x = breeding[i].x;
			int y = breeding[i].y;

			for (int j = 0; j < 8; j++)
				if (x + dx[j] > 0 && x + dx[j] <= n && y + dy[j] > 0 && y + dy[j] <= n)
					tree.push_back({ x + dx[j], y + dy[j], 1 });
		}

		//Winter
		for (int i = 0; i < n; i++)		//��� �߰�
			for (int j = 0; j < n; j++)
				nutrient[i][j] += A[i][j];

		dead_tree.clear();
		breeding.clear();
	}

	answer = tree.size();
	cout << answer << endl;

	return 0;
}