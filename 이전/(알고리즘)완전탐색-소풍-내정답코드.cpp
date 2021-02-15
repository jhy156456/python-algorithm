#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vii problems;
vii results;
int c,n,m;
int answer = 0;
void pairWith(int problemIndex) {
	ii here = problems[problemIndex];
	results.push_back(here);
	if ((int)results.size() == n / 2) {
		//for (int j = 0; j < (int)results.size(); j++) {
		//	cout << "first : " << results[j].first << "  second : " << results[j].second << endl;
		//}
		//cout << "天天天天天天天天天天天天天天天天天天" << endl;
		answer++;
		return;
	}
	for (int i = problemIndex+1; i < m; i++) {
		int differentCount = 0;
		ii there = problems[i];
		for (int j = 0; j < (int)results.size(); j++) {
			if (results[j].first == there.first
				|| results[j].first == there.second
				|| results[j].second == there.first
				|| results[j].second == there.second) {
				differentCount++;
			}
		}
		if (differentCount == 0) { 
			pairWith(i); 
			results.pop_back();
		}
	}
	
}
int main() {
	cin >> c;
	while (c--) {
		cin >> n >> m;
		problems.clear();
		results.clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			problems.push_back(ii(a, b));
		}
		sort(problems.begin(), problems.end());

		for (int i = 0; i < m; i++) {

			pairWith(i); results.clear();
		}
		cout << answer << endl;
		answer = 0;
	}
}