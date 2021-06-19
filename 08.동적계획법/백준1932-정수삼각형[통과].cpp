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
int n;
vvi problems;
vvi dp;
void printVector(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
int go(int y, int x) {

	if (y == n-1) return problems[y][x];
	int & ret = dp[y][x];
	if (ret != 0) {
		return ret;
	}

	return ret = problems[y][x] + max(go(y + 1, x), go(y + 1, x + 1));
}
int main() {
	cin >> n;
	problems = vvi(n, vi(n, 0));
	dp = vvi(n, vi(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			int a;
			cin >> a;
			problems[i][j] = a;
		}
	}
	cout<<go(0, 0)<<endl;
}