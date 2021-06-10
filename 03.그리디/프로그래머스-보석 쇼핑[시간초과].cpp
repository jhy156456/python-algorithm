#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<string, int> si;
int n;
vector<pair<ll, ll>> problems;
bool compare(si lhs, si rhs) {
	return lhs.second < rhs.second;
}
vector<int> solution(vector<string> gems) {
	int length = gems.size();
	set<string> mySet;
	vector<int> answer;

	//보석의 중복을 제거한다
	for (int i = 0; i < length; i++) {
		mySet.insert(gems[i]);
	}
	map<string, int>  myMap;
	int start, end = 0;
	int gugan = 1000000;
	for (int i = 0; i < length; i++) {

		if (myMap.find(gems[i]) == myMap.end()) {
			//못찾았으면 넣는다
			myMap.insert(pair<string, int>(gems[i], i));
		}
		else {
			//찾았으면 새로운 인덱스로 갱신한다
			myMap[gems[i]] = i;
		}

		if (myMap.size() == mySet.size()) {
			int min = (min_element(myMap.begin(), myMap.end(), compare)->second) + 1;
			int max = (max_element(myMap.begin(), myMap.end(), compare)->second) + 1;
			int tempGugan = max - min;
			if (tempGugan < gugan) {
				gugan = tempGugan;
				answer.clear();
				answer.push_back(min);
				answer.push_back(max);
			}
		}
	}
	
	/*set<string>::iterator it = mySet.begin();
	int i = 0;
	while (it != mySet.end()) {
		cout << *it << endl;
		it = next(mySet.begin(), ++i);
	}*/

	return answer;
}
int main() {

	vi answer = solution({ "AA","AB","AC","AA","AC" });
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}