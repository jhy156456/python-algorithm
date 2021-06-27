#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> si;
typedef vector<vi> vvi;
typedef pair<string, string> ss;
void printVector(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int r, c, w;
	cin >> r >> c >> w;
	vvi problems = vvi(51,vi(51,1));

	for (int i = 2; i < 51; i++) {
		for (int j = 1; j < i; j++) {
			problems[i][j] = problems[i-1][j-1] + problems[i-1][j];
		}
	}
	int result = 0;
	int col = 1;
	for (int i = r-1; i < (r-1)+w; i++) {
		for (int j = c-1; j < col+(c-1); j++) {
			result += problems[i][j];
			
		}
		col++;
	}
	//printVector(problems);
	cout << result << endl;


}