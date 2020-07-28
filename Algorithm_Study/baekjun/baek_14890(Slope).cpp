#include <iostream>
#include <vector>

using namespace std;

int N, L, answer = 0;
int res_ver[101] = { 0 };
int res_hor[101] = { 0 };
vector< vector< pair<int, int> > > verticals, horizontals;
vector< vector<int> > map;

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << "\t";
		}cout << endl;
	}cout << endl;
}

void pp(int arr[]) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}cout << endl;
}

void ppp(vector< vector< pair<int, int> > > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j].first << " ";
		}cout << endl;
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j].second << " ";
		}cout << endl << endl;
	}cout << endl;
}

void checkLoad(int * arr, vector< vector< pair<int, int> > > &vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (arr[i] != -1) {
			if (vec[i].size() == 1) {		//모든 칸 높이가 동일
				arr[i] = 1;
				continue;
			}

			for (int j = 0; j < vec[i].size() - 1; j++) {
				int diff = vec[i][j + 1].first - vec[i][j].first;
				if (diff > 1 || diff < -1) {		//칸 높이가 2 이상
					arr[i] = -1;
					break;
				}
				else if (diff == 1) {				//높이 1 증가
					if (vec[i][j].second >= L) {	//경사로 놓기 성공
						vec[i][j].second -= L;
					}
					else {							//경사로 놓기 실패
						arr[i] = -1;
						break;
					}
				}
				else if (diff == -1) {				//높이 1 감소
					if (vec[i][j + 1].second >= L) {	//경사로 놓기 성공
						vec[i][j + 1].second -= L;
					}
					else {								//경사로 놓기 실패
						arr[i] = -1;
						break;
					}
				}

				if (j == vec[i].size() - 2)		//통과 가능
					arr[i] = 1;

			}
		}
	}
}

int main() {
	cin >> N >> L;						//input
	for (int i = 0; i < N; i++) {
		vector<int> m(N);
		map.push_back(m);
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {		//map >> <높이, 연속 개수>로 변환
		int v_num = map[i][0];
		int v_same = 1;
		vector< pair<int, int> > ver;
		for (int j = 1; j < N; j++) {
			if (map[i][j] == v_num) {
				v_same++;

				if (j == N - 1)
					ver.push_back({ map[i][j], v_same });
			}
			else {
				ver.push_back({ v_num, v_same });
				v_num = map[i][j];
				v_same = 1;

				if (j == N - 1)
					ver.push_back({ map[i][j], 1 });
			}
		}
		verticals.push_back(ver);

		int h_num = map[0][i];
		int h_same = 1;
		vector< pair<int, int> > hor;
		for (int j = 1; j < N; j++) {
			if (map[j][i] == h_num) {
				h_same++;

				if (j == N - 1)
					hor.push_back({ map[j][i], h_same });
			}
			else {
				hor.push_back({ h_num, h_same });
				h_num = map[j][i];
				h_same = 1;

				if (j == N - 1)
					hor.push_back({ map[j][i], 1 });
			}
		}
		horizontals.push_back(hor);
	}

	checkLoad(res_ver, verticals);		//통과 여부 검사
	checkLoad(res_hor, horizontals);

	for (int i = 0; i < N; i++) {		//통과 가능한 길 카운트
		if (res_ver[i] == 1)
			answer++;
		if (res_hor[i] == 1)
			answer++;
	}

	cout << "===============vertical=================\n";
	ppp(verticals);
	pp(res_ver);
	cout << "==============horizontal================\n";
	ppp(horizontals);
	pp(res_hor);

	cout << answer << endl;

	/*cout << endl;

	p(verticals);
	p(horizontals);
	pp(vertical);
	pp(horizontal);*/


	return 0;
}