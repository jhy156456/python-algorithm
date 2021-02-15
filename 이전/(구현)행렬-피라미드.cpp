#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int c, start;
const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1} },
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1} }
};
vvi problems;
//첫실행 오른쪽
void goright(int step) {
	int left = c - step + 1;
	int right = c + step;
	for (int i = left; i < right; i++) {
		if (start == 10) {
			start = 1;
		}
		problems[step][i] = start++;
	}
}

void goleft(int step) {
	int left = c - step + 1;
	int right = c + step;
	for (int i = right - 1; i >= left; i--) {
		if (start == 10) {
			start = 1;
		}
		problems[step][i] = start++;
	}
}
int main() {
	cin >> c>>start;
	problems = vvi(c+1, vi(c*2+1, 0));
	problems[1][c] = start++;
	for (int i = 2; i <= c; i++) { 
		if((i + 1) % 2 ==1)goright(i);
		else goleft(i);
	}
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= c*2; j++) {
			if(problems[i][j]!=0)cout << problems[i][j] << " ";
			else cout << "  ";
		}
		cout << endl;
	}

}