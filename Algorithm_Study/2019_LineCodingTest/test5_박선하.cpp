#include <iostream>
#include <queue>

using namespace std;

int cony, brown, move_cony = 1, n = 0, num_count = 1, answer = 0;
queue<int> que_brown;

int findN(int count) {		//N초 찾기
	int indice = 0;

	while (1) {
		if (count >= pow(3, indice) && count < pow(3, indice + 1))
			return indice;
		
		indice++;
	}
}

bool isFinish() {
	if (cony > 200000) {		//잡지 못함
		//cout << "Cony Run Success\n";
		//cout << "n : " << n << ", brown : " << brown << ", cony : " << cony << endl;
		answer = -1;
		return true;
	}
	else if (brown == cony) {		//잡음
		//cout << "Cony Run Fail\n";
		//cout << "n : " << n << ", brown : " << brown << ", cony : " << cony << endl;
		answer = n;
		return true;
	}
	else {
		return false;
	}
}

void moveBC() {							//BFS
	while (!que_brown.empty()) {
		int move_brown = 0;
		brown = que_brown.front();
		que_brown.pop();
		
		if (n != findN(num_count)) {
			cony += move_cony++;		//Cony 이동
			n = findN(num_count);
		}	
		
		while (move_brown < 3) {	//Brown 이동
			num_count++;
			if (move_brown == 0) {			//brown - 1
				brown -= 1;

				//cout << n << "\t" << brown << "\t" << cony << endl;

				if (isFinish()) {
					return;
				}
				else {
					if(brown >= 0)
						que_brown.push(brown);
					brown += 1;
					move_brown++;
				}
			}
			else if (move_brown == 1) {		//brown + 1
				brown += 1;

				//cout << n << "\t" << brown << "\t" << cony << endl;

				if (isFinish()) {
					return;
				}
				else {
					if (brown >= 0)
						que_brown.push(brown);
					brown -= 1;
					move_brown++;
				}
			}
			else if (move_brown == 2) {		//2 * brown
				brown *= 2;

				//cout << n << "\t" << brown << "\t" << cony << endl;

				if (isFinish()) {
					return;
				}
				else {
					if (brown >= 0)
						que_brown.push(brown);
					brown /= 2;
					move_brown++;
				}
			}
		}
	}
}

int main() {
	cin >> cony >> brown;
	 
	if (!isFinish()) {
		que_brown.push(brown);
		moveBC();
	}

	cout << answer << endl;

	return 0;
}