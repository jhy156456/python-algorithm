#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>ii;
typedef pair<ii, int>iii;
int t, n, w, h, problem[15][12],temp[15][12];
int result;
vector<int> ballCol;
void down() {
	for (int j = 0; j < w; j++) {
		for (int k = h - 2; k >= 0; k--) {
			if (problem[k][j] >= 1) {
				int findRow = h - 1;
				while (problem[findRow][j] >= 1 && k<findRow)findRow--;
				problem[findRow][j] = problem[k][j];
				if(findRow>k)problem[k][j] = 0;
			}
		}
	}
}
void LetsGoBoom(int row, int col) {
	//1보다 크면 번진당
	if (problem[row][col] >= 1) {
		//행열의 숫자만큼 상하좌우전진
		int boomLength = problem[row][col];
		problem[row][col] = 0;

		//좌
		int leftCol = col;
		for (int i = 0; i < boomLength - 1; i++) {
			leftCol--;
			if (leftCol >= 0) {
				LetsGoBoom(row, leftCol);
			}

		}
		//상
		int upRow = row;
		for (int i = 0; i < boomLength - 1; i++) {
			upRow--;
			if ( upRow>=0) {
				LetsGoBoom(upRow, col);
			}

		}
		//하
		int downRow = row;
		for (int i = 0; i < boomLength - 1; i++) {
			downRow++;
			if (downRow<h) {
				LetsGoBoom(downRow, col);
			}

		}
	
		//우
		int rightCol = col;
		for (int i = 0; i < boomLength-1; i++) {
			rightCol++;
			if (rightCol<w) {
				LetsGoBoom(row, rightCol);
			}
			
		}
	}
}
void r(int depth) {
	if (depth == n) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				problem[i][j] = temp[i][j];
			}
		}

		for (int i = 0; i < (int)ballCol.size(); i++) {
			int row = 0;
			//볼을 내리면서 0이아닐때까지 찾는다
			while (problem[row][ballCol[i]] == 0 && row<h) row++;
			LetsGoBoom(row, ballCol[i]);
			down();
		}
		int oneCount = 0;
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				if (problem[j][k] >= 1) {
					oneCount++;
				}
			}
		}
		if (result > oneCount) result = oneCount;
		return;
	}
	for (int i = 0; i < w; i++) {
		ballCol.push_back(i);
		r(depth+1);
		ballCol.pop_back();
	}
}
int main() {
	cin >> t;

	for (int a = 1; a <= t; a++) {
		result = 999999;
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> temp[i][j];
			}
		}

		//ballCol.resize(4);
		//ballCol[0] = 3;
		//ballCol[1] = 1;
		//ballCol[2] = 1;
		//ballCol[3] = 1;

		//r(4);

		for (int i = 0; i < w; i++) {
			ballCol.push_back(i);
			r(1);
			ballCol.pop_back();
		}
		ballCol.clear();
		cout << "#" << a << " " << result << endl;

	}

}


