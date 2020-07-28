#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, h, answer = -1;
vector< vector< int> > ladders;
vector< pair<int, int> > add;

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << "\t";
		}cout << endl;
	}cout << endl;
}

bool ladder_game() {		//사다리 타기
	bool match = true;

	//cout << "=============================\n";
	for (int i = 0; i < n; i++) {
		//cout << i << " >> ";
		//cout << "--------- " << i << " ----------\n";
		int a = 0, b = i, result = -1;

		while (a < h - 1) {		//사다리 내려가기
			for (int j = -1; j <= 0; j++) {		//좌우 가로선 유무
				if (b + j >= 0 && b + j < n - 1) {
					if (ladders[a][b + j] == 1) {		//가로선 있음
						//cout << a << ", " << b + j << endl;
						if (j == -1)
							b -= 1;
						if (j == 0)
							b += 1;

						break;
					}
				}
			}

			a++;
		}

		int break_point = 0;
		while (break_point == 0) {		//마지막 가로선 검사
			if (b > 0) {
				if (ladders[a][b - 1] == 1) {
					result = b - 1;
					break;
				}
				else {
					result = b;
				}
			}
			if (b < n - 1) {
				if (ladders[a][b] == 1) {
					result = b + 1;
					break;
				}
				else {
					result = b;
					break;
				}
			}
			break_point++;
		}

		//cout << "res : " << result << endl;

		if (i != result)
			match = false;
	}

	return match;
}

void add_ladder() {
	if (ladder_game()) {		//사다리 0개 추가
		answer = 0;
	}
	else if (add.size() > 0) {
		for (int i = 0; i < add.size(); i++) {		//사다리 1개 추가
			ladders[add[i].first][add[i].second] = 1;
			if (ladder_game()) {
				answer = 1;
				return;
			}
			ladders[add[i].first][add[i].second] = 0;
		}

		for (int i = 0; i < add.size() - 1; i++) {		//사다리 2개 추가
			ladders[add[i].first][add[i].second] = 1;
			for (int j = i + 1; j < add.size(); j++) {
				ladders[add[j].first][add[j].second] = 1;
				if (ladder_game()) {
					answer = 2;
					return;
				}
				ladders[add[j].first][add[j].second] = 0;
			}
			ladders[add[i].first][add[i].second] = 0;
		}

		for (int i = 0; i < add.size() - 2; i++) {		//사다리 3개 추가
			ladders[add[i].first][add[i].second] = 1;
			for (int j = i + 1; j < add.size() - 1; j++) {
				ladders[add[j].first][add[j].second] = 1;
				for (int k = j + 1; k < add.size(); k++) {
					ladders[add[k].first][add[k].second] = 1;
					if (ladder_game()) {
						answer = 3;
						return;
					}
					ladders[add[k].first][add[k].second] = 0;
				}
				ladders[add[j].first][add[j].second] = 0;
			}
			ladders[add[i].first][add[i].second] = 0;
		}
	}
}

int main() {
	//input
	cin >> n >> m >> h;
	vector<int> lad(n - 1);
	for (int i = 0; i < h; i++)
		ladders.push_back(lad);

	for (int i = 0; i < m; i++) {		//사다리 저장
		int a, b;
		cin >> a >> b;
		ladders[a - 1][b - 1] = 1;

		if (b > 1)
			ladders[a - 1][b - 2] = -1;
		if (b < n - 1)
			ladders[a - 1][b] = -1;
	}

	for (int i = 0; i < h; i++) {		//빈 가로선 저장
		for (int j = 0; j < n - 1; j++) {
			if (ladders[i][j] == 0) {
				add.push_back({ i, j });
			}
		}
	}

	add_ladder();

	//p(ladders);
	cout << "answer : " << answer << endl;

	return 0;
}