#include <string>
#include <vector>
#include <iostream>

using namespace std;

void p(vector<string> st, vector<int> in) {
	for (int i = 0; i < st.size(); i++) {
		cout << st[i] << "\t" << in[i] << endl;
	}
	cout << endl;
}

string alphabet(string str) {				//�빮�� > �ҹ���
	char * ch = _strdup(str.c_str());

	for (int i = 0; i < strlen(ch); i++) {
		if (ch[i] >= 65 && ch[i] <= 90) {
			ch[i] += 32;
		}
	}

	return ch;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int num_in = 0;
	vector<string> cache_str;
	vector<int> cache_num;

	if (cacheSize == 0) {		//all cache miss
		answer = cities.size() * 5;

		return answer;
	}

	for (int i = 0; i < cities.size(); i++) {	//�빮�� > �ҹ���
		cities[i] = alphabet(cities[i]);
	}

	for (int i = 1; i <= cacheSize; i++) {		//���� �ʱ�ȭ
		cache_str.push_back("");
		cache_num.push_back(-1 * i);
	}

	for (int i = 0; i < cities.size(); i++) {
		int idx_min = -1;
		int min = 100001;

		for (int j = 0; j < cacheSize; j++) {
			if (cache_num[j] < min) {				//���� ���� �Էµ� string�� �ε��� ����
				idx_min = j;
				min = cache_num[j];
			}

			if (cities[i] == cache_str[j]) {			//cache hit
				cache_num[j] = ++num_in;
				answer += 1;
				p(cache_str, cache_num);

				break;
			}
			else if (j == cacheSize - 1 && cities[i] != cache_str[j]) {		//cache miss
				cache_str[idx_min] = cities[i];
				cache_num[idx_min] = ++num_in;
				answer += 5;
				p(cache_str, cache_num);
			}
		}
	}

	cout << answer << endl;

	return answer;
}

int main() {
	int c = 3;
	vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

	solution(c, cities);

	return 0;
}