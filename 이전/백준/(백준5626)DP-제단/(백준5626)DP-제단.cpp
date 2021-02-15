#include<iostream>
#include<deque>
#include<vector>
#include<queue>
using namespace std;
int n;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

vi nonMinus;
vi results;
vi temp;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int maxHeight;
	cin >> n;
	maxHeight = ((int)n / 2) + 1;
	nonMinus = vi(n);results = vi(maxHeight+1);temp = vi(maxHeight + 1);
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> nonMinus[i];
		if (max < nonMinus[i])max = nonMinus[i];
	}
	if (max > maxHeight || n == 2) {
		cout << 0 << endl;
		return 0;
	}
	results[0] = 1;
	/*
	예제 기준 남아있는 제단의 높이가 1일수도,2일수도있다
	*/

	for (int i = 1; i < n; i++) { //i=1 이 두번째열
		for (int j = 0; j <= maxHeight; j++) {
			if (nonMinus[i] != -1 && j==nonMinus[i]) { //제단의 높이가 정해져있는경우
				if (j == 0) { //그 열을 먼저 앞단에서 가져온후
					temp[j] = results[j] + results[j + 1];
				}
				else if (j == maxHeight) {
					temp[j] = results[j - 1] + results[j];
				}
				else {
					temp[j] = results[j - 1] + results[j] + results[j + 1];
				}
				for (int l = 0; l < j; l++) { //가져오지 않은부분을 0으로 만든다
					temp[l] = 0;
				}
				for (int l = j + 1; l <= maxHeight; l++) {//가져오지 않은부분을 0으로 만든다
					temp[l] = 0;
				}
				break;
			}
			else { //제단의 높이가 정해져있지 않은경우
				if (j == 0) {
					temp[j] = results[j] + results[j + 1];
				}
				else if (j == maxHeight) {
					temp[j] = results[j - 1] + results[j];
				}
				else {
					temp[j] = results[j - 1] + results[j] + results[j + 1];
				}
			}
		}
		for (int k = 0; k <= maxHeight; k++) { //temp배열에 넣었던걸 다시 results배열에 복사한다
			results[k] = temp[k];
		}
	}

	cout << results[0]% 1000000007 << endl;
	return 0;
}