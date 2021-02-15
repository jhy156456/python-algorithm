#include <iostream>
using namespace std;

int bin(int n, int k) {
	if (k == 0 || n == k) return 1;
	else return bin(n - 1, k - 1) + bin(n - 1, k);
}
int main() {
	int first = 0;
	int second = 0;
	cin >> first;
	cin >> second;
	cout << bin(first, second) % 10007 << endl;
}