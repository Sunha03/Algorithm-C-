#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, answer = 0;
int nutrient[11][11];
int A[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector< vector<int> > tree;

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			nutrient[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		vector<int> t(3);
		tree.push_back(t);

		for (int j = 0; j < 3; j++)
			cin >> tree[i][j];
	}

	while (k-- != 0) {
		vector< vector<int> > live_tree, dead_tree, breeding;

		sort(tree.begin(), tree.end());

		//Spring
		for (int i = 0; i < tree.size(); i++) {
			int x = tree[i][0];
			int y = tree[i][1];
			int z = tree[i][2];

			if (z <= nutrient[x - 1][y - 1]) {		//양분 주기
				nutrient[x - 1][y - 1] -= z;
				tree[i][2]++;

				if (tree[i][2] % 5 == 0)
					breeding.push_back({ x, y, tree[i][2] });

				live_tree.push_back({ x, y, tree[i][2] });
			}
			else {						//죽은 나무 저장
				dead_tree.push_back({ x,  y, z / 2 });
			}
		}

		//Summer
		for (int i = 0; i < dead_tree.size(); i++)
			nutrient[dead_tree[i][0] - 1][dead_tree[i][1] - 1] += dead_tree[i][2];

		//Fall
		for (int i = 0; i < breeding.size(); i++) {
			int x = breeding[i][0];
			int y = breeding[i][1];

			for (int j = 0; j < 8; j++)
				if (x + dx[j] > 0 && x + dx[j] <= n && y + dy[j] > 0 && y + dy[j] <= n)
					live_tree.push_back({ x + dx[j], y + dy[j], 1 });
		}

		//Winter
		for (int i = 0; i < n; i++)		//양분 추가
			for (int j = 0; j < n; j++)
				nutrient[i][j] += A[i][j];

		tree = live_tree;
	}

	answer = tree.size();
	cout << answer << endl;

	return 0;
}