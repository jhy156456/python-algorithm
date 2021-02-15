#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int> problem(1001);
vector<int> dice(1001);
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> problem[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> dice[i];
	}
	int nowLocation = 1, diceIndex = 1;

	while (nowLocation < n) {
		nowLocation += dice[diceIndex];
		nowLocation += problem[nowLocation];
		diceIndex++;
	}
	cout << diceIndex << endl;
}