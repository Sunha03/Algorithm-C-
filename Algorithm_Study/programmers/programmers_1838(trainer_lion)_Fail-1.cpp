#include <vector>
#include <iostream>

using namespace std;

void p(vector<vector<int>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
	int answer = 0;
	int now_time = 1330, end_time = 590, max_people = 0;
	int visit[1001] = { 0, };

	for (int i = 0; i < m; i++) {
		if (now_time > timetable[i][0])
			now_time = timetable[i][0];
		if (end_time < timetable[i][1])
			end_time = timetable[i][1];
	}

	while (now_time <= end_time) {				//최대 겹치는 손님 수 계산
		int num_people = 0;

		for (int i = 0; i < m; i++) {
			if (timetable[i][0] <= now_time && timetable[i][1] >= now_time) {
				visit[i] = 1;
			}
			else {
				visit[i] = 0;

				if (timetable[i][0] > now_time)
					break;
			}
		}

		for (int j = 0; j < m; j++)
			if (visit[j] == 1)
				num_people++;

		if (max_people < num_people)
			max_people = num_people;

		now_time += 10;
	}

	if (max_people == 1) {
		answer = 0;
	}
	else if (max_people == 2) {
		answer = (n - 1) * 2;
	}
	else if (max_people == 3) {
		answer = 2 * (n - 1) - (n / 2);
	}
	else if (max_people == 4) {
		answer = n;
	}
	else if (max_people == 5) {
		if (max_people % 2 == 0)
			answer = n - 2;
		else
			answer = n - 1;
	}
	else if (max_people >= 6 && max_people <= 8) {
		if (max_people % 2 == 0)
			answer = n / 2;
		else
			answer = (n + 1) / 2;
	}
	else if (n == 7 && max_people >= 9 && max_people <= 10) {
		if (max_people == 9 || max_people == 10)
			answer = 3;
	}
	else if (n == 8 && max_people >= 9 && max_people <= 12) {
		if (max_people >= 9 && max_people <= 12)
			answer = 3;
	}
	else if (n == 9 && max_people >= 9 && max_people <= 16) {
		if (max_people >= 9 && max_people <= 13)
			answer = 4;
		else if (max_people >= 14 && max_people <= 16)
			answer = 3;
	}
	else if (n == 10 && max_people >= 9 && max_people <= 18) {
		if (max_people >= 9 && max_people <= 13)
			answer = 4;
		else if (max_people >= 14 && max_people <= 18)
			answer = 3;
	}
	else if (max_people % 2 == 0 && max_people <= n * n / 2) {
		answer = 2;
	}
	else if (max_people % 2 == 1 && max_people <= n * n / 2 + 1) {
		answer = 2;
	}
	else {
		answer = 1;
	}

	cout << max_people << endl;
	cout << answer << endl;

	return answer;
}

int main() {
	vector<vector<int>> time = { { 1140, 1200 },{ 1150, 1200 },{ 1100, 1200 },{ 1210, 1300 },{ 1220, 1280 } };
	solution(4, 5, time);

	return 0;
}