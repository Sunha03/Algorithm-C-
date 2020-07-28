#include <iostream>
#include <vector>

using namespace std;

int n, l, r, uniCount = 0, num_of_unite = 0, answer = -1;
vector< vector<int> > country, h, v, unite, sum_of_unite;


void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool inRange(int num1, int num2) {			//L <= 인구 차이 <= R
	int dif = abs(num1 - num2);

	if (dif >= l && dif <= r)
		return true;
	else
		return false;
}

int findUnite(int x, int y, int uniSum) {		//연합 찾기
	int sum = 0;

	uniCount++;
	unite[x][y] = uniSum;
	sum += country[x][y];

	if (x > 0)
		if (v[x - 1][y] == 1)
			if (unite[x - 1][y] == 0)
				sum += findUnite(x - 1, y, uniSum);


	if (x < n - 1)
		if (v[x][y] == 1)
			if (unite[x + 1][y] == 0)
				sum += findUnite(x + 1, y, uniSum);


	if (y > 0)
		if (h[x][y - 1] == 1)
			if (unite[x][y - 1] == 0)
				sum += findUnite(x, y - 1, uniSum);


	if (y < n - 1)
		if (h[x][y] == 1)
			if (unite[x][y + 1] == 0)
				sum += findUnite(x, y + 1, uniSum);


	return sum;
}

int main() {
	cin >> n >> l >> r;					//Input
	for (int i = 0; i < n; i++) {
		vector<int> c(n);
		country.push_back(c);

		for (int j = 0; j < n; j++)
			cin >> country[i][j];
	}

	while (num_of_unite != n * n) {			//(연합 개수 = 나라 개수)일 때까지
		num_of_unite = 0;					//초기화
		h.clear();			v.clear();				unite.clear();			sum_of_unite.clear();
		for (int i = 0; i < n; i++) {
			vector<int> c(n);
			country.push_back(c);
			h.push_back(c);
			v.push_back(c);
			unite.push_back(c);
		}

		for (int j = 0; j < n; j++)				//가로 국경선
			for (int i = 0; i < n - 1; i++)
				if (inRange(country[i][j], country[i + 1][j]))
					v[i][j] = 1;

		for (int i = 0; i < n; i++)				//세로 국경선
			for (int j = 0; j < n - 1; j++)
				if (inRange(country[i][j], country[i][j + 1]))
					h[i][j] = 1;

		for (int i = 0; i < n; i++) {			//연합 찾기
			for (int j = 0; j < n; j++) {
				if (unite[i][j] == 0) {
					uniCount = 0;
					int sum = findUnite(i, j, num_of_unite++);

					sum_of_unite.push_back({ uniCount, sum });
				}
			}
		}

		for (int i = 0; i < n; i++) {			//이동한 인구 수 계산
			for (int j = 0; j < n; j++) {
				int n_unite = unite[i][j] - 1;
				country[i][j] = sum_of_unite[n_unite][1] / sum_of_unite[n_unite][0];
			}
		}

		answer++;
	}

	cout << answer << endl;
	//p(country);
	//p(unite);

	return 0;
}