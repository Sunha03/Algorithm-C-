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

bool ladder_game() {		//��ٸ� Ÿ��
	bool match = true;

	//cout << "=============================\n";
	for (int i = 0; i < n; i++) {
		//cout << i << " >> ";
		//cout << "--------- " << i << " ----------\n";
		int a = 0, b = i, result = -1;

		while (a < h - 1) {		//��ٸ� ��������
			for (int j = -1; j <= 0; j++) {		//�¿� ���μ� ����
				if (b + j >= 0 && b + j < n - 1) {
					if (ladders[a][b + j] == 1) {		//���μ� ����
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
		while (break_point == 0) {		//������ ���μ� �˻�
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
	if (ladder_game()) {		//��ٸ� 0�� �߰�
		answer = 0;
	}
	else if (add.size() > 0) {
		for (int i = 0; i < add.size(); i++) {		//��ٸ� 1�� �߰�
			ladders[add[i].first][add[i].second] = 1;
			if (ladder_game()) {
				answer = 1;
				return;
			}
			ladders[add[i].first][add[i].second] = 0;
		}

		for (int i = 0; i < add.size() - 1; i++) {		//��ٸ� 2�� �߰�
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

		for (int i = 0; i < add.size() - 2; i++) {		//��ٸ� 3�� �߰�
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

	for (int i = 0; i < m; i++) {		//��ٸ� ����
		int a, b;
		cin >> a >> b;
		ladders[a - 1][b - 1] = 1;

		if (b > 1)
			ladders[a - 1][b - 2] = -1;
		if (b < n - 1)
			ladders[a - 1][b] = -1;
	}

	for (int i = 0; i < h; i++) {		//�� ���μ� ����
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