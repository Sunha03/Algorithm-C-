#include <iostream>
#include <vector>

using namespace std;

int n, m, k, num_min = 100;
vector< vector<int> > office;
vector< vector<int> > watch;

void(*direction[4])(int, int, vector< vector<int> > &);

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void up(int x, int y, vector< vector<int> > &vec) {
	if (x > 0) {
		while (x > 0 && vec[x - 1][y] != 6) {
			x--;
			vec[x][y] = 8;
		}
	}
}

void down(int x, int y, vector< vector<int> > &vec) {
	if (x < n - 1) {
		while (x < n - 1 && vec[x + 1][y] != 6) {
			x++;
			vec[x][y] = 8;
		}
	}
}

void left(int x, int y, vector< vector<int> > &vec) {
	if (y > 0) {
		while (y > 0 && vec[x][y - 1] != 6) {
			y--;
			vec[x][y] = 8;
		}
	}
}

void right(int x, int y, vector< vector<int> > &vec) {
	if (y < m - 1) {
		while (y < m - 1 && vec[x][y + 1] != 6) {
			y++;
			vec[x][y] = 8;
		}
	}
}

void dfs(vector< vector<int> > v, int n_cmr, int num) {
	vector< vector<int> > vec = v;

	if (num == watch.size()) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vec[i][j] == 0) {		//0 °³¼ö count
					count++;
				}
			}
		}

		if (count < num_min) {
			num_min = count;

			cout << "-------min : " << min << "---------\n";
			p(vec);
		}

		return;
	}

	int x = watch[n_cmr][1];
	int y = watch[n_cmr][2];

	if (watch[n_cmr][0] == 1) {
		for (int i = 0; i < 4; i++) {
			vec = v;
			direction[i](x, y, vec);
			dfs(vec, n_cmr + 1, num + 1);
		}
	}
	else if (watch[n_cmr][0] == 2) {
		for (int i = 0; i < 2; i++) {
			vec = v;
			direction[i](x, y, vec);
			direction[i + 2](x, y, vec);
			dfs(vec, n_cmr + 1, num + 1);
		}
	}
	else if (watch[n_cmr][0] == 3) {
		for (int i = 0; i < 3; i++) {
			vec = v;
			direction[i](x, y, vec);
			direction[i + 1](x, y, vec);
			dfs(vec, n_cmr + 1, num + 1);
		}

		vec = v;
		direction[3](x, y, vec);
		direction[0](x, y, vec);
		dfs(vec, n_cmr + 1, num + 1);
	}
	else if (watch[n_cmr][0] == 4) {
		for (int i = 0; i < 2; i++) {
			vec = v;
			direction[i](x, y, vec);
			direction[i + 1](x, y, vec);
			direction[i + 2](x, y, vec);
			dfs(vec, n_cmr + 1, num + 1);
		}

		vec = v;
		direction[2](x, y, vec);
		direction[3](x, y, vec);
		direction[0](x, y, vec);
		dfs(vec, n_cmr + 1, num + 1);

		vec = v;
		direction[3](x, y, vec);
		direction[0](x, y, vec);
		direction[1](x, y, vec);
		dfs(vec, n_cmr + 1, num + 1);
	}
	else if (watch[n_cmr][0] == 5) {
		for (int i = 0; i < 4; i++) {
			direction[i](x, y, vec);
		}
		dfs(vec, n_cmr + 1, num + 1);
	}
}

int main() {
	cin >> n >> m;						//input
	for (int i = 0; i < n; i++) {
		vector<int> v(m);
		office.push_back(v);
		for (int j = 0; j < m; j++) {
			cin >> office[i][j];
		}
	}

	direction[0] = up;			direction[1] = right;
	direction[2] = down;		direction[3] = left;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (office[i][j] == 1 | office[i][j] == 2 | office[i][j] == 3 |
				office[i][j] == 4 | office[i][j] == 5)
				watch.push_back({ office[i][j], i, j });
		}
	}

	dfs(office, 0, 0);

	cout << num_min << "\n";

	return 0;
}