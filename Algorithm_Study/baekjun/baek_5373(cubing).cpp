#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< vector<char> > m_up, m_down, m_front, m_back, m_left, m_right;

void printVec() {
	for (int i = 0; i < 3; i++) {
		cout << "\t\t";
		for (int j = 0; j < 3; j++) {
			cout << m_up[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << m_left[i][j] << " ";
		}
		cout << "\t\t";
		for (int j = 0; j < 3; j++) {
			cout << m_front[i][j] << " ";
		}
		cout << "\t\t";
		for (int j = 0; j < 3; j++) {
			cout << m_right[i][j] << " ";
		}
		cout << "\t\t";
		for (int j = 0; j < 3; j++) {
			cout << m_back[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << "\t\t";
		for (int j = 0; j < 3; j++) {
			cout << m_down[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void initVec(vector< vector<char> > &vec, char ch) {
	for (int i = 0; i < 3; i++) {
		vector<char> v;
		for (int j = 0; j < 3; j++) {
			v.push_back(ch);
		}
		vec.push_back(v);
	}
}

void rotation(vector< vector<char> > &vec, int clockwise) {
	if (clockwise == 0) {				//반시계 방향
		char temp = vec[0][0];
		vec[0][0] = vec[0][2];
		vec[0][2] = vec[2][2];
		vec[2][2] = vec[2][0];
		vec[2][0] = temp;

		temp = vec[2][1];
		vec[2][1] = vec[1][0];
		vec[1][0] = vec[0][1];
		vec[0][1] = vec[1][2];
		vec[1][2] = temp;
	}
	else {						//시계 방향
		char temp = vec[2][0];
		vec[2][0] = vec[2][2];
		vec[2][2] = vec[0][2];
		vec[0][2] = vec[0][0];
		vec[0][0] = temp;

		temp = vec[2][1];
		vec[2][1] = vec[1][2];
		vec[1][2] = vec[0][1];
		vec[0][1] = vec[1][0];
		vec[1][0] = temp;
	}
}

void upDown(char rota, char dir) {
	int index, clockwise;
	char temp[3];

	if (dir == '+') {
		clockwise = 1;
	}
	else {
		clockwise = 0;
	}

	if (rota == 'u') {
		index = 0;
		rotation(m_up, clockwise);
	}
	else if (rota == 'd') {
		index = 2;
		rotation(m_down, clockwise);
	}

	if ((rota == 'u' && dir == '+') || (rota == 'd' && dir == '-')) {					//U+, D-
		for (int i = 0; i < 3; i++) {
			temp[i] = m_front[index][i];
			m_front[index][i] = m_right[index][i];
			m_right[index][i] = m_back[index][i];
			m_back[index][i] = m_left[index][i];
			m_left[index][i] = temp[i];
		}
	}
	else if ((rota == 'u' && dir == '-') || (rota == 'd' && dir == '+')) {				//U-, D+
		for (int i = 0; i < 3; i++) {
			temp[i] = m_front[index][i];
			m_front[index][i] = m_left[index][i];
			m_left[index][i] = m_back[index][i];
			m_back[index][i] = m_right[index][i];
			m_right[index][i] = temp[i];
		}
	}
}

void frontBack(char rota, char dir) {
	int index_i, index_j, clockwise;
	char temp[3];

	if (dir == '+') {
		clockwise = 1;
	}
	else {
		clockwise = 0;
	}

	if (rota == 'f') {
		index_i = 0;
		index_j = 2;
		rotation(m_front, clockwise);
	}
	else if (rota == 'b') {
		index_i = 2;
		index_j = 0;
		rotation(m_back, clockwise);
	}

	if ((rota == 'f' && dir == '+') || (rota == 'b' && dir == '-')) {					//F+, B-
		for (int i = 0; i < 3; i++) {
			temp[i] = m_up[index_j][i];
			m_up[index_j][i] = m_left[2 - i][index_j];
			m_left[2 - i][index_j] = m_down[index_i][2 - i];
			m_down[index_i][2 - i] = m_right[i][index_i];
			m_right[i][index_i] = temp[i];
		}
	}
	else if ((rota == 'f' && dir == '-') || (rota == 'b' && dir == '+')) {				//F-, B+
		for (int i = 0; i < 3; i++) {
			temp[i] = m_up[index_j][i];
			m_up[index_j][i] = m_right[i][index_i];
			m_right[i][index_i] = m_down[index_i][2 - i];
			m_down[index_i][2 - i] = m_left[2 - i][index_j];
			m_left[2 - i][index_j] = temp[i];
		}
	}
}

void leftRight(char rota, char dir) {
	int index_i, index_j, clockwise;
	char temp[3];

	if (dir == '+') {
		clockwise = 1;
	}
	else {
		clockwise = 0;
	}

	if (rota == 'l') {
		index_i = 0;
		index_j = 2;
		rotation(m_left, clockwise);
	}
	else if (rota == 'r') {
		index_i = 2;
		index_j = 0;
		rotation(m_right, clockwise);
	}

	if ((rota == 'l' && dir == '+') || (rota == 'r' && dir == '-')) {					//L+, R-
		for (int i = 0; i < 3; i++) {
			temp[i] = m_front[i][index_i];
			m_front[i][index_i] = m_up[i][index_i];
			m_up[i][index_i] = m_back[2 - i][index_j];
			m_back[2 - i][index_j] = m_down[i][index_i];
			m_down[i][index_i] = temp[i];
		}
	}
	else if ((rota == 'l' && dir == '-') || (rota == 'r' && dir == '+')) {				//L-, R+
		for (int i = 0; i < 3; i++) {
			temp[i] = m_front[i][index_i];
			m_front[i][index_i] = m_down[i][index_i];
			m_down[i][index_i] = m_back[2 - i][index_j];
			m_back[2 - i][index_j] = m_up[i][index_i];
			m_up[i][index_i] = temp[i];
		}
	}
}

int main()
{
	int test_case;
	vector< vector<char> > answer;

	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		int n;
		vector< vector<char> > move;

		cin >> n;
		for (int i = 0; i < n; i++) {			//input move[][]
			vector<char> m;
			for (int j = 0; j < 2; j++) {
				char c;
				cin >> c;
				m.push_back(c);
			}
			move.push_back(m);
		}

		m_up.clear();			m_down.clear();				m_front.clear();
		m_back.clear();			m_left.clear();				m_right.clear();
		initVec(m_up, 'w');		initVec(m_down, 'y');		initVec(m_front, 'r');
		initVec(m_back, 'o');	initVec(m_left, 'g');		initVec(m_right, 'b');

		for (int i = 0; i < move.size(); i++) {
			switch (move[i][0]) {
			case 'U':
				upDown('u', move[i][1]);
				break;
			case 'D':
				upDown('d', move[i][1]);
				break;
			case 'F':
				frontBack('f', move[i][1]);
				break;
			case 'B':
				frontBack('b', move[i][1]);
				break;
			case 'L':
				leftRight('l', move[i][1]);
				break;
			case 'R':
				leftRight('r', move[i][1]);
				break;
			}
		}

		for (int i = 0; i < 3; i++) {
			answer.push_back(m_up[i]);
		}

	}

	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < 3; j++) {
			cout << answer[i][j];
		}
		cout << "\n";
	}

	return 0;
}