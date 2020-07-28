#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;

	vector<vector<int>> h, v;
	for (int i = 0; i < m; i++) {
		vector<int> temp(n);
		h.push_back(temp);
		v.push_back(temp);
	}


	h[0][0] = 1;
	v[0][0] = 1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (city_map[i][j] == 0) {
				if (j > 0) {
					h[i][j] += h[i][j - 1];
					v[i][j] += h[i][j - 1];
				}
				if (i > 0) {
					h[i][j] += v[i - 1][j];
					v[i][j] += v[i - 1][j];
				}
				h[i][j] %= MOD;
				v[i][j] %= MOD;
			}
			if (city_map[i][j] == 1) {
				h[i][j] = 0;
				v[i][j] = 0;
			}
			else if (city_map[i][j] == 2) {
				if (j > 0) {
					h[i][j] = h[i][j - 1];
				}
				if (i > 0) {
					v[i][j] = v[i - 1][j];
				}
			}
		}
	}

	answer = h[m - 1][n - 2] + v[m - 2][n - 1];
	answer %= MOD;
	cout << answer << "\n";

	return answer;
}
