#include <vector>
#include <iostream>

using namespace std;

int N, max_people = 0;

int findMinDistance() {
	for (int dis = 8; dis >= 2; dis--) {
		vector<pair<int, int>> people;
		int locker[11][11] = { 0, };

		locker[0][0] = 1;
		people.push_back({ 0, 0 });

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (locker[i][j] == 0) {				//라커에 사람이 없으면
					for (int k = 0; k < people.size(); k++) {			//모든 사람들과 비교
						if (abs(people[k].first - i) + abs(people[k].second - j) < dis) {
							break;
						}
						else if (k == people.size() - 1) {
							locker[i][j] = 1;
							people.push_back({ i, j });

							if (people.size() == max_people) {
								/*cout << "END-----------" << dis << "------------\n";
								for (int x = 0; x < N; x++) {
									for (int y = 0; y < N; y++) {
										cout << locker[x][y] << " ";
									}cout << endl;
								}cout << endl;*/

								return dis;
							}
						}
					}

					if (i == N - 1 && j == N - 1 && people.size() < max_people) {
						continue;
					}
				}
			}
		}
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
	int answer = 20;
	int now_time = 1330, end_time = 590;
	int visit[1001] = { 0, };
	N = n;

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

	if (max_people == 1) {					//최소 손님 간의 거리
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
	else if (max_people > n * n / 2 + (n % 2) && max_people <= n * n * 2) {
		answer = 1;
	}
	else {
		answer = findMinDistance();
	}

	cout << max_people << endl;
	cout << answer << endl;

	return answer;
}

int main() {
	vector<vector<int>> time = { {1140, 1200},{ 1140, 1200 },{ 1140, 1200 },{ 1140, 1200 },{ 1140, 1200 },{ 1140, 1200 },{ 1140, 1200 },{ 1140, 1200 },{1150, 1200}, {1100, 1200}, {1210, 1300}, {1220, 1280} };
	solution(7, 9, time);

	return 0;
}