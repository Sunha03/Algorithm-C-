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
	sort(crew.begin(), crew.end());								//crew ������������ ����

	for (int i = 0; i < n; i++) {								//bus �ð�ǥ vector
		bus.push_back({ bus_time });
		bus_time += t;
	}

	for (int i = 0; i < n; i++) {								//���� �ð��뺰 ž���� ���� vector
		vector<int> s(m);
		shuttle.push_back(s);
	}

	int index_crew = 0;
	for (int i = 0; i < n; i++) {								//���� n����ŭ
		queue<int> line;										//i�� ������ ž���� �� �ִ� �����
		for (int j = index_crew; j < crew.size(); j++) {		//ť�� ����
			if (bus[i] >= crew[j]) {
				line.push(j);
				index_crew++;
			}
		}

		while (!line.empty()) {									//ž���� ť�� �� ������
			int now = line.front();
			line.pop();

			int end = 0;
			for (int j = i; j < n; j++) {						//i��° ��Ʋ��������
				for (int k = 0; k < m; k++) {					//���ʴ�� ����
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
	if (shuttle[n - 1][m - 1] == 0) {				//������ ��Ʋ������ �ڸ��� ������
		answer = ansToStr(bus[n - 1]);				//������ ���� �ð�
		cout << answer << endl;
	}
	else {											//�ڸ��� ������ ������ ž���� - 1
		answer = ansToStr(crew[shuttle[n - 1][m - 1] - 1] - 1);
		cout << answer << endl;
	}

	return answer;
}