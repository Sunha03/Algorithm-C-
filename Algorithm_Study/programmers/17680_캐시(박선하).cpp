#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

string alphabet(string str) {				//대문자 > 소문자
	char * ch = strdup(str.c_str());

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

	for (int i = 0; i < cities.size(); i++) {	//대문자 > 소문자
		cities[i] = alphabet(cities[i]);
	}

	for (int i = 1; i <= cacheSize; i++) {		//벡터 초기화
		cache_str.push_back("");
		cache_num.push_back(-1 * i);
	}

	for (int i = 0; i < cities.size(); i++) {
		int idx_min = -1;
		int min = 100001;

		for (int j = 0; j < cacheSize; j++) {
			if (cache_num[j] < min) {			//가장 먼저 입력된 string의 인덱스 갱신
				idx_min = j;
				min = cache_num[j];
			}

			if (cities[i] == cache_str[j]) {		//cache hit
				cache_num[j] = ++num_in;
				answer += 1;

				break;
			}
			else if (j == cacheSize - 1 && cities[i] != cache_str[j]) {		//cache miss
				cache_str[idx_min] = cities[i];
				cache_num[idx_min] = ++num_in;
				answer += 5;
			}
		}
	}

	cout << answer << endl;

	return answer;
}