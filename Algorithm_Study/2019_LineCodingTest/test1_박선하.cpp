#include <iostream>
#include <algorithm>

using namespace std;


int main(void) {
	long long n, idx = 1, num_min = 10000000000001;
	cin >> n;

	while (idx <= sqrt(n)) {		//n�� �����ٱ��� ���� �� �ִ� ���� Ž��
		if (n % idx == 0) {
			cout << idx << " X " << n / idx << " : " << abs(idx - n / idx) << endl;

			if ((long long)abs(idx - n / idx) < num_min) {
				num_min = abs(idx - n / idx);
			}
		}

		idx++;
	}

	cout << num_min << endl;

	return 0;
}