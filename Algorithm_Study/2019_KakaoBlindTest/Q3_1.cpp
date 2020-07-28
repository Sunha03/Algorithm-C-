#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print(vector<vector<int>> key) {
	for (int i = 0; i < key.size(); i++) {
		for (int j = 0; j < key.size(); j++) {
			cout << key[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

vector<vector<int>> rotation(vector<vector<int>> key) {
	vector<vector<int>> rotKey;

	for (int i = 0; i < key.size(); i++) {
		vector<int> v;
		for (int j = 0; j < key.size(); j++) {
			v.push_back(key[key.size() - j - 1][i]);
		}
		rotKey.push_back(v);
	}

	return rotKey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	int rotate = 4;

	while (rotate-- > 0) {
		key = rotation(key);

		for (int i = 0; i < lock.size(); i++) {
			for (int j = 0; j < lock.size(); j++) {
				bool match = true;
				for (int k = i; k < i + key.size(); k++) {
					for (int l = j; l < j + key.size(); l++) {
						if (match) {
							if (k < lock.size() && l < lock.size()) {
								if (lock[k][l] == 0 && key[k][l] == 1 || lock[k][l] == 1 && key[k][l] == 0) {
									if (k == i + key.size() - 1 && l == j + key.size() - 1) {
										//return true;
									}
								}
							}
						}
					}

					if (match == false)
						break;
				}
			}
		}
	}

	answer = false;
	cout << answer << endl;

	return answer;
}

int main() {
	vector<vector<int>> key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vector<vector<int>> lock = { {1, 1, 1}, { 1, 1, 0 }, { 1, 0, 1 } };
	solution(key, lock);

	return 0;
}