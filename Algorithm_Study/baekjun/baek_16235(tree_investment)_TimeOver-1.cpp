#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, answer = 0;
int nutrient[11][11];
int A[11][11];
vector< vector<int> > dead_tree;
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

void spring() {
	vector< vector<int> > ::iterator it = tree.begin();

	while (it != tree.end()) {
		int x = it->at(0) - 1;
		int y = it->at(1) - 1;
		int z = it->at(2);

		if (z <= nutrient[x][y]) {		//양분 주기
			nutrient[x][y] -= z;
			it->at(2)++;
			it++;
		}
		else {						//죽은 나무 저장
			it = tree.erase(it);
			dead_tree.push_back({ x + 1,  y + 1, z / 2 });
		}
	}
}

void summer() {			//(죽은 나무 나이 / 2) 더하기
	for (int i = 0; i < dead_tree.size(); i++)
		nutrient[dead_tree[i][0] - 1][dead_tree[i][1] - 1] += dead_tree[i][2];

	dead_tree.clear();
}

void fall() {
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int i = 0; i < tree.size(); i++) {
		int z = tree[i][2];

		if (z % 5 == 0) {			//나무 추가
			int x = tree[i][0];
			int y = tree[i][1];

			for (int j = 0; j < 8; j++)
				if (x + dx[j] > 0 && x + dx[j] <= n && y + dy[j] > 0 && y + dy[j] <= n)
					tree.push_back({ x + dx[j], y + dy[j], 1 });
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++)		//양분 추가
		for (int j = 0; j < n; j++)
			nutrient[i][j] += A[i][j];
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
		sort(tree.begin(), tree.end());

		spring();
		summer();
		fall();
		winter();
	}

	answer = tree.size();
	cout << answer << endl;

	return 0;
}