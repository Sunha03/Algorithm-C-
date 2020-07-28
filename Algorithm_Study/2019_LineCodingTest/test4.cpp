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

		if (h > max_height)		//�ְ��� ���� ����
			max_height = h;
	}

	for (int i = 0; i < n - 1; i++) {
		if (height[i] != max_height) {	//�ְ� ���̰� �ƴϸ�
			int idx = i + 1;

			//���� ���ų� ���� ���� ã��
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