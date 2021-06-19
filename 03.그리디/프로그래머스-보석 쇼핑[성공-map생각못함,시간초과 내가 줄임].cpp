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
	int gugan = 1000000;
	int min = 0;
	bool isMinChange = true;
	for (int i = 0; i < length; i++) {
		if (myMap.find(gems[i]) == myMap.end()) {
			//못찾았으면 넣는다
			myMap.insert(pair<string, int>(gems[i], i));
		}
		else {
			//찾았으면 값을 바꾼다
			//이때 맨 앞에값이면? 최솟값이 변경된것이므로
			//answer배열을 갱신 할 필요가 있음
			if (myMap[gems[i]] == min) {
				isMinChange = true;
			}
			myMap[gems[i]] = i;
		}
		if (myMap.size() == mySet.size() && isMinChange) {
			//계속 최솟값을 구하니까 시간초과과 난다..
			min = min_element(myMap.begin(), myMap.end(), compare)->second;
			int max = i;
			int tempGugan = max - min;
			if (tempGugan<gugan) {
				gugan = tempGugan;
				answer.clear();
				answer.push_back(min + 1);
				answer.push_back(max + 1);
				
			}
			isMinChange = false;
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

	vi answer = solution({ "AA", "AB", "AC", "AA", "AC" });
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}