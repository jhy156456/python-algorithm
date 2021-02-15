#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

int s[11] = { 4,5,6,7,8,9,1,2,3,4,5 };
void partition(int low, int high, int &pivot) {
	int pivotItem = s[low];
	int j = low;
	for (int i = low+1; i <= high; i++) {
		if (pivotItem > s[i]) {
			j++;
			swap(s[i],s[j]);
		}
	}
	pivot = j;
	swap(s[low], s[pivot]);
}
void quickSort(int low, int high) {
	int pivot;
	if (low < high) {
		partition(low,high,pivot);
		quickSort(low, pivot - 1);
		quickSort(pivot+1, high);
	}
}

int main() {

	for (int i = 0; i < 11; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	quickSort(0, 10);
	for (int i = 0; i < 11; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}