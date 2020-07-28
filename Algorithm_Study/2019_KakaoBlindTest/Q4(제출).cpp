#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (int i = 0; i < queries.size(); i++) {
		int res = 0;
		for (int j = 0; j < words.size(); j++) {

			int match = 0;
			if (queries[i].length() == words[j].length()) {
				for (int k = 0; k < words[j].length(); k++) {
					if (queries[i].at(k) == '?' && words[j].at(k) >= 97 && words[j].at(k) <= 122)
						match++;
					else {
						if (queries[i].at(k) == words[j].at(k))
							match++;
						else
							break;
					}
				}

				if (match == queries[i].length())
					res++;
			}
		}
		answer.push_back(res);
	}

	return answer;
}