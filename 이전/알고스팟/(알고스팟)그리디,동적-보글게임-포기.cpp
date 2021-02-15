#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const int dy[8] = {-1,0,1,1,1,0,-1,-1};
const int dx[8] = {-1,-1,-1,0,1,1,1,0};
int cache[5][5][9];
vvi problems;
int c,n;
vs words;
bool inRange(int y, int x) {
	if (y < 0 || y>5 || x < 0 || x>5) return false; //안에 없다 ->거짓
	else return true; //안에있다 ->참
}
bool hasWord(int y, int x, const string& word,int nextWord) {
	if (!inRange(y, x)) return false; //안에있으면 참이므로 not연산자에 의해 거짓이되고 if문장 실행 x
	
	if (problems[y][x] != word[0]-'A') {
		cache[y][x][nextWord] = problems[y][x];
		return false;
	}
	if (word.size() == 1) {
		return true;
	}
	for (int direction = 0; direction < 8; direction++) {
		/*
		1  8 7
		2 나 6
		3  4 5
		*/
		int nextY = y + dy[direction]; int nextX = x + dx[direction];
		int &ret = cache[y][x][direction];
		if (ret != -1) {
			if (ret == word[1]-'A') {
				if (hasWord(nextY, nextX, word.substr(1), direction)) {
					return true;
				}
			}
			else {
				return false;
			}
		}
		else {
			if (hasWord(nextY, nextX, word.substr(1), direction)) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	cin >> c;
	while (c--) {
		problems.assign(5, vi(5, -1));
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				char p;
				cin >> p;
				problems[i][j] = p - 'A';
			}
		}
		cin >> n;
		words.clear();
		for (int i = 0; i < n; i++) {
			string word; cin >> word;
			int flag = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (hasWord(i, j, word,0)) {
						cout << word << " YES" << endl;
						flag++;
					}
				}
			}
			if (flag == 0) {
				cout << word << " NO" << endl;
			}

		}
		
	}

}