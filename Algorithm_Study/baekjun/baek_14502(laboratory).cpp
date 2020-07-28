#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt, answer;

void p(vector< vector<int> > v)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void initVec(vector< vector<int> > &vec) {
	vec.clear();
	for (int i = 0; i < N; i++) {
		vector<int> v(M);
		vec.push_back(v);
	}
}

void virus(int x, int y, vector< vector<int> > &visit, vector< vector<int> > &labo) {
	if (visit[x][y] == 1) {
		return;
	}
	else {
		visit[x][y] = 1;

		if (labo[x][y] == 0 || labo[x][y] == 2) {
			labo[x][y] = 2;
			if (x > 0) {
				virus(x - 1, y, visit, labo);
			}
			if (x < N - 1) {
				virus(x + 1, y, visit, labo);
			}
			if (y > 0) {
				virus(x, y - 1, visit, labo);
			}
			if (y < M - 1) {
				virus(x, y + 1, visit, labo);
			}
		}
		else if (labo[x][y] == 1) {
			return;
		}
	}
}

void wall(int num, vector< vector<int> > &labo)
{
	if (num == 3) {								//벽 3개 생성 완료
		vector< vector<int> > visit;
		vector< vector<int> > v_labo;

		v_labo = labo;
		initVec(visit);
		for (int i = 0; i < N; i++) {			//바이러스 퍼짐
			for (int j = 0; j < M; j++) {
				if (labo[i][j] == 2) {
					virus(i, j, visit, v_labo);
				}
			}
		}

		cnt = 0;
		for (int i = 0; i < N; i++) {			//0인 영역 count
			for (int j = 0; j < M; j++) {
				if (v_labo[i][j] == 0) {
					cnt++;
				}
			}
		}

		if (answer < cnt) {						//최대값 찾기
			answer = cnt;
		}

		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (labo[i][j] == 0) {
				labo[i][j] = 1;
				wall(num + 1, labo);

				labo[i][j] = 0;
			}
		}
	}
}

int main()
{
	int n, m;
	answer = 0;
	vector< vector<int> > labo;
	vector< vector<int> > laboratory;

	n = 7;	m = 7;	N = n;	M = m;
	laboratory = { { 2, 0, 0, 0, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 2, 0 },
	{ 0, 1, 1, 0, 1, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1 },
	{ 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0 }
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (laboratory[i][j] == 0) {
				labo = laboratory;
				labo[i][j] = 1;
				wall(1, labo);

				labo[i][j] = 0;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}
/*(input)
cin >> n >> m;
N = n;
M = m;

initVec(laboratory);
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++) {
		cin >> laboratory[i][j];
	}
}
*/


/*
n = 4;	m = 6;	N = n;	M = m;
laboratory = { { 0, 0, 0, 0, 0, 0 },
{ 1, 0, 0, 0, 0, 2 },
{ 1, 1, 1, 0, 0, 2 },
{ 0, 0, 0, 0, 0, 2 }
};

n = 7;	m = 7;	N = n;	M = m;
laboratory = { { 2, 0, 0, 0, 1, 1, 0 },
{ 0, 0, 1, 0, 1, 2, 0 },
{ 0, 1, 1, 0, 1, 0, 0 },
{ 0, 1, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 1, 1 },
{ 0, 1, 0, 0, 0, 0, 0 },
{ 0, 1, 0, 0, 0, 0, 0 }
};


n = 8;	m = 8;	N = n;	M = m;
laboratory = { { 2, 0, 0, 0, 0, 0, 0, 2 },
{ 2, 0, 0, 0, 0, 0, 0, 2 },
{ 2, 0, 0, 0, 0, 0, 0, 2 },
{ 2, 0, 0, 0, 0, 0, 0, 2 },
{ 2, 0, 0, 0, 0, 0, 0, 2 },
{ 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0 }
};
*/