#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, size_combi = 1, sum_ability = 0, num_min = 20001;
int person[21] = { 0 };
int person_combi[21], person_pair[3];
vector<int> start, link;
vector< vector<int> > S;
vector< vector<int> > team_combi;

void p(vector< vector<int> > vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " "
				;
		}cout << endl;
	}cout << endl;
}

//조합 찾기(nCr)
void combination(int arr[21], int index, int n, int r, int target) {
	if (r == 0) {
		vector<int> team;
		team.push_back(0);

		for (int i = 0; i < index; i++) {
			team.push_back(arr[i]);
			//cout << arr[i] << " ";
		}//cout << endl;

		team_combi.push_back(team);
	}
	else if (target == n) {
		return;
	}
	else {
		arr[index] = target;
		combination(arr, index + 1, n, r - 1, target + 1);
		combination(arr, index, n, r, target + 1);
	}
}

//조합 찾기(nC2)
void combination_pair(vector<int> &vec, int arr[3], int index, int n, int r, int target) {
	if (r == 0) {
		sum_ability += S[arr[0]][arr[1]] + S[arr[1]][arr[0]];
		/*for (int i = 0; i < index; i++) {
			cout << arr[i] << " " ;
			//sum_ability += S[arr[i]][arr[i + 1]] + S[arr[i + 1]][arr[i]];
		}cout << endl;*/

		vec[0] = sum_ability;
	}
	else if (target == vec.size()) {
		return;
	}
	else {
		arr[index] = vec[target];
		combination_pair(vec, arr, index + 1, n, r - 1, target + 1);
		combination_pair(vec, arr, index, n, r, target + 1);
	}
}

int main() {
	cin >> n;				//input
	for (int i = 0; i < n; i++) {
		vector<int> s(n);
		S.push_back(s);

		for (int j = 0; j < n; j++) {
			cin >> S[i][j];
		}
	}

	//조합 가지 수
	/*for (int i = n; i > n / 2; i--)
		size_combi *= i;
	for (int i = 1; i <= n / 2; i++)
		size_combi /= i;
	size_combi /= 2;*/

	combination(person_combi, 0, n, n / 2, 0);		//전체 팀 조합 찾기

	//p(team_combi);

	for (int i = 0; i < team_combi.size(); i++) {	//조합된 팀 내에서 사람 i, j 조합 찾기
		/*cout << "----------Team" << i << "-----------\n";
		for (int j = 0; j < team_combi[i].size(); j++)
			cout << team_combi[i][j] << " ";
		cout << endl;*/

		sum_ability = 0;
		combination_pair(team_combi[i], person_pair, 0, team_combi.size(), 2, 1);
	}

	for (int i = 0; i < team_combi.size() / 2; i++) {		//능력치 값 최소 찾기
		int diff = abs(team_combi[i][0] - team_combi[team_combi.size() - 1 - i][0]);
		if (diff < num_min)
			num_min = diff;
	}

	cout << num_min << endl;

	//p(team_combi);

	//p(S);

	return 0;
}