#include <iostream>
#include <vector>
#include<deque>
#include <algorithm>
#include<stack>
using namespace std;
typedef pair<char, int> ci;
deque<ci> problems, compare;
stack<ci> wait;
int n;
bool cmp(ci& a, ci& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main() {
	cin >> n;
	for (int i = 0; i < n * 5; i++) {
		char a, b;
		int hi;
		cin >> a >> b >> hi;
		problems.push_back({ a,hi });
		compare.push_back({ a,hi });
	}
	sort(problems.begin(), problems.end(),cmp);

	for (int i = 0; i < (int)compare.size(); i++) {
		if (problems[i] == compare[i]) {
			problems.pop_front();
			compare.pop_front();
			i--;
		}
		else {
			if (wait.size() != 0) {
				if (wait.top() == problems[i]) {
					wait.pop();
					problems.pop_front();
					i--;
					continue;
				}
			}
				wait.push(compare[i]);
				compare.pop_front();
				i--;
			
		}
	}
	int index = 0;
	while (!wait.empty()) {
		if (wait.top() == problems[index]) {
			wait.pop(); index++;
		}
		else {
			break;
		}
	}
	if (wait.size() == 0) {
		cout << "GOOD" << endl;
	}
	else {
		cout << "BAD" << endl;
	}

}