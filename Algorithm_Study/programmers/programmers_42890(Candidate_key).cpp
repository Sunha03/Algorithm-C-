#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num_attribute = 0, num_row = 0;
int combi_att[9];
vector<vector<int>> combi_key;

void p(vector<vector<int>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

void combination(int arr[], int index, int n, int r, int target) {
	if (r == 0) {
		vector<int> keys;

		keys.push_back(0);
		for (int i = 0; i < index; i++)
			keys.push_back(arr[i]);

		combi_key.push_back(keys);
	}
	else if (target == n) {
		return;
	}
	else {
		arr[index] = target;
		combination(arr, index + 1, n, r - 1, target + 1);
		combination(arr, index, n, r, target + 1);
	}
}

void minimality(int i) {
	for (int j = i + 1; j < combi_key.size(); j++) {
		if (combi_key[j][0] != -1) {
			bool break_point = false;

			while (!break_point) {		//i��° key ������ ������ key ������ �ִ���
				for (int k = 1; k < combi_key[i].size(); k++) {
					for (int l = 1; l < combi_key[j].size(); l++) {
						if (combi_key[i][k] == combi_key[j][l]) {
							if (k == combi_key[i].size() - 1) {		//i�� ��� Ű�� ����
								combi_key[j][0] = -1;
								break_point = true;
							}
							else
								break;

						}
						else if (l == combi_key[j].size() - 1) {		//i �߿� �������� �ʴ� Ű�� ����
							break_point = true;
						}
					}

					if (break_point == true)
						break;
				}
			}
		}
	}
}

void uniqueness(vector<vector<string>> input) {
	for (int key = 0; key < combi_key.size(); key++) {			//key ���� ��ü Ž��
		if (combi_key[key][0] == 0) {
			int i = 0;
			bool same = false;

			while (same == false && i < num_row - 1) {	//row 2���� ��
				for (int j = i + 1; j < num_row; j++) {
					for (int k = 1; k < combi_key[key].size(); k++) {	//key ���պ��� ��
						//2�� row�� �ٸ�
						if (input[i][combi_key[key][k]] != input[j][combi_key[key][k]])
							break;

						//2�� row�� ����
						else if (input[i][combi_key[key][k]] == input[j][combi_key[key][k]] && k == combi_key[key].size() - 1) {
							//cout << "SAME : " << key << "\t" << i << "\t" << input[i][combi_key[key][k]] << endl;
							combi_key[key][0] = -1;
							same = true;
							break;
						}
					}

					if (same == true)
						break;
				}

				if (i == num_row - 2) {		//2�� row�� �ٸ�
					combi_key[key][0] = 1;
					minimality(key);
				}

				i++;
			}
		}
	}
}


int solution(vector<vector<string>> relation) {
	int answer = 0;

	num_row = relation.size();
	num_attribute = relation[0].size();

	if (num_row == 1) {
		answer = num_attribute;
	}
	else {
		for (int i = 1; i <= num_attribute; i++) {
			combination(combi_att, 0, num_attribute, i, 0);
		}

		uniqueness(relation);

		for (int i = 0; i < combi_key.size(); i++) {
			if (combi_key[i][0] == 1) {
				answer++;
			}
		}
	}


	//p(combi_key);

	cout << answer << endl;

	return answer;
}

int main() {
	/*vector<vector<string>> v = {{"100", "ryan", "music", "2"},
	{"200", "apeach", "math", "2"},
	{"300", "tube", "computer", "3"},
	{"400", "con", "computer", "4"},
	{"500", "muzi", "music", "3"},
	{"600", "apeach", "music", "2"}};*/

	vector<vector<string>> v = { {"100"/*, "ryan", "music", "1", "A"*/},
	{"200"/*, "ryaa", "musir", "2", "B"*/},
	{"300"/*, "ryaa", "musi4", "3", "C"*/},
	{"400"/*, "ryae", "musi4", "4", "E"*/},
	{"500"/*, "rya2", "musi2", "4", "F"*/},
	{"600"/*, "ryaq", "musis", "6", "F"*/},
	{"700"/*, "ryac", "musia", "7", "G"*/} };

	solution(v);

	return 0;
}