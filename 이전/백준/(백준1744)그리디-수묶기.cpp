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
vi positive, negative;
int main() {
	cin >> n;
	int zeroCount = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a > 0) {
			positive.push_back(a);
		}
		else if (a < 0) {
			negative.push_back(a);
		}
		else if (a == 0) {
			zeroCount++;
		}
	}
	sort(positive.begin(), positive.end(), greater<int>());
	sort(negative.begin(), negative.end());
	int maxAnswer = 0;
	int positiveSize = (int)positive.size();
	if ((int)positive.size() % 2 != 0) positive.push_back(1);

	for (int i = 0; i < (int)positive.size(); i += 2) {
		if (positive[i + 1] == 1) { //다음숫자가 1일때 삽입한 수를 보고있는지? 확인해야한다
			if (i + 1 == positiveSize) {
				maxAnswer += positive[i] * positive[i + 1];
			}
			else {
				maxAnswer += positive[i] + positive[i + 1];
			}

		}
		else {
			maxAnswer += positive[i] * positive[i + 1];
		}

	}

	if ((int)negative.size() % 2 != 0)negative.push_back(1);
	for (int i = 0; i < (int)negative.size(); i += 2) {
		if (negative[i] == -1) {
			if (zeroCount != 0 && negative[i + 1] != -1) {
				continue;
			}
			else {
				maxAnswer += negative[i] * negative[i + 1];
			}
		}
		else {
			maxAnswer += negative[i] * negative[i + 1];
		}

	}
	cout << maxAnswer << endl;
}