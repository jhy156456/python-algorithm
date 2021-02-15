#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vii;
typedef vector<int> vi;

using namespace std;
int c,n;
vi russia;
vi korea;
int main() {
	cin >> c;
	while (c--) {
		cin >> n;
		russia.assign(n, 0);
		korea.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> russia[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> korea[i];
		}
		sort(russia.begin(), russia.end());
		sort(korea.begin(), korea.end());
		int winCount = 0;
		for (int i = russia.size()-1; i >=0; i--) {
			//러시아선수 처음부터 비교해본다
			//크거나 같은애들중 가장 작은애를 가져온다
			//크거나 같은애들이 없다면 한국애들중 가장 작은수를 가져온다
			//결론은 정렬해놓고 하는게 좋을듯
			int bigOrSame = 0;
			int j = 0;
			for (j = 0; j < (int)korea.size(); j++) {
				if (russia[i] <= korea[j]) {
					bigOrSame = korea[j];
					break;
				}
			}
			if (bigOrSame != 0) {
				winCount++;
				korea.erase(korea.begin() + j);
			}

		}
		cout << winCount << endl;
	}
}