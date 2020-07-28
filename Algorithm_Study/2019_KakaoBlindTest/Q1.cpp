#include <string>
#include <vector>
#include <iostream>

using namespace std;

int findStr(string str, string s) {
	int numOther = 0;
	int find = 0;
	int answer = 0;
	vector<int> numStr = { 0 };

	while (s.find(str) >= 0 && s.find(str) < s.length()) {
		int start = s.find(str);
		//cout << "start : " << start << endl;

		if (start == 0) {
			numStr[numStr.size() - 1]++;
			s.erase(0, str.length());
		}
		else {
			numStr.push_back(1);
			s.erase(0, start + str.length());
			numOther += start;
		}
	}
	numOther += s.length();

	//cout << "numOther : " << numOther << endl;

	for (int i = 0; i < numStr.size(); i++) {
		cout << numStr[i] << " ";
		if (numStr[i] > 0 && numStr[i] < 10)
			answer += (1 + str.length());
		else if (numStr[i] >= 10 && numStr[i] < 100)
			answer += (2 + str.length());
		else if (numStr[i] >= 100 && numStr[i] < 1000)
			answer += (3 + str.length());
		if (numStr[i] == 1000)
			answer += (4 + str.length());
	}cout << endl;

	answer += numOther;

	/*for (int i = 0; i < numStr.size(); i++) {
		cout << numStr[i] << " ";
	}cout << endl;
	cout << numOther << endl;
	cout << "answer : " << answer << endl<<endl;*/


	return answer;
}

int solution(string s) {
	int answer = 1001;

	for (int i = 1; i < s.length(); i++) {
		string str = "";			//단위 문자열
		for (int j = 0; j < i; j++) {
			str.push_back(s.at(j));
		}
		cout << str << endl;
		int res = findStr(str, s);
		if (res < answer) {
			answer = res;
			
			cout << "STR : " << str << ", answer : " << answer<< endl;
		}

	}

	cout << answer << endl;

	return answer;
}

int main() {
	solution("aabbaccc");
	//solution("ababcdcdababcdcd");
	//solution("abcabcdede");
	//solution("abcabcabcabcdededededede");
	//solution("xababcdcdababcdcd");


	return 0;
}