#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> si;
typedef vector<vi> vvi;

int n,m;
vector<string> problems;
vvi dp;
void printVector(vector<vector<char>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
char getChar(vector<vector<char>> charV, int y, int x) {
	if (charV[y][x] == 'B') {
		return 'W';
	}
	else {
		return 'B';
	}
}
int  check(int y, int x) {
	//몇번을 바꿔야 체스판이 되는지 체크한다.
	int count1 = 0;
	int count2 = 0;
	vector<vector<char>> temp(8, vector<char>(8));

	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			temp[i - y][j - x] = problems[i][j];
		}
	}

	//cout << "------------------------" << endl;;
	//printVector(temp);
	
	
	for (int i = 0; i < 8; i++) {
		if (i > 0) {
			//두번째 행,첫번째 열은 바로 윗 행과 같다면 카운트가 증가된다
			if (temp[i - 1][0] == temp[i][0]) {
				count1++;
				temp[i][0] = getChar(temp, i - 1, 0);
			}
		}
		for (int j = 0; j < 8; j++) {
			if (j > 0) {
				//제일 처음 열 에서 바로 윗 열과 같다면 카운트가 증가된다
				if (temp[i][j-1] == temp[i][j]) {
					count1++;
					temp[i][j] = getChar(temp, i, j-1);
				}
			}
		}
	}
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			temp[i - y][j - x] = problems[i][j];
		}
	}

	if (temp[0][0] == 'W') {
		temp[0][0] = 'B';
	}
	else {
		temp[0][0] = 'W';
	}
	count2++;
	for (int i = 0; i < 8; i++) {
		if (i > 0) {
			//두번째 행,첫번째 열은 바로 윗 행과 같다면 카운트가 증가된다
			if (temp[i - 1][0] == temp[i][0]) {
				count2++;
				temp[i][0] = getChar(temp, i - 1, 0);
			}
		}
		for (int j = 0; j < 8; j++) {
			if (j > 0) {
				//제일 처음 열 에서 바로 윗 열과 같다면 카운트가 증가된다
				if (temp[i][j - 1] == temp[i][j]) {
					count2++;
					temp[i][j] = getChar(temp, i, j - 1);
				}
			}
		}
	}



	//printVector(temp);
	//cout << count << endl;
	//cout << "------------------------" << endl;;
	return min(count1,count2);

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		problems.push_back(a);
	}
	int result = 1000000;
	for (int i = 0; i <= n-8 ; i++) {
		for (int j = 0; j <= m-8 ; j++) {
			result = min(result,check(i, j));
		}
	}
	cout << result << endl;
}