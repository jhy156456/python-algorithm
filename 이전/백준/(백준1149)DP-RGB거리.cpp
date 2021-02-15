#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int, int> ii;
int problem[1000][1000];
int cache[1000][1000];
int n;
int otherColor[3][2]={ {1,2},{0,2},{0,1}};
int getMinValue(int choosedColor,int houseNumber) {
	if (houseNumber == n - 1) {
		return problem[houseNumber][choosedColor];
	}
	int &ret = cache[houseNumber][choosedColor];
	if (ret != -1) return ret;
	return ret = min(getMinValue(otherColor[choosedColor][0], houseNumber + 1)
		+problem[houseNumber][choosedColor]
		, getMinValue(otherColor[choosedColor][1], houseNumber + 1)
		+problem[houseNumber][choosedColor]);
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> problem[i][j];
		}
	}
	cout << min(getMinValue(0,0), min(getMinValue(1,0), getMinValue(2,0))) << endl;
}