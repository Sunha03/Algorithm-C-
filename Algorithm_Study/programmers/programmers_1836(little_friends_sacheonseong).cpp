#include <iostream>
#include <string>
#include <vector>

using namespace std;

int M, N;
vector<char> answer;
vector<vector<char>> ch_board;

void p(vector<vector<char>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}cout << "\n";
	}cout << "\n";

}

bool inLine(int x, int y, char c) {
	int nx = x;
	int ny = y;

	while (--nx >= 0) {		//상
		if (ch_board[nx][ny] == c && ch_board[nx][ny] != '.') {
			ch_board[x][y] = '.';
			ch_board[nx][ny] = '.';
			answer.push_back(c);
			cout << c << endl;
			p(ch_board);
			return true;
		}
		else if (ch_board[nx][ny] != c && ch_board[nx][ny] != '.') {
			break;
		}
	}

	nx = x;			ny = y;
	while (--ny >= 0) {		//좌
		if (ch_board[nx][ny] == c && ch_board[nx][ny] != '.') {
			ch_board[x][y] = '.';
			ch_board[nx][ny] = '.';
			answer.push_back(c);
			cout << c << endl;
			p(ch_board);
			return true;
		}
		else if (ch_board[nx][ny] != c && ch_board[nx][ny] != '.') {
			break;
		}
	}

	nx = x;			ny = y;
	while (++ny <= N - 1) {		//우
		if (ch_board[nx][ny] == c && ch_board[nx][ny] != '.') {
			ch_board[x][y] = '.';
			ch_board[nx][ny] = '.';
			answer.push_back(c);
			cout << c << endl;
			p(ch_board);
			return true;
		}
		else if (ch_board[nx][ny] != c && ch_board[nx][ny] != '.') {
			break;
		}
	}

	nx = x;			ny = y;
	while (++nx <= N - 1) {		//하
		if (ch_board[nx][ny] == c && ch_board[nx][ny] != '.') {
			ch_board[x][y] = '.';
			ch_board[nx][ny] = '.';
			answer.push_back(c);
			cout << c << endl;
			p(ch_board);
			return true;
		}
		else if (ch_board[nx][ny] != c && ch_board[nx][ny] != '.') {
			break;
		}
	}

	return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
	string answer = "";

	M = m;		N = n;
	for (int i = 0; i < m; i++) {
		char * ch = _strdup(board[i].c_str());
		vector<char> v(n);
		ch_board.push_back(v);

		for (int j = 0; j < n; j++) {
			ch_board[i][j] = ch[j];
		}
	}

	//p(ch_board);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (ch_board[i][j] != '.' || ch_board[i][j] != '*') {
				if (inLine(i, j, ch_board[i][j])) {		//직선 거리
					continue;
				}
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}cout << endl;

	return answer;
}

int main() {
	vector<string> vec = { "DBA", "C*A", "CDB" };
	solution(3, 3, vec);

	return 0;
}