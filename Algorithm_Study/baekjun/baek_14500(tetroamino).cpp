#include <iostream>
#include <vector>

using namespace std;

int m, n, num_max = 0;
vector < vector<int> > paper;

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void findVertical(int x, int y, int dir) {
	int n = 0, sum = 0;
	int square[6];
	int arr[10][2] = { {0, 1}, {0, 2}, {0, 3}, {0, 5}, {1, 2}, {2, 3}, {2, 5}, {3, 4}, {3, 5}, {4, 5} };

	if (dir == 0) {
		int num[6] = { 0, 3, 1, 4, 2, 5 };

		for (int i = x; i < x + 3; i++) {
			for (int j = y; j < y + 2; j++) {
				square[num[n++]] = paper[i][j];
				sum += paper[i][j];
			}
		}
	}
	else if (dir == 1) {
		int num[6] = { 0, 1, 2, 3, 4, 5 };

		for (int i = x; i < x + 2; i++) {
			for (int j = y; j < y + 3; j++) {
				square[num[n++]] = paper[i][j];
				sum += paper[i][j];
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			sum -= (square[arr[i][0]] + square[arr[i][1]]);

			if (num_max < sum) {
				num_max = sum;
			}

			sum += (square[arr[i][0]] + square[arr[i][1]]);
		}
	}
}

int main() {
	cin >> n >> m;						//input
	for (int i = 0; i < n; i++) {
		vector<int> p(m);
		paper.push_back(p);
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n - 2; i++) {			//3 X 2
		for (int j = 0; j < m - 1; j++) {
			findVertical(i, j, 0);
		}
	}

	for (int i = 0; i < n - 1; i++) {			//2 X 3
		for (int j = 0; j < m - 2; j++) {
			findVertical(i, j, 1);
		}
	}

	for (int i = 0; i < n; i++) {				//1 X 4
		for (int j = 0; j < m - 3; j++) {
			int sum = 0;
			sum += (paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3]);

			if (num_max < sum) {
				num_max = sum;
			}
		}
	}

	for (int i = 0; i < n - 3; i++) {				//4 X 1
		for (int j = 0; j < m; j++) {
			int sum = 0;
			sum += (paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j]);

			if (num_max < sum) {
				num_max = sum;
			}
		}
	}

	cout << num_max << "\n";

	return 0;
}