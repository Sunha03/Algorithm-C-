#include <iostream>

using namespace std;

class Table {
public:
	bool empty;
	int cooking;
	int eating;
	int cleaning;
};

int total_time = 0, total_cook = 0, total_clean = 0, total_table = 0;
int now_time = 0, num_cook = 0, num_clean = 0, num_table = 0;
int in_custom = 0, out_custom = 0;
int wait_custom[6] = { 0, 0, 0, 0, 0, 0 };

int main() {
	//input
	cout << "측정시간(시간), 요리사(명), 청소 스텝(명), 테이블(개)을 차례대로 입력해주세요.\n";
	cin >> total_time;		cin >> total_cook;
	cin >> total_clean;		cin >> total_table;

	//init
	total_time *= 60;
	num_cook = total_cook;		num_clean = total_clean;		num_table = total_table;
	Table *table = new Table[total_table];
	for (int i = 0; i < total_table; i++) {
		table[i].empty = true;		table[i].cooking = 4;
		table[i].eating = 11;		table[i].cleaning = 3;
	}

	while (now_time != total_time || now_time == 0) {
		if ((now_time % 10) == 0) {		//10분마다 손님 7명 입장
			for (int i = 0; i < 5; i++)
				wait_custom[i] = wait_custom[i + 1];
			wait_custom[5] = 7;

			in_custom = 0;
			for (int i = 0; i < 6; i++)
				in_custom += wait_custom[i];
		}

		for (int i = 0; i < total_table; i++) {		//요리, 식사, 청소 진행
			if (table[i].empty == false) {
				if (table[i].cooking > 0) {			//요리 중
					if (table[i].cooking == 4) {		//요리 시작
						if (num_cook > 0) {
							num_cook--;
							table[i].cooking--;
						}
					}
					else
						table[i].cooking--;

					if (table[i].cooking == 0)		//요리 끝
						num_cook++;
				}
				else if (table[i].eating > 0) {		//식사 중
					table[i].eating--;
					if (table[i].eating == 0) {		//식사 끝
						out_custom++;
					}
				}
				else if (table[i].cleaning > 0) {	//청소 중
					if (table[i].cleaning == 3) {		//청소 시작
						if (num_clean > 0) {
							num_clean--;
							table[i].cleaning--;
						}
					}
					else
						table[i].cleaning--;

					if (table[i].cleaning == 0) {	//청소 끝
						num_clean++;
						table[i].empty = true;		table[i].cooking = 4;
						table[i].eating = 11;		table[i].cleaning = 3;
						num_table++;
					}
				}
			}
		}

		while (num_table != 0 && in_custom != 0) {	//테이블 착석
			for (int i = 0; i < total_table; i++) {
				if (table[i].empty == true) {		//착석
					table[i].empty = false;
					num_table--;

					for (int j = 0; j < 6; j++) {
						if (wait_custom[j] > 0) {
							wait_custom[j]--;
							break;
						}
					}
					in_custom--;
				}
			}

		}


		now_time++;
	}

	cout << "식당에서 식사를 마친 손님은 총 " << out_custom << "명 입니다." << endl;

	return 0;
}