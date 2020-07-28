#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int edges[201][201] = { 0, };
int shortest[201][201] = { -1, };
int possible[100] = { 0, };

void Dijkstra(int start) {
	int visit[201] = { 0, };				//방문 여부
	queue<int> q;
	q.push(start);

	shortest[start][start] = 0;				//i > j 최소 경로 길이

	while (!q.empty()) {
		int now = q.front();

		if (visit[now] == 0) {
			visit[now] = 1;

			for (int i = 0; i < N; i++) {
				if (edges[now][i] == 1) {
					if (shortest[start][i] < 0 || shortest[start][i] > shortest[start][now] + 1) {
						shortest[start][i] = shortest[start][now] + 1;
						shortest[i][start] = shortest[start][now] + 1;
					}

					q.push(i);
				}
			}
		}

		q.pop();
	}

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int answer = 0;

	N = n;

	for (int i = 0; i < edge_list.size(); i++) {		//길 여부(0:없음, 1:있음)
		int n1 = edge_list[i][0] - 1;
		int n2 = edge_list[i][1] - 1;

		edges[i][i] = 1;
		edges[n1][n2] = 1;
		edges[n2][n1] = 1;
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << edges[i][j] << " ";
		}cout << endl;
	}cout << endl;*/

	memset(shortest, -1, sizeof(shortest));

	for (int i = 0; i < n; i++)							//최소 경로 길이 계산(다익스트라)
		Dijkstra(i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << shortest[i][j] << " ";
		}cout << endl;
	}cout << endl;

	for (int i = 0; i < gps_log.size() - 1; i++) {		//불가능한 경로 찾기 & 수정
		if (edges[gps_log[i] - 1][gps_log[i + 1] - 1] == 0) {
			for (int j = i + 1; j < gps_log.size(); j++) {
				if (shortest[gps_log[i] - 1][gps_log[j] - 1] <= j - i) {
					cout << gps_log[i] << " " << gps_log[j] << endl;
					answer += j - i - 1;
					cout << i << " " << j << " " << answer << endl;

					i = j;
					break;
				}
				else if (j == gps_log.size() - 1) {
					return -1;
				}
			}
		}
	}

	cout << answer << endl;

	return answer;
}

int main() {
	vector<vector<int>> el = { {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7} };
	vector<int> gl = { 1, 2, 3, 3, 6, 7 };

	solution(7, 10, el, 6, gl);

	return 0;
}