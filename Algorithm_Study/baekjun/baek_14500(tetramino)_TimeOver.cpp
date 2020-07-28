#include <iostream>
#include <vector>

using namespace std;

int m, n, num_max = 0, sum = 0;
vector< vector<int> > paper;
vector< vector<int> > visit;

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void initVec(vector< vector<int> > &vec) {
	vec.clear();
	for (int i = 0; i < n; i++) {
		vector<int> v(m);
		vec.push_back(v);
	}
}

void block(int x, int y, int count) {
	int num = 0;

	visit[x][y] = 1;
	sum += paper[x][y];

	if (count == 4) {
		if (num_max < sum) {
			num_max = sum;
		}
	}
	else {
		while (num != 4) {
			if (num == 0) {
				if (x > 0) {
					if (visit[x - 1][y] == 0) {
						block(x - 1, y, count + 1);
						visit[x - 1][y] = 0;
						sum -= paper[x - 1][y];
					}
				}
				num++;
			}
			else if (num == 1) {
				if (x < n - 1) {
					if (visit[x + 1][y] == 0) {
						block(x + 1, y, count + 1);
						visit[x + 1][y] = 0;
						sum -= paper[x + 1][y];
					}
				}
				num++;
			}
			else if (num == 2) {
				if (y > 0) {
					if (visit[x][y - 1] == 0) {
						block(x, y - 1, count + 1);
						visit[x][y - 1] = 1;
						sum -= paper[x][y - 1];
					}
				}
				num++;
			}
			else if (num == 3) {
				if (y < m - 1) {
					if (visit[x][y + 1] == 0) {
						block(x, y + 1, count + 1);
						visit[x][y + 1] = 1;
						sum -= paper[x][y + 1];
					}
				}
				num++;
			}
		}
	}
}

int main() {
	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<int> p(m);
		paper.push_back(p);
		visit.push_back(p);
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			initVec(visit);
			sum = 0;

			block(i, j, 1);
		}
	}

	for (int i = 0; i < n; i++) {							//で or ぬ
		for (int j = 0; j < m - 2; j++) {
			int three = 0;
			three = paper[i][j] + paper[i][j + 1] + paper[i][j + 2];

			if (i > 0) {
				three += paper[i - 1][j + 1];
				if (num_max < three) {
					num_max = three;
				}
				three -= paper[i - 1][j + 1];
			}
			if (i < n - 1) {
				three += paper[i + 1][j + 1];
				if (num_max < three) {
					num_max = three;
				}
				three -= paper[i + 1][j + 1];
			}
		}
	}

	for (int i = 0; i < n - 2; i++) {					//た or っ
		for (int j = 0; j < m; j++) {
			int three = 0;
			three = paper[i][j] + paper[i + 1][j] + paper[i + 2][j];

			if (j > 0) {
				three += paper[i + 1][j - 1];
				if (num_max < three) {
					num_max = three;
				}
				three -= paper[i + 1][j - 1];
			}
			if (j < m - 1) {
				three += paper[i + 1][j + 1];
				if (num_max < three) {
					num_max = three;
				}
				three -= paper[i + 1][j + 1];
			}
		}
	}


	cout << num_max << "\n";

	return 0;
}