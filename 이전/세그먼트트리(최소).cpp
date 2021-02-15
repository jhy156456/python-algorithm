#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
struct RMQ {
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& array) {
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	int init(const vector<int>& array, int left, int right, int node) {
		if (left == right) return rangeMin[node] = array[left];

		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	//node�� ǥ���ϴ� ���� array[nodeLeft~nodeRight]�� �־��� ��
	//�� ������ array[left~right]�� �������� �ּ�ġ�� ���Ѵ�.
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		//�� ������ ��ġ�� ������ ���� ū ���� ��ȯ�Ѵ� : ���õ�
		if (right < nodeLeft || nodeRight < left) return INT_MAX;
		//node�� ǥ���ϴ� ������ array[left~right]�� ������ ���ԵǴ°��
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
};
int main() {
	vector<int> segmentTree;
	for (int i = 0; i <= 10; i++) {
		segmentTree.push_back(i);
	}
	RMQ rmq(segmentTree);

	cout << segmentTree[rmq.query(7, 10)] << endl;

}