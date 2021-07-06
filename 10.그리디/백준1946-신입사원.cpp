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
vii problems;
vi results;
bool cmp2(ii& a, ii& b) {
	//두번째 원소를 기준으로 내림차순 정렬
	return a.second < b.second;
}
bool cmp(ii& a, ii& b) {
	//첫번째 원소를 기준으로 내림차순 정렬
	return a.first < b.first;
}

int main() {
	cin >> t;

	while (t != 0) {
		cin >> n;
		problems.clear();
		t--;

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			problems.push_back(ii(a, b));
		}

		int resultCount = 0;
		int tempCount = 1;

		resultCount = max(resultCount, tempCount);
		sort(problems.begin(), problems.end(),cmp);
		int pivot = problems[0].second;
		for (int i = 1; i < n; i++) {
			if (pivot > problems[i].second) {
				pivot = problems[i].second;
				tempCount++;
			}
		}
		resultCount = tempCount;

		sort(problems.begin(), problems.end(), cmp2);
		tempCount = 1;
		int pivot = problems[0].first;
		for (int i = 1; i < n; i++) {
			if (pivot > problems[i].first) {
				pivot = problems[i].first;
				tempCount++;
			}
		}

		resultCount = max(resultCount, tempCount);
		results.push_back(resultCount);
	}
	
	for (int i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}


}