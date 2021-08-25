#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#include<sstream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> si;
typedef vector<vi> vvi;
typedef vector<vector<int>> vvi;
int arraySize = 16;
string to_binary(int num) {
	string s = "";
	while (num > 0) {
		if (num % 2 == 1) s = "1" + s;
		else s = "0" + s;
		num = num >> 1;
	}

	for (int i = s.size(); i < arraySize; i++) {
		s = "0" + s;
	}
	return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	arraySize = n;
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		string s = to_binary(arr1[i] | arr2[i]);
		string row;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '0') {
				row += " ";
			}
			else {
				row += "#";
			}
		}
		answer.push_back(row);
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << endl;
	}
	return answer;
}
int main() {

	solution(5, { 9, 20, 28, 18, 11
		}, { 30, 1, 21, 17, 28
		});

}