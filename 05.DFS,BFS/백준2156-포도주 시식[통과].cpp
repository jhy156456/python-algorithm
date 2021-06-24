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
int n;
vi problems;
long cache[10001][4];
//붙어있는 2잔까지 마실 수 있다.
long dp(int index, int selectedCount) {
	//if ((index == 1 && selectedCount == 1) ||
	//	(index == 2 && selectedCount == 2) ||
	//	(index == 3 && selectedCount == 0) ||
	//	(index == 4 && selectedCount == 1) ||
	//	(index == 5 && selectedCount == 0)||
	//	(index == 6 && selectedCount == 1)) {
	//	cout << "index : " << index << endl;
	//	cout << "selectedCount : " << selectedCount << endl;


	//}
	if (index == n) {
		return 0;
	}
	long& ret = cache[index][selectedCount];
	if (ret != -1) {
		return ret;
	}
	if (selectedCount == 2) {
		return dp(index + 1, 0);
	}
	long selectIndex = problems[index] + dp(index + 1, selectedCount + 1);
	long unSelectedIndex = dp(index + 1, 0);

	return ret = max(selectIndex, unSelectedIndex);

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		problems.push_back(a);
	}
	memset(cache, -1, sizeof(cache));
	cout << dp(0, 0) << endl;
}