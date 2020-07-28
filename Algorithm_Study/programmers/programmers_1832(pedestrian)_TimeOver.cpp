#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;
int M, N;
int cnt;

//�ð��ʰ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void move(int x, int y, vector<vector<int>> &map, int dir) {		//dir 0:��>�Ʒ�, 1:��>��
	if (x == M - 1 && y == N - 1) {			//end ����
		cnt++;
		return;
	}

	if (map[x][y] == 1) {					//�ڵ��� X
		return;
	}

	if (map[x][y] == 0) {						//�̵�
		if (x < M - 1) {						//�� > �Ʒ�
			move(x + 1, y, map, 0);
		}
		if (y < N - 1) {						//�� > ��
			move(x, y + 1, map, 1);
		}
	}
	else if (map[x][y] == 2) {
		if (dir == 0) {							//�� > �Ʒ�
			if (x < M - 1) {
				move(x + 1, y, map, 0);
			}
		}
		else if (dir == 1) {					//�� > ��
			if (y < N - 1) {
				move(x, y + 1, map, 1);
			}
		}
	}
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;

	M = m;
	N = n;
	cnt = 0;

	move(0, 0, city_map, 0);

	answer = cnt % MOD;
	cout << cnt << ", " << answer << "\n";

	return answer;
}

int main()
{
	int m = 3;
	int n = 6;
	vector<vector<int>> city_map = {
		{ 0, 2, 0, 0, 0, 2 },
		{ 0, 0, 2, 0, 1, 0 },
		{ 1, 0, 0, 2, 2, 0 }
	};

	solution(m, n, city_map);
	return 0;
}

/*
int m = 3;
int n = 6;
vector<vector<int>> city_map = {
{ 0, 2, 0, 0, 0, 2 },
{ 0, 0, 2, 0, 1, 0 },
{ 1, 0, 0, 2, 2, 0 }
};
*/

/*
int m = 3;
int n = 3;
vector<vector<int>> city_map = {
{ 0, 0, 0 },
{ 0, 0, 0 },
{ 0, 0, 0 }
};
*/