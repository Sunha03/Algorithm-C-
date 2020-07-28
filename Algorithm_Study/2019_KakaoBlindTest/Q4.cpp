#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (int i = 0; i < queries.size(); i++) {
		/*string que = "";
		int numEtc = 0;
		bool front = true;
		for (int j = 0; j < queries[i].size(); j++) {
			if (queries[i].at(j) >= 97 && queries[i].at(j) >= 122)
				que.push_back(queries[i].at(j));
			else {
				if (j != 0)
					front = false;
				numEtc++;
			}
		}*/

		int res = 0;
		for (int j = 0; j < words.size(); j++) {
			
			int match = 0;
			if (queries[i].length() == words[j].length()) {
				for (int k = 0; k < words[j].length(); k++) {
					if (queries[i].at(k) == '?' && words[j].at(k) >= 97 && words[j].at(k) <= 122) {
						match++;
					}
					else {
						if (queries[i].at(k) == words[j].at(k)) {
							match++;
						}
						else {
							break;
						}
					}
				}

				if (match == queries[i].length()) {
					cout << queries[i] << " -> " << words[j] << endl;
					res++;
				}
			}
		}

		answer.push_back(res);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
	cout << endl;

	return answer;
}

int main() {
	vector<string> w = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> q = { "fro??", "????o", "fr???", "fro???", "pro?" };
	solution(w, q);

	return 0;
}