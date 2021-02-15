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
int c;

int main() {
	cin >> c;
	int start = 1;
	vvi problems = vvi(c+1, vi(c+1, 0));
	int y = 0, x = 0;
	for (int i = 0; i < c; i++) {
		x = i;
		y = 0;
		problems[y][x] = start++;
		for (int j = 0; j < i; j++) {
			y = y + 1;
			x = x - 1;
			problems[y][x] = start++;
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			cout << problems[i][j] << " ";
		}
		cout << endl;
	}

}