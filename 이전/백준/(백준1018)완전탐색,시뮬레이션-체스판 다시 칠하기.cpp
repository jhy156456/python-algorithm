#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int n, m;
vector<vector<int>> problem(51, vector<int>(51));
vector<vector<int>> basic2(8, vector<int>(8));
vector<vector<int>> temp(8, vector<int>(8));
vector<vector<int>> basic1(8, vector<int>(8));
int getCount(int row, int col) {
	for (int i = row; i < row+8; i++) {
		for (int j = col; j < col+8; j++) {
			temp[i-row][j-col] = problem[i][j];
		}
	}
	int basic1Go = 0, basic2Go = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (temp[i][j] != basic1[i][j]) {
				basic1Go++;
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (temp[i][j] != basic2[i][j]) {
				basic2Go++;
			}
		}
	}
	return min(basic1Go, basic2Go);
}

int main(){
	cin >> n >> m;
	char a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			if (a == 'B') {
				problem[i][j] = 0;
			}
			else {
				problem[i][j] = 1;
			}
		}
	}
	int colFirst = 1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			basic1[i][j] = colFirst%2;
			colFirst++;
			
		}
		colFirst++;
	}
	colFirst = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			basic2[i][j] = colFirst % 2;
			colFirst++;

		}
		colFirst++;
	}
	
	int result = 100000;
	for (int i = 0; i < n-7; i++) {
		for (int j = 0; j < m-7; j++) {
			int myCount = getCount(i,j);
			if (result > myCount) {
				result = myCount;
			}
		}
	}
	cout << result << endl;

}