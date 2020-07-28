#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string ansToStr(int time) {			//int to string(900 -> "15:00")
	int hour = time / 60;
	int minute = time % 60;
	string ans;

	if (hour < 10) {
		ans += "0";
	}
	ans += to_string(hour);
	ans += ":";
	if (minute < 10) {
		ans += "0";
	}
	ans += to_string(minute);

	return ans;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int bus_time = 9 * 60;
	vector<int> bus;
	vector<int> crew;
	vector<vector<int>> shuttle;

	for (int i = 0; i < timetable.size(); i++) {				//timetable string to int("15:00" -> 900)
		struct tm tm;
		if (strptime(timetable[i].c_str(), "%H:%M", &tm)) {
			crew.push_back({ tm.tm_hour * 60 + tm.tm_min });
		}
	}
	sort(crew.begin(), crew.end());								//crew 오름차순으로 정리

	for (int i = 0; i < n; i++) {								//bus 시간표 vector
		bus.push_back({ bus_time });
		bus_time += t;
	}

	for (int i = 0; i < n; i++) {								//버스 시간대별 탑승자 여부 vector
		vector<int> s(m);
		shuttle.push_back(s);
	}

	int index_crew = 0;
	for (int i = 0; i < n; i++) {								//버스 n번만큼
		queue<int> line;										//i번 버스에 탑승할 수 있는 사람을
		for (int j = index_crew; j < crew.size(); j++) {		//큐에 저장
			if (bus[i] >= crew[j]) {
				line.push(j);
				index_crew++;
			}
		}

		while (!line.empty()) {									//탑승자 큐가 빌 때까지
			int now = line.front();
			line.pop();

			int end = 0;
			for (int j = i; j < n; j++) {						//i번째 셔틀버스부터
				for (int k = 0; k < m; k++) {					//차례대로 저장
					if (shuttle[j][k] == 0) {
						shuttle[j][k] = now + 1;
						end = 1;
						break;
					}
				}
				if (end == 1) {
					break;
				}
			}
		}
	}

	string strH, strM;
	if (shuttle[n - 1][m - 1] == 0) {				//마지막 셔틀버스에 자리가 있으면
		answer = ansToStr(bus[n - 1]);				//마지막 버스 시간
		cout << answer << endl;
	}
	else {											//자리가 없으면 마지막 탑승자 - 1
		answer = ansToStr(crew[shuttle[n - 1][m - 1] - 1] - 1);
		cout << answer << endl;
	}

	return answer;
}