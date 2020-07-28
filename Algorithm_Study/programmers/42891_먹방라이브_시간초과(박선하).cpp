#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int index = 0;

	while (k >= 0) {
		int end = 0;
		while (end == 0) {
			if (food_times[index] > 0) {
				food_times[index] -= 1;
				k--;
				end = 1;
				answer = index + 1;
			}

			if (index == food_times.size() - 1) {
				index = 0;
			}
			else {
				index++;
			}
		}
	}

	return answer;
}