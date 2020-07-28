#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, max_height = -1, answer = -1;
	vector<int> height;

	cin >> n;		//input
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		height.push_back(h);

		if (h > max_height)		//최고층 높이 저장
			max_height = h;
	}

	for (int i = 0; i < n - 1; i++) {
		if (height[i] != max_height) {	//최고 높이가 아니면
			int idx = i + 1;

			//나와 같거나 높은 빌딩 찾기
			while (true) {
				if (height[i] <= height[idx]) {
					if (answer < idx - i) {
						answer = idx - i;
					}
					break;
				}

				idx++;
			}
		}
	}

	cout << answer << endl;

	return 0;
}