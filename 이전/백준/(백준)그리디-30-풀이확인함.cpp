#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<char> vs;
using namespace std;
int n;
vi numbers;
int main() {

	string problem;
	cin >> problem;
	int sum = 0;
	int zeroCount = 0;
	for (int i = 0; i < (int)problem.size(); i++) {
		sum += problem[i] - 48;
		if ((problem[i] - 48) == 0) zeroCount++;
		numbers.push_back(problem[i] - 48);
	}

	if (zeroCount == 0 || sum % 3 != 0) {
		cout << -1;
	}
	else {
		sort(numbers.begin(), numbers.end(),greater<int>());
		for (int i = 0; i < (int)numbers.size(); i++)cout << numbers[i];
	}
	cout << endl;
}