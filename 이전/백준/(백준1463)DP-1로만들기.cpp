#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,dp[10000001];

int minMake(int n) {
	int &ret = dp[n];
	if (ret != -1)return ret;
	if (n == 0) {

	}
	else if (n == 1) {
		return ret = 0;
	}
	else if (n == 2) {
		return ret = 1;
	}
	else if (n == 3) {
		return ret = 1;
	}
	if (n % 3 == 0 && n % 2 == 0) {
		return ret = 1 + min(min(minMake(n - 1), minMake(n / 2)), minMake(n / 3));
	}
	else if (n % 3 == 0) {
		return ret = 1 + min(minMake(n - 1), minMake(n / 3));
	}
	else if (n % 2 == 0) {
		return ret = 1+ min(minMake(n - 1), minMake(n / 2));
	}
	else {
		return ret = 1 + minMake(n - 1);
	}
}
int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << minMake(n) << endl;
}