#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include<cstring>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int problem[21][21];
//dice[1][1] = ¹Ù´Ú
int dice[4][3];
int n, m, x, y, k;
int main() {
	cin >> n >> m >> y >> x>>k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> problem[i][j];
		}
	}

	for (int i = 0; i < k; i++) {

		int a; 
		cin >> a;
		int thereY = 0;
		int thereX = 0;

		//µ¿
		if (a == 1) {
			thereY = y;
			thereX = x + 1;
			if (thereY >= 0 && thereY < n && thereX >= 0 && thereX < m) {
				int temp = dice[1][0];
				dice[1][0] = dice[1][1];
				dice[1][1] = dice[1][2];
				dice[1][2] = dice[3][1];
				dice[3][1] = temp;

				if (problem[thereY][thereX] == 0) {
					problem[thereY][thereX] = dice[1][1];
				}
				else {
					dice[1][1] = problem[thereY][thereX];
					problem[thereY][thereX] = 0;
				}
				y = thereY;
				x = thereX;
				cout << dice[3][1] << endl;
			}
		}
		//¼­
		else if (a == 2) {
			thereY = y;
			thereX = x - 1;
			if (thereY >= 0 && thereY < n && thereX >= 0 && thereX < m) {
				int temp = dice[3][1];
				dice[3][1] = dice[1][2];
				dice[1][2] = dice[1][1];
				dice[1][1] = dice[1][0];
				dice[1][0] = temp;
				if (problem[thereY][thereX] == 0) {
					problem[thereY][thereX] = dice[1][1];
				}
				else {
					dice[1][1] = problem[thereY][thereX];
					problem[thereY][thereX] = 0;
				}
				y = thereY;
				x = thereX;
				cout << dice[3][1] << endl;
			}
			
		}
		//ºÏ
		else if (a == 3) {
			thereY = y-1;
			thereX = x;
			if (thereY >= 0 && thereY < n && thereX >= 0 && thereX < m) {
				int temp = dice[3][1];
				dice[3][1] = dice[2][1];
				dice[2][1] = dice[1][1];
				dice[1][1] = dice[0][1];
				dice[0][1] = temp;
				if (problem[thereY][thereX] == 0) {
					problem[thereY][thereX] = dice[1][1];
				}
				else {
					dice[1][1] = problem[thereY][thereX];
					problem[thereY][thereX] = 0;
				}
				y = thereY;
				x = thereX;
				cout << dice[3][1] << endl;
			}
		}
		//³²
		else {
			thereY = y+1;
			thereX = x;
			if (thereY >= 0 && thereY < n && thereX >= 0 && thereX < m) {
				int temp = dice[0][1];
				dice[0][1] = dice[1][1];
				dice[1][1] = dice[2][1];
				dice[2][1] = dice[3][1];
				dice[3][1] = temp;
				if (problem[thereY][thereX] == 0) {
					problem[thereY][thereX] = dice[1][1];
				}
				else{
					dice[1][1] = problem[thereY][thereX];
					problem[thereY][thereX] = 0;
				}
				y = thereY;
				x = thereX;
				cout << dice[3][1] << endl;
			}
		}
	}
}