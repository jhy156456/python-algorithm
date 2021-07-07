#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int t, n;
vi problems;

bool cmp(int& a, int& b) {
	return a > b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		problems.push_back(a);
	}

	sort(problems.begin(), problems.end());

	int count = n;
	int result = problems[0]*n;
	
	for (int i = 1; i < n; i++) {
		count--;
		if (count * problems[i] > result) {
			result = max(result,count * problems[i]);
		}		
	}
	cout << count << endl;
	cout << result << endl;
}