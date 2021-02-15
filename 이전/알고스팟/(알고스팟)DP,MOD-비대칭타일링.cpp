#include<iostream>
using namespace std;
int n,t;
long long a[101];
int main() {
	cin >> t;
	a[0] = 1; a[1] = 1; a[2] = 2; a[3] = 3;
	for (int i = 4; i <= 100; i++) {
		a[i] = (a[i - 1] + a[i - 2]) % 1000000007;
	}
	for (int j = 1; j <= t; j++) {
		cin >> n;
		if (n % 2 == 0) {
			int oneCalc = (a[n] +1000000007 - a[n / 2]) % 1000000007;
			int result =( oneCalc+ 1000000007 - a[n / 2-1]) % 1000000007;
			cout << result << endl;
		}
		else {
			cout << (a[n] + 1000000007 - a[n / 2]) % 1000000007 << endl;
		}
	}
}