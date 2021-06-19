#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int c,n;
vi russia;
vi korean;
int main(){

	cin >> c;
	while (c != 0) {
		cin >> n;
		russia.clear();
		korean.clear();
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			russia.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			korean.push_back(a);
		}
		sort(russia.begin(), russia.end());
		sort(korean.begin(), korean.end());

		int count = 0;
		int koreanIndex = n - 1;
		for (int i = n - 1; i > -1; i--) {
			if (russia[i] <= korean[koreanIndex]) {
				count++;
				koreanIndex--;
			}

		}
		cout << count << endl;
		c--;
	}
}



