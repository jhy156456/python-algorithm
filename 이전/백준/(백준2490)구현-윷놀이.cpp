#include<iostream>
using namespace std;

int main() {
	for (int j = 0; j < 3; j++) {
		int a[4] = { 0 };
		int count[2] = { 0 };
		for (int i = 0; i < 4; i++) {
			cin >> a[i];
			if (a[i] == 0) count[0]++; //배(0)의 갯수
			else count[1]++; //등(1)의 갯수
		}
		if (count[0] == 1 && count[1] == 3) cout << "A" << endl;
		else if (count[0] == 2 && count[1] == 2) cout << "B" << endl;
		else if (count[0] == 3 && count[1] == 1)cout << "C" << endl;
		else if (count[0] == 4)cout << "D" << endl;
		else if (count[1] == 4)cout << "E" << endl;
	}
}
