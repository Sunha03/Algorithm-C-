#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void p(vector<vector<string>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
			if (j != vec[i].size() - 1)
				cout << " ";
		}cout << endl;
	}
}

bool isNumber(string strNum) {
	if (atoi(strNum.c_str()))
		return true;
	else
		return false;
}

int main(void) {
	int table1_header = 0, table2_header = 0, ans_header = 0, size1 = 0, size2 = 0;
	int foreign1, foreign2;
	vector<string> input1, input2;
	vector<vector<string>> table1, table2, answer, final_answer;

	//==================input table1==================
	cin >> size1;
	for (int i = 0; i < 4; i++) {
		string s;

		cin >> s;
		if (isNumber(s)) {			//속성 입력
			if (table1_header == 0)
				table1_header = i;
			table1.push_back(input1);
			input1.clear();
		}
		input1.push_back(s);
	}

	for (int i = 0; i < table1_header - 1; i++) {	//첫번째 row
		string s;
		cin >> s;
		input1.push_back(s);
	}
	table1.push_back(input1);

	for (int i = 0; i < size1 - 2; i++) {			//나머지 row
		vector<string> in;
		for (int j = 0; j < table1_header; j++) {
			string s;

			cin >> s;
			in.push_back(s);
		}
		table1.push_back(in);
	}

	//==================input table2==================
	cin >> size2;
	for (int i = 0; i < 4; i++) {
		string s;

		cin >> s;
		if (isNumber(s)) {			//속성 입력
			if (table2_header == 0)
				table2_header = i;
			table2.push_back(input2);
			input2.clear();
		}
		input2.push_back(s);
	}

	for (int i = 0; i < table2_header - 1; i++) {	//첫번째 row
		string s;
		cin >> s;
		input2.push_back(s);
	}
	table2.push_back(input2);

	for (int i = 0; i < size2 - 2; i++) {		//나머지 row
		vector<string> in;
		for (int j = 0; j < table2_header; j++) {
			string s;

			cin >> s;
			in.push_back(s);
		}
		table2.push_back(in);
	}

	for (int i = 0; i < table1[0].size(); i++) {	//외래키 찾기
		for (int j = 0; j < table2[0].size(); j++) {
			if (table1[0][i] == table2[0][j]) {
				foreign1 = i;
				foreign2 = j;
			}
		}
	}

	vector<string> ans;			//조인 결과 테이블의 속성
	for (int i = 0; i < table1[0].size(); i++) {
		ans.push_back(table1[0][i]);
		ans_header++;
	}
	for (int i = 0; i < table2[0].size(); i++) {
		if (i != foreign2) {
			ans.push_back(table2[0][i]);
			ans_header++;
		}
	}
	final_answer.push_back(ans);

	sort(table1.begin(), table1.end());		//외래키 기준 정렬
	sort(table2.begin(), table2.end());

	for (int i = 0; i < table1.size() - 1; i++) {
		for (int j = 0; j < table2.size() - 1; j++) {
			vector<string> row;

			if (table1[i][foreign1] == table2[j][foreign2]) {	//row 일치
				for (int k = 0; k < table1_header; k++)
					row.push_back(table1[i][k]);
				for (int k = 1; k < table2_header; k++)
					row.push_back(table2[j][k]);

				answer.push_back(row);
				break;
			}
			else if (j == table2.size() - 2) {		//row 일치 없음
				for (int k = 0; k < table1_header; k++)
					row.push_back(table1[i][k]);
				for (int k = 1; k < table2_header; k++)
					row.push_back("NULL");

				answer.push_back(row);
				break;
			}
		}
	}

	cout << endl;
	p(final_answer);
	p(answer);
	
	return 0;
}
/*
6
id name occupation
5 Brown Accountant
2 Cony Programmer
3 Sally Doctor
1 James Singer
4 Moon Dancer
7
id city zip
2 Seoul 10008
7 Busan 40002
5 Gwangju 20009
6 Daegu 30008
3 Seoul 40005
1 Seoul 50006
*/