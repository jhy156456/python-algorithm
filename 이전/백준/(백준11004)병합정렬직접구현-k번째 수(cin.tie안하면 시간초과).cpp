#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>
using namespace std;
/*
STL은 sort(퀵 정렬), stable_sort(합병 정렬), partial_sort(힙 정렬)
출처: https://codecooking.tistory.com/17 [코드요리]
*/
int n, k;
vector<int> a(5000001);
vector<int> sorted(5000001);
void myMerge(int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		if (a[i] < a[j]) {
			sorted[k] = a[i]; i++;
		}
		else {
			sorted[k] = a[j]; j++;
		}
		k++;
	}
	if (i > mid) {
		for (int t = j; t <= end; t++) {
			sorted[k] = a[t]; k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = a[t]; k++;
		}
	}
	for (int i = start; i <= end; i++) a[i] = sorted[i];
}
void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		myMerge(start, mid, end);

	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n>>k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	merge_sort(1, n);

	cout << a[k] << endl;

}
