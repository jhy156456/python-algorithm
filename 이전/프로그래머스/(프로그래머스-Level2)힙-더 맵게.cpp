#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
int n, p;
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < (int)scoville.size(); i++) {
		pq.push(scoville[i]);
	}
	int mix = 0;

	while (pq.top() < K) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		if (a == 0 || b == 0) {
			return -1;
		}
		mix = a + b * 2;
		pq.push(mix);
		answer++;
		if (pq.size() == 0) {
			return -1;
		}
	}
	return answer;
}

int main() {
	cout << solution({ 1, 2, 3, 9, 10, 12 },11) << endl;
}