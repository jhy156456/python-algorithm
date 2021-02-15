#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;

int main(){
	
	cin >> n >> m;
	vector<int> a(n+m), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int bStart = 0;
	for (int i = n; i < n + m; i++) {
		a[i] = b[bStart++];
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < n+m; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

}