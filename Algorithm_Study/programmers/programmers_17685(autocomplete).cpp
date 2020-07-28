#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int same(string str1, string str2) {
	int size, same = 0;

	str1.size() < str2.size() ? size = str1.size() : size = str2.size();

	for (int i = 0; i < size; i++) {
		if (str1.at(i) == str2.at(i)) {
			same++;
		}
		else {
			break;
		}
	}

	return same;
}

int solution(vector<string> words) {
	int answer = 0;
	int index = 0;
	int first, end;

	sort(words.begin(), words.end());

	first = same(words.at(0), words.at(1));
	first < words.at(0).size() ? answer += first + 1 : answer += words.at(0).size();

	for (int i = 1; i < words.size() - 1; i++) {
		int same1, same2;
		int max = 0;

		same1 = same(words.at(i - 1), words.at(i));
		same2 = same(words.at(i), words.at(i + 1));

		same1 < same2 ? max = same2 : max = same1;
		max < words.at(i).size() ? answer += max + 1 : answer += words.at(i).size();
	}

	end = same(words.at(words.size() - 2), words.at(words.size() - 1));
	end < words.at(words.size() - 1).size() ? answer += end + 1 : answer += words.at(words.size() - 1).size();

	return answer;
}

int main() {
	vector<string> vec = { "go", "guild", "gone" };
	int ans = solution(vec);

	return 0;
}