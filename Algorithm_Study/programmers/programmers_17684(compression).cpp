#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< pair<string, int> > dictionary;

void p_dic() {
	for (int i = 0; i < 10; i++) {
		cout << dictionary[i].first << "\t";
	}cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << dictionary[i].second << "\t";
	}cout << endl;

	for (int i = 10; i < 20; i++) {
		cout << dictionary[i].first << "\t";
	}cout << endl;
	for (int i = 10; i < 20; i++) {
		cout << dictionary[i].second << "\t";
	}cout << endl;

	for (int i = 20; i < 26; i++) {
		cout << dictionary[i].first << "\t";
	}cout << endl;
	for (int i = 20; i < 26; i++) {
		cout << dictionary[i].second << "\t";
	}cout << endl;

	for (int i = 26; i < dictionary.size(); i++) {
		cout << dictionary[i].first << "\t";
	}cout << endl;
	for (int i = 26; i < dictionary.size(); i++) {
		cout << dictionary[i].second << "\t";
	}cout << endl;
}

int findWC(string s) {			//�������� �ܾ� ã��
	for (int i = 0; i < dictionary.size(); i++) {
		if (dictionary[i].first == s)
			return dictionary[i].second;
		else if (i == dictionary.size() - 1)
			return -1;
	}
}

vector<int> solution(string msg) {
	vector<int> answer;
	char * ch_msg = _strdup(msg.c_str());

	for (int i = 65; i <= 90; i++) {		//���� �ʱ�ȭ(A~Z)
		string str;
		str.push_back((char)i);
		dictionary.push_back({str, i - 64});
	}

	bool break_point = false;
	for (int i = 0; i < strlen(ch_msg); i++) {
		int idx_c = -1;
		int idx_i = 0;
		string w;
		w.push_back(ch_msg[i]);

		if (i != strlen(ch_msg) - 1) {		//W ã��
			for (int j = i + 1; j < strlen(ch_msg); j++) {
				w.push_back(ch_msg[j]);
				idx_i++;

				if (findWC(w) == -1) {
					idx_c = j;
					idx_i--;
					//cout << "(X) " << w << endl;
					w.pop_back();
					break;
				}
			}
			i += idx_i;
		}

		answer.push_back(findWC(w));		//answer �߰�

		string w_plus_c = w;						//W + C 
		if (i != strlen(ch_msg) - 1) {
			w_plus_c.push_back(ch_msg[idx_c]);
		}

		if (findWC(w_plus_c) == -1) {				//W + C ������ �߰�
			dictionary.push_back({ w_plus_c, dictionary.size() + 1});
		}
			
		//cout <<  w << " / " << w_plus_c << endl;
	}

	//p_dic();

	for (int i = 0; i < answer.size(); i++) {		//Answer Print
		cout << answer[i] << " ";
	}cout << endl;


	return answer;
}

int main() {
	string s = "TOBEORNOTTOBEORTOBEORNOT";
	solution(s);

	return 0;
}