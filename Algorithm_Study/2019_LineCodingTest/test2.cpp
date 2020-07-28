#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>

using namespace std;

bool isCapital(char ch) {		//대문자 여부
	if (ch >= 65 && ch <= 90)
		return true;
	else
		return false;
}

bool isSmall(char ch) {			//소문자 여부
	if (ch >= 97 && ch <= 122)
		return true;
	else
		return false;
}

int main(void) {
	int num_element = 0, num_number = 0;
	string str_formula;
	char * ch_formula = "";
	queue<char> element;
	queue<char> number;
	queue<char> answer;

	cin >> str_formula;
	ch_formula = _strdup(str_formula.c_str());

	for (int i = 0; i < str_formula.size(); i++) {
		if (isCapital(ch_formula[i])) {		//대문자 저장(element)
			num_element++;
			element.push(ch_formula[i]);
		}
		else if (isSmall(ch_formula[i])) {	//소문자 저장(element)
			element.push(ch_formula[i]);
		}
		//1일 때 숫자 저장(number)
		else if (ch_formula[i] >= '1' && ch_formula[i] <= '10') {
			num_number++;
			number.push(ch_formula[i]);
		}
	}

	if (num_element != num_number) {	//원소 개수 != 숫자 개수
		cout << "error\n";
		return 0;
	}

	int idx_el = 0, idx_num = 0;
	while (num_element + num_number > 0) {
		char ch = element.front();
		char num = number.front();

		cout << ch << " ";		//대문자 push
		answer.push(ch);
		element.pop();
		num_element--;

		if (idx_el < element.size() - 1) {
			if (isSmall(element.front())) {		//소문자 있으면 push
				cout << element.front() << " ";
				answer.push(element.front());
				element.pop();
				idx_el++;
			}
		}

		if (num == '1') {		//숫자 == 1이면 생략
			cout << num << " ";
			number.pop();
			idx_num++;
			num_number--;
		}
		else if (num > '1' && num <= '10') {	//숫자 push
			cout << num << " ";
			answer.push(num);
			number.pop();
			idx_num++;
			num_number--;
		}
	}

	int size = answer.size();		//결과 출력
	for (int i = 0; i<size; i++) {
		char ch = answer.front();
		answer.pop();
		cout << ch;
	}
	cout << endl;


	return 0;
}