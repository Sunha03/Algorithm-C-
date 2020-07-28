#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector< pair<string, int> > dictionary;

int findWC(string s) {			//사전에서 단어 탐색
	for (int i = 0; i < dictionary.size(); i++) {
		if (dictionary[i].first == s)
			return dictionary[i].second;
		else if (i == dictionary.size() - 1)
			return -1;
	}
}

vector<int> solution(string msg) {
	vector<int> answer;
	char * ch_msg = strdup(msg.c_str());

	for (int i = 65; i <= 90; i++) {		//사전 초기화(A~Z)
		string str;
		str.push_back((char)i);
		dictionary.push_back({ str, i - 64 });
	}

	for (int i = 0; i < strlen(ch_msg); i++) {
		int idx_c = -1;
		int idx_i = 0;
		string w;
		w.push_back(ch_msg[i]);

		if (i != strlen(ch_msg) - 1) {		//W 찾기
			for (int j = i + 1; j < strlen(ch_msg); j++) {
				w.push_back(ch_msg[j]);
				idx_i++;

				if (findWC(w) == -1) {
					idx_c = j;
					idx_i--;
					w.pop_back();
					break;
				}
			}
			i += idx_i;
		}

		answer.push_back(findWC(w));		//answer 추가

		string w_plus_c = w;						//W + C 
		if (i != strlen(ch_msg) - 1) {
			w_plus_c.push_back(ch_msg[idx_c]);
		}

		if (findWC(w_plus_c) == -1) {				//W + C 없으면 추가
			dictionary.push_back({ w_plus_c, dictionary.size() + 1 });
		}
	}

	for (int i = 0; i < answer.size(); i++) {		//print
		cout << answer[i] << " ";
	}cout << endl;


	return answer;
}