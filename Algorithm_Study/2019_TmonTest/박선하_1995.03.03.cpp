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
	cout << "�����ð�(�ð�), �丮��(��), û�� ����(��), ���̺�(��)�� ���ʴ�� �Է����ּ���.\n";
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
		if ((now_time % 10) == 0) {		//10�и��� �մ� 7�� ����
			for (int i = 0; i < 5; i++)
				wait_custom[i] = wait_custom[i + 1];
			wait_custom[5] = 7;

			in_custom = 0;
			for (int i = 0; i < 6; i++)
				in_custom += wait_custom[i];
		}

		for (int i = 0; i < total_table; i++) {		//�丮, �Ļ�, û�� ����
			if (table[i].empty == false) {
				if (table[i].cooking > 0) {			//�丮 ��
					if (table[i].cooking == 4) {		//�丮 ����
						if (num_cook > 0) {
							num_cook--;
							table[i].cooking--;
						}
					}
					else
						table[i].cooking--;

					if (table[i].cooking == 0)		//�丮 ��
						num_cook++;
				}
				else if (table[i].eating > 0) {		//�Ļ� ��
					table[i].eating--;
					if (table[i].eating == 0) {		//�Ļ� ��
						out_custom++;
					}
				}
				else if (table[i].cleaning > 0) {	//û�� ��
					if (table[i].cleaning == 3) {		//û�� ����
						if (num_clean > 0) {
							num_clean--;
							table[i].cleaning--;
						}
					}
					else
						table[i].cleaning--;

					if (table[i].cleaning == 0) {	//û�� ��
						num_clean++;
						table[i].empty = true;		table[i].cooking = 4;
						table[i].eating = 11;		table[i].cleaning = 3;
						num_table++;
					}
				}
			}
		}

		while (num_table != 0 && in_custom != 0) {	//���̺� ����
			for (int i = 0; i < total_table; i++) {
				if (table[i].empty == true) {		//����
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

	cout << "�Ĵ翡�� �Ļ縦 ��ģ �մ��� �� " << out_custom << "�� �Դϴ�." << endl;

	return 0;
}