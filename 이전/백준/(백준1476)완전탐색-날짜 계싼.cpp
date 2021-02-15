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
int e, s, m;

int main() {
	cin >> e >> s >> m;
	int eStart = 1, sStart = 1, mStart = 1,count=1;

	while (eStart != e || sStart != s || mStart != m) {
		eStart++; sStart++; mStart++;
		if (eStart == 16) eStart = 1;
		if (sStart == 29) sStart = 1;
		if (mStart == 20) mStart = 1;
		count++;
	}
	cout << count << endl;
}