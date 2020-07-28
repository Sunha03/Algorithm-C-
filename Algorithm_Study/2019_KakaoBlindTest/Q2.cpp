#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print(vector<int> p) {
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 1) {
			cout << "(";
		}
		else if (p[i] == -1) {
			cout << ")";
		}
	}cout << endl;
}

bool isRight(vector<int> u) {
	if (u.size() > 0) {
		if (u[0] == -1)
			return false;
		else {
			int open = 0;
			for (int i = 0; i < u.size(); i++) {
				if (u[i] == 1)
					open++;
				else if (u[i] == -1)
					open--;

				if (open < 0)
					return false;
			}

			return true;
		}
	}
	else
		return false;
}

vector<int> algorithm(vector<int> pInt) {
	vector<int> u, v, res;
	int sum = 0, idx = 0;

	if (pInt.size() == 0) {
		res.push_back(0);
		return res;
	}

	for (int i = 0; i < pInt.size(); i++) {
		u.push_back(pInt[i]);
		sum += pInt[i];
		if (sum == 0) {
			idx = i + 1;
			break;
		}
	}
	for (int i = idx; i < pInt.size(); i++)
		v.push_back(pInt[i]);

	print(u);
	print(v);

	if (isRight(u)) {		//¿Ã¹Ù¸¥
		vector<int> newV = algorithm(v);

		for (int i = 0; i < u.size(); i++)
			res.push_back(u[i]);
		for (int i = 0; i < newV.size(); i++)
			if(newV[i] != 0)
				res.push_back(newV[i]);

		return res;
	}
	else {					//±ÕÇü ÀâÈù
		res.push_back(1);
		print(res);

		vector<int> newV = algorithm(v);
		for (int i = 0; i < newV.size(); i++)
			if(newV[i] != 0)
				res.push_back(newV[i]);
		print(res);

		res.push_back(-1);
		print(res);

		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == 1)
				res.push_back(-1);
			else if (u[i] == -1)
				res.push_back(1);
		}
		print(res);

		return res;
	}
}

string solution(string p) {
	string answer = "";
	vector<int> pInt;

	for (int i = 0; i < p.length(); i++) {
		if (p.at(i) == '(')
			pInt.push_back(1);
		else if (p.at(i) == ')')
			pInt.push_back(-1);
	}

	vector<int> result = algorithm(pInt);

	for (int i = 0; i < result.size(); i++) {
		if (result[i] == 1)
			answer.push_back('(');
		else if (result[i] == -1)
			answer.push_back(')');
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i];
	cout << endl;

	return answer;
}

int main() {
	//solution("(()())()");
	//solution(")(");
	solution("()))((()");

	return 0;
}