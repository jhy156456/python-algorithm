#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int c, n;
int path[100][100];
int cache[100][100];
int path1(int y, int x) {
	if (y == n - 1)return path[y][x];
	int &ret = cache[y][x];
	if (ret != -1) return ret;
	return ret=path[y][x]+max(path1(y + 1, x + 1), path1(y + 1, x));
}
int main(){
	cin >> c;
	while (c--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i+1; j++) {
				cin >> path[i][j];
			}
		}
		cout << path1(0, 0) << endl;;
	}
	
}