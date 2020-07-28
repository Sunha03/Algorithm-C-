#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void p(vector<vector<int>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	vector<vector<int>> times;

	for (int i = 0; i < food_times.size(); i++)
	{
		times.push_back({ food_times[i], i + 1 });
	}
	sort(times.begin(), times.end());

	int end = 0;
	for (int i = 0; i < times.size(); i++) {

	}

	for (int i = 0; i < food_times.size(); i++) {
		if (food_times[i] != 0) {
			k--;
		}
		if (k == 0) {
			answer = i + 1;
			cout << answer << endl;
			break;
		}
	}

	return answer;
}

int main()
{
	vector<int> v = { 3, 1, 2 };
	solution(v, 5);

	return 0;
}

/*
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
}*/

/*vector<vector<int>> times;

	for (int i = 0; i < food_times.size(); i++)
	{
		times.push_back({ food_times[i], i + 1});
	}
	sort(times.begin(), times.end(), greater<vector<int>>());

	while (k > 0) {
		for (int i = times.size() - 1; i >= 0; i--) {
			for (int j = 0; j < times[i][0]; j++) {
				if (k >= i) {
					for (int k = 0; k < i; k++) {
						times[k][0] -= 1;
					}
					k -= i;
					cout << i << " " << j << " " << k << " " << endl;
					p(times);
					break;
				}
				else {
					end = 1;
					break;
				}
			}
			if (end == 1) {
				break;
			}
		}
		if (end == 1) {
			answer = times[k][1] + 1;
			break;
		}
	}
	//p(times);
	cout << answer << endl;vector<vector<int>> times;

	for (int i = 0; i < food_times.size(); i++)
	{
		times.push_back({ food_times[i], i + 1});
	}
	sort(times.begin(), times.end(), greater<vector<int>>());

	while (k > 0) {
		for (int i = times.size() - 1; i >= 0; i--) {
			for (int j = 0; j < times[i][0]; j++) {
				if (k >= i) {
					for (int k = 0; k < i; k++) {
						times[k][0] -= 1;
					}
					k -= i;
					cout << i << " " << j << " " << k << " " << endl;
					p(times);
					break;
				}
				else {
					end = 1;
					break;
				}
			}
			if (end == 1) {
				break;
			}
		}
		if (end == 1) {
			answer = times[k][1] + 1;
			break;
		}
	}
	//p(times);
	cout << answer << endl;
	*/