#include <iostream>
#include <vector>

using namespace std;

int n, num_max = 0;
vector< vector<int> > input;

void counseling(int today, int sum) {
	int next = today + input[today][0];

	if (today < n - 1) {
		if (next < n) {					//���� ����� ã��
			for (int i = next; i < n; i++) {
				counseling(i, sum + input[today][1]);
			}
		}
		else if (next == n) {			//���� ��� X & ���� ��� O
			if (num_max < sum + input[today][1]) {
				num_max = sum + input[today][1];
			}
		}
		else {							//���� ��� O & ���� ��� O
			if (num_max < sum) {
				num_max = sum;
			}

		}
	}
	else if (today == n - 1) {			//n��°��
		if (next <= n) {				//t == 1(���O)
			if (num_max < sum + input[today][1]) {
				num_max = sum + input[today][1];
			}
		}
		else {							//t != 1(���X)
			if (num_max < sum) {
				num_max = sum;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> c(2);
		input.push_back(c);
		for (int j = 0; j < 2; j++) {
			cin >> input[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		counseling(i, 0);
	}


	cout << num_max << endl;

	return 0;
}