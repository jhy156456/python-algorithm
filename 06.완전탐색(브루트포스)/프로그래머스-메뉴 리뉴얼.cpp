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
int n;
vvi problems;
vvi dp;
void printVector(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	int ordersSize = orders.size();


	for (int i = 0; i < course.size(); i++) {
		int courseSize = course[i];
		map<string, int> myMap;
		int maxCount = 0;
		for (int j = 0; j < ordersSize; j++) {
			string order = orders[j];
			sort(order.begin(), order.end());
			if (order.size() < courseSize) continue;
			vector<int> permu;
			vector<int> per;
			for (int k = 0; k < order.size(); k++) {
				permu.push_back(k);
				per.push_back(1);
			}
			for (int k = 0; k < courseSize; k++) {
				per[k] = 0;
			}

			do {
				string combination = "";
				for (int k = 0; k < permu.size(); k++) {
					if (per.at(k) == 0) {
						combination += order[permu[k]];
					}
				}
				map<string, int>::iterator iter = myMap.find(combination);
				if (iter == myMap.end()) {
					myMap.insert(si(combination, 1));
				}
				else {
					iter->second += 1;
					maxCount = max(iter->second, maxCount);
				}
			} while (next_permutation(per.begin(), per.end()));
		}

		map<string, int>::iterator iter;

		for (iter = myMap.begin(); iter != myMap.end(); iter++)
		{
			if (iter->second == maxCount) {
				answer.push_back(iter->first);
			}
		}
	}

	sort(answer.begin(), answer.end());
	//
	//for (int i = 0; i < answer.size(); i++) {
	//	cout << answer[i] << endl;
	//}
	return answer;
}
int main() {
	vs answer = solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
}