#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
int n, c;
vector<int> m;
vector<int> e;
vector<pair<int, int>> problems;
vector<int>results;
int main() {
	cin >> c;

	while (c != 0) {
		cin >> n;
		c--;
		m.clear();
		e.clear();
		problems.clear();
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			m.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			e.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			problems.push_back(ii(e[i], m[i]));
		}
		sort(problems.begin(), problems.end());
		
		int result = 0;
		result = problems[n-1].first + problems[n-1].second;
		int eSum = problems[n-1].second;

		for (int i = n-2; i > -1; i--) {
			eSum += problems[i].first + problems[i].second;
			//여태까지 처먹은게 지금 도시락데우고 먹는 숫자보다 작으면 result를 갱신한다
			result = max(eSum, result);
			eSum -= problems[i].first;
		}

		results.push_back(result);
	}

	for (int i = 0; i < results.size(); i++) {
		cout<<results[i]<<endl;
	}

	
}
 


// 1 2 4 8 9

// gap = 8