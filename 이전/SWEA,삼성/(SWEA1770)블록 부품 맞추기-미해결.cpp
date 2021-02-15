#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
#include<math.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define MAX 30000
int (*reverseClockRotation(int block[4][4]))[4] {
	int rotate[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rotate[j][i] = block[i][3-j];
		}
	}
	return rotate;
}
extern int makeBlock(int module[][4][4]) {

	for (int i = 0; i < MAX; i++) {
		int max = 0;

		for (int j = 0; j < MAX; j++) {
			if (i == j) continue;
			int reverse[4][4];
			//j모듈을 뒤집는다.
			for (int k = 0; k < 4; k++) {
				for (int l = 3; l >= 0; l--) {
					reverse[k][3 - l] = module[j][k][l];
				}
			}



		}
	}
}
int main() {
	static int module[MAX][4][4];

	srand(3); // 3 will be changed

	for (int tc = 1; tc <= 10; tc++)
	{
		for (int c = 0; c < MAX; c++)
		{
			int base = 1 + (rand() % 6);
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					module[c][y][x] = base + (rand() % 3);
				}
			}
		}
		cout << "#" << tc << " " << makeBlock(module) << endl;
	}

	return 0;
}