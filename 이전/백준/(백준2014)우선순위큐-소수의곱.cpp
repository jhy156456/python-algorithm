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
	// �Ҽ� ����Ʈ, �Ҽ��� ���Ͽ� ���� �� �ִ� ť, ���� ����Ʈ
	// ť�� �� �� ��Ҹ� ���� �� �Ҽ��� ���ϸ鼭 ť�� �ٽ� ���� ���̴�.

	for (int i = 0; i < K; i++) {
		cin >> primeNumber[i];
		q.push(primeNumber[i]);
	}
	long long maxValue = 0;
	long long head = 0;
	for (int i = 0; i < N; i++) {
		// n��° �� ���� n��° ���� �ȴ�.
		head = q.top();
		q.pop();
		// ť�� Ȱ���Ͽ� ���Ը��� ������������ ���ĵ����ν� ���ϴ� ������ ����Ʈ�� ���� ����.
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