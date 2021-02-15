#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,x;
vector<int> problems(100000);
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> problems[i];
	}
	cin >> x;
	sort(problems.begin(), problems.begin()+n);

	int left = 0, right = n - 1, answer = 0,sum=0;

	while (right >= left) {
		sum = problems[left] + problems[right];
		if (sum == x) {
			answer++;
			right--;
			left++;
		}
		else if (sum > x) {
			right--;
		}
		else if (sum < x) {
			left++;
		}
	}
	cout << answer << endl;
}