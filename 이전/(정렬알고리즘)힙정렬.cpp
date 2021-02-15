#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

int s[11] = {0,6,9,8,4,7,2,5,3,1,5 };
void Adjust(int root, int n) {
	int e = s[root];
	int j = 0;
	for (j = (2 * root); j <= n; j *= 2) {
		if (j < n && s[j] < s[j + 1]) j++;
		if (e >= s[j]) break;
		s[j / 2] = s[j];
	}
	s[j / 2] = e;
}
void heapSort(int n) {
	for (int i = (n / 2); i >= 1; i--) {
		Adjust(i, n);
	}

	for (int i = (n - 1); i >= 1; i--) {
		swap(s[1], s[i + 1]);
		Adjust(1, i);
	}
}
int main() {

	heapSort(10);
	for (int i = 1; i <= 10; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}