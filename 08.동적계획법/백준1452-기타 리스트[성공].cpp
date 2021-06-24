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
int n, s, m;
vi volume;
vvi cache;
vi answer;
int C[101][101];
int dp(int index, int sum) {
	if (index == n+1) {
		answer.push_back(sum);
		return 1;
	}
	int& ret = cache[index][sum];
	if (ret == 0) {
		return 0;
	}
	ret = 0;
	int plusSum = sum + volume[index];
	int minusSum = sum - volume[index];

	if (plusSum <= m && plusSum >= 0) {
		ret = dp(index + 1, plusSum);
	}
	if (minusSum <= m && minusSum >= 0) {
		ret = dp(index + 1, minusSum);
	}
	return ret;

}

int main() {
	cin >> n >> s >> m;
	cache = vvi(101, vi(1001, -1));
	volume = vi(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		volume[i+1] = a;
	}
	cache[0][s] = 1;
	dp(1, s);
	if (answer.size() == 0) {
		cout << -1 << endl;
	}
	else {
		cout << *max_element(answer.begin(), answer.end()) << endl;
	}
}