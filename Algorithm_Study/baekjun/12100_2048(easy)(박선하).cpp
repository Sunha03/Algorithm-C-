#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, num_max = 0;
vector< vector<int> > input;

void dfs(vector< vector<int> > vec, int num);

void move(vector<int> &line) {			//한 줄 이동
	int num_zero = 0;
	int same = 0;
	queue<int> number;
	vector<int> output;

	for (int i = 0; i < n; i++) {
		if (line[i] != 0)
			number.push(line[i]);
		else
			num_zero++;
	}

	line.clear();
	while (!number.empty()) {
		line.push_back(number.front());
		number.pop();
	}
	for (int i = 0; i < num_zero; i++) {
		line.push_back(0);
	}

	for (int i = 0; i < n - 1; i++) {
		if (line[i] == line[i + 1]) {
			output.push_back(2 * line[i]);

			if (i == n - 3)
				output.push_back(line[n - 1]);

			same++;
			i++;
		}
		else {
			output.push_back(line[i]);

			if (i == n - 2)
				output.push_back(line[n - 1]);
		}
	}

	for (int i = 0; i < same; i++)
		output.push_back(0);

	line = output;
}

//(dir)0:up, 1:down
void upDown(vector< vector<int> > map, int dir, int num) {
	for (int j = 0; j < n; j++) {
		vector<int> one_line;
		for (int i = 0; i < n; i++) {
			if (dir == 0)
				one_line.push_back(map[i][j]);
			else if (dir == 1)
				one_line.push_back(map[n - i - 1][j]);
		}

		move(one_line);

		for (int i = 0; i < n; i++) {
			if (dir == 0)
				map[i][j] = one_line[i];
			else if (dir == 1)
				map[n - i - 1][j] = one_line[i];
		}
	}

	dfs(map, num + 1);
}

//(dir)0:left, 1:right
void leftRight(vector< vector<int> > map, int dir, int num) {
	for (int i = 0; i < n; i++) {
		vector<int> one_line;
		for (int j = 0; j < n; j++) {
			if (dir == 0)
				one_line.push_back(map[i][j]);
			else if (dir == 1)
				one_line.push_back(map[i][n - j - 1]);
		}

		move(one_line);

		for (int j = 0; j < n; j++) {
			if (dir == 0)
				map[i][j] = one_line[j];
			else if (dir == 1)
				map[i][n - j - 1] = one_line[j];
		}
	}

	dfs(map, num + 1);
}

void dfs(vector< vector<int> > vec, int num) {
	vector< vector<int> > temp = vec;
	int count_move = 0;

	if (num == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (num_max < vec[i][j]) {
					num_max = vec[i][j];
				}
			}
		}
		return;
	}

	while (count_move < 4) {
		switch (count_move) {
		case 0:
			upDown(temp, 0, num);
			count_move++;
			break;
		case 1:
			upDown(temp, 1, num);
			count_move++;
			break;
		case 2:
			leftRight(temp, 0, num);
			count_move++;
			break;
		case 3:
			leftRight(temp, 1, num);
			count_move++;
			break;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> in(n);
		input.push_back(in);
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}

	dfs(input, 0);
	cout << num_max << endl;

	return 0;
}