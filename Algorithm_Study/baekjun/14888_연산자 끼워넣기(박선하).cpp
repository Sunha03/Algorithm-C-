#include <iostream>

using namespace std;

int n, sum_operator = 0, num_min = 1000000001, num_max = -1000000001;
int A[12];
int num_operator[4] = { 0, };

void calculate(int idx, int before, int count) {			//DFS
	int oper = 0;
	int after = A[idx + 1];

	if (count == sum_operator) {			//모든 연산자 넣기완료
		if (before < num_min)
			num_min = before;
		if (before > num_max)
			num_max = before;

		return;
	}

	while (oper < 4) {
		if (oper == 0) {
			if (num_operator[0] > 0) {
				num_operator[0]--;
				calculate(idx + 1, before + after, count + 1);
				num_operator[0]++;
			}
			oper++;
		}
		else if (oper == 1) {
			if (num_operator[1] > 0) {
				num_operator[1]--;
				calculate(idx + 1, before - after, count + 1);
				num_operator[1]++;
			}
			oper++;
		}
		else if (oper == 2) {
			if (num_operator[2] > 0) {
				num_operator[2]--;
				calculate(idx + 1, before * after, count + 1);
				num_operator[2]++;
			}
			oper++;
		}
		else if (oper == 3) {
			if (num_operator[3] > 0) {
				num_operator[3]--;
				calculate(idx + 1, before / after, count + 1);
				num_operator[3]++;
			}
			oper++;
		}
	}
}

int main() {
	cin >> n;							//input
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> num_operator[i];

		if (num_operator[i] != 0)
			sum_operator += num_operator[i];
	}

	calculate(0, A[0], 0);

	cout << num_max << "\n" << num_min << "\n";

	return 0;
}