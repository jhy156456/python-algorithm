#include<iostream>
#include<vector>
#include<string>
using namespace std;
//�������
//���� : http://gorakgarak.tistory.com/523
 void combination(int arr[], int index, int n, int r, int target) {
	if (r == 0) {
		int size = _msize(arr) / sizeof(*arr);
		// ��ǥ ���� (x,y) ���
		for (int i = 0; i < index; i++)
			cout << arr[i] << endl;
		
	}
	else if (target == n) {
		return;
	}
	else {
		arr[index] = target;
		combination(arr, index + 1, n, r - 1, target + 1);
		combination(arr, index, n, r, target + 1);
	}
}
int main() {
	int *arr = new int[4];
	cout << _msize(arr) / sizeof(*arr) << endl;
	combination(arr, 0, 4, 2, 1);
}