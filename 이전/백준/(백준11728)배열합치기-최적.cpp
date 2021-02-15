#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;

int main(){
	
	cin >> n >> m;
	
	vector<int> a(n+m), b(m);
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	int indexA = n - 1;
	int indexB = m - 1;
	int indexMerged = n + m - 1;
	while (indexB >= 0) {
		if (indexA >= 0 && a[indexA] > b[indexB]) {
			a[indexMerged] = a[indexA];
			indexA--;
		}
		else {
			a[indexMerged] = b[indexB];
			indexB--;
		}
		indexMerged--;
	}
	for (int i = 0; i < n + m; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}