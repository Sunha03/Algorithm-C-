#include <iostream>
#include <algorithm>

using namespace std;


int main(void) {
	long long n, idx = 1, num_min = 10000000000001;
	cin >> n;

	while (idx <= n) {
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

/*bool findWH(int begin, int end) {
	while (--end >= begin) {
		if (n % end == 0) {
			int h = n / end;
			int w = end;

			cout << abs(h - w) << endl;
			cout << "h : " << h << ", w : " << w << endl;

			return true;
		}
	}
}

int main(void) {
	cin >> n;

	for (int i = 1; i < 3162277; i++) {
		if (n >= i * i && n < (i + 1)*(i + 1)) {
			cout << "i : " << i << endl;
			if (findWH(i * i, (i + 1)*(i + 1))) {
				break;
			}
		}
	}


	return 0;
}*/