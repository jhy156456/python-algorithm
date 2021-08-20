#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
int n;
vi problems;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	priority_queue<int> maxHeap; // 최대힙 = 내림차순
	priority_queue<int, vector<int>, greater<int>> minHeap; //최소힙 = 오름차순
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		problems.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (maxHeap.size() == minHeap.size()) {
			maxHeap.push(problems[i]);
		}
		else {
			minHeap.push(problems[i]);
		}

		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		cout << maxHeap.top() << "\n";

	}
}