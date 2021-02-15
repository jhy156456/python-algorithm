#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int problem[500][500];
int cache[500][500];
int n;
int dy[] = {-1,1,0,0};//╩С,го,аб,©Л
int dx[] = {0,0,-1,1};
int move(int y, int x,int pandaLive) {
	if (y < 0 || y >= n || x < 0 || x >= n) {
		return -1;
	}
	int &ret = cache[y][x];
	if (ret != -1) return ret;
	int findMax[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		int thereY = y + dy[i];
		int thereX = x + dx[i];

		if (problem[y][x] < problem[thereY][thereX]) {
			findMax[i]= move(thereY, thereX, pandaLive + 1);
		}
		else {
			findMax[i] = 1;
		}

	}
	return ret = max(findMax[0], max(findMax[1], max(findMax[2],findMax[3])))+1;
}
int main(){
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> problem[i][j];
		}
	}
	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int result = move(i, j,1);
			if (maxValue < result)maxValue = result;
		}
	}
	//cout << endl;
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout<< cache[i][j]<<" ";
	//	}
	//	cout << endl;
	//}
	cout << maxValue-1 << endl;
}