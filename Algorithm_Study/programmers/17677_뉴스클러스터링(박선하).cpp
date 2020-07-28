#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int idx_contain;

bool alphabet(char *c) {
	if (*c >= 65 && *c <= 90) {
		return true;
	}
	else if (*c >= 97 && *c <= 122) {
		*c -= 32;
		return true;
	}
	else {
		return false;
	}
}

bool isContain(vector<char> ch, vector< vector<char> > vec) {
	idx_contain = -1;

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i][0] == ch[0] && vec[i][1] == ch[1]) {
			idx_contain = i;
			return true;
		}
		else if (i == vec.size() - 1) {
			return false;
		}
	}
}

void strToChar(char * ch, vector< vector<char> > &vec) {			//string to 2차원 char vector
	vector<char> pair(2);
	for (int i = 0; i < strlen(ch) - 1; i++) {
		if (alphabet(&ch[i]) && alphabet(&ch[i + 1])) {				//둘 다 알파벳이면
			pair = { ch[i], ch[i + 1] };

			if (vec.size() == 0) {
				vec.push_back({ ch[i], ch[i + 1], 1 });
			}
			else if (isContain(pair, vec)) {
				vec[idx_contain][2]++;
			}
			else {
				vec.push_back({ ch[i], ch[i + 1], 1 });
			}
		}
	}
}

bool isSame(vector<char> ch1, vector<char> ch2) {
	if ((ch1[0] == ch2[0]) && (ch1[1] == ch2[1])) {
		return true;
	}
	else {
		return false;
	}
}

int solution(string str1, string str2) {
	int answer = 0;
	int num_union = 0;
	int num_inter = 0;
	double jacard = 0.0;
	vector< vector<char> > v_str1, v_str2, v_union, v_inter;
	char * ch1 = strdup(str1.c_str());			//string to char*
	char * ch2 = strdup(str2.c_str());

	strToChar(ch1, v_str1);
	strToChar(ch2, v_str2);

	for (int i = 0; i < v_str1.size(); i++) {						//교집합 vector
		for (int j = 0; j < v_str2.size(); j++) {
			if (isSame(v_str1[i], v_str2[j])) {
				if (v_inter.size() == 0) {
					v_inter.push_back({ v_str1[i][0], v_str1[i][1], min(v_str1[i][2], v_str2[j][2]) });
					break;
				}
				else if (isContain(v_str1[i], v_inter)) {
					v_inter[idx_contain][2] = min(v_inter[idx_contain][2], v_str2[j][2]);
					break;
				}
				else {
					v_inter.push_back({ v_str1[i][0], v_str1[i][1], min(v_str1[i][2], v_str2[j][2]) });
					break;
				}
			}
		}
	}

	v_union = v_inter;

	//합집합 vector 완성
	for (int i = 0; i < v_str1.size(); i++) {				//v_str2
		if (!isContain(v_str1[i], v_union)) {
			v_union.push_back(v_str1[i]);
		}
		else {
			v_union[idx_contain][2] = max(v_union[idx_contain][2], v_str1[i][2]);
		}
	}
	for (int i = 0; i < v_str2.size(); i++) {				//v_str2
		if (!isContain(v_str2[i], v_union)) {
			v_union.push_back(v_str2[i]);
		}
		else {
			v_union[idx_contain][2] = max(v_union[idx_contain][2], v_str2[i][2]);
		}
	}

	for (int i = 0; i < v_inter.size(); i++) {
		num_inter += v_inter[i][2];
	}
	for (int i = 0; i < v_union.size(); i++) {
		num_union += v_union[i][2];
	}

	if (num_inter == 0 && num_union == 0) {
		jacard = 1;
	}
	else {
		jacard = (double)num_inter / num_union;
	}
	answer = jacard * 65536;
	cout << answer << endl;

	return answer;
}