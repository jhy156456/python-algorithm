#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>
using namespace std;
int n;
vector<int> problem(100001);
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> problem[i];
	sort(problem.begin(), problem.begin() + n,greater<int>());
	int forSize = n;
	int result = 0;
	for (int i = 0; i < forSize; i++) {
		n--;
		if (i < forSize - 1) {
			if (problem[i] > n || abs(problem[i] - problem[i + 1]) > 1) {
				result++;
			}
			else {
				result += problem[i];
				break;
			}
		}
		else {
			if (problem[i] >= n) {
				result++;
			}
			else {
				result += problem[i];
				break;
			}
		}
	}
	cout << result << endl;
}
