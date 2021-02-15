#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int cache[100000][3];
int selectCase[3][3] = { {1,2},{0,2},{0,1,2} };
int getCase(int row, int selectedCase) {
	if (row == n - 1) return cache[row][selectedCase] = 1;
	if (selectedCase == 0 || selectedCase==1) {
		int a, b;
		int &retA = cache[row+1][selectCase[selectedCase][0]];
		int &retB = cache[row+1][selectCase[selectedCase][1]];
		if (retA != -1) {
			a = retA;
		}
		else {
			a = getCase(row + 1, selectCase[selectedCase][0]);
		}
		if (retB != -1) {
			b = retB;
		}
		else {
			b = getCase(row + 1, selectCase[selectedCase][1]);
		}
		return cache[row][selectedCase] = (a % 9901 + b % 9901);
	}else if (selectedCase == 2) {
		int a, b, c;
		int &retA = cache[row+1][selectCase[selectedCase][0]];
		int &retB = cache[row+1][selectCase[selectedCase][1]];
		int &retC = cache[row+1][selectCase[selectedCase][2]];
		if (retA != -1) {
			a = retA;
		}
		else {
			a = getCase(row + 1, selectCase[selectedCase][0]);
		}
		if (retB != -1) {
			b = retB;
		}
		else {
			b = getCase(row + 1, selectCase[selectedCase][1]);
		}
		if (retC != -1) {
			c = retC;
		}
		else {
			c = getCase(row + 1, selectCase[selectedCase][2]);
		}
		return cache[row][selectedCase] = (a%9901 + b % 9901 + c % 9901);
	}
}
int main(){
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << (getCase(0, 1)+ getCase(0, 2)+getCase(0, 0))%9901<< endl;
}