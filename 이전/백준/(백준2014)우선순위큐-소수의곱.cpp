#include<iostream>
#include<vector>
#include <functional>
#include <algorithm>
#include<queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K;
	int N;
	cin >> K;
	cin >> N;
	int *primeNumber = new int[K];
	priority_queue< long long, vector<long long>, greater<long long> > q;
	// 소수 리스트, 소수와 비교하여 곱한 값 넣는 큐, 최종 리스트
	// 큐의 맨 앞 요소를 빼서 각 소수를 곱하면서 큐에 다시 넣을 것이다.

	for (int i = 0; i < K; i++) {
		cin >> primeNumber[i];
		q.push(primeNumber[i]);
	}
	long long maxValue = 0;
	long long head = 0;
	for (int i = 0; i < N; i++) {
		// n번째 뺀 값이 n번째 수가 된다.
		head = q.top();
		q.pop();
		// 큐를 활용하여 삽입마다 오름차순으로 정렬됨으로써 원하는 값들을 리스트에 저장 가능.
		for (int j = 0; j < K; j++) {
			long long value = head * primeNumber[j];
			int size = q.size();
			if (size > N && value > maxValue) continue;
			maxValue = max(value, maxValue);
			q.push(value);
			if (head % primeNumber[j] == 0) {
				break;
			}
		}
	}
	cout << q.top() << endl;
}