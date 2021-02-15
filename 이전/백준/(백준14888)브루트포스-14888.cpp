#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
vector<int> results;
int n, pplus, mminus, gob, nanu,sumYunSan;
int problems[12];
void calc(int problemsIndex,int result) {
	if (pplus > 0) {
		int tempResult = result;
		result = result + problems[problemsIndex];
		problemsIndex++;
		pplus--;
		calc(problemsIndex, result);
		pplus++;
		problemsIndex--;
		result = tempResult;
	}
	if (mminus > 0) {
		int tempResult = result;
		result = result - problems[problemsIndex];
		problemsIndex++;
		mminus--;
		calc(problemsIndex, result);
		mminus++;
		problemsIndex--;
		result = tempResult;
	}
	if (gob > 0) {
		int tempResult = result;
		result = result * problems[problemsIndex];
		problemsIndex++;
		gob--;
		calc(problemsIndex, result);
		gob++;
		problemsIndex--;
		result = tempResult;
	}
	if (nanu > 0) {
		int tempResult = result;
		result = result / problems[problemsIndex];
		problemsIndex++;
		nanu--;
		calc(problemsIndex, result);
		nanu++;
		problemsIndex--;
		result = tempResult;
	}
	if(sumYunSan + 1 == problemsIndex)results.push_back(result);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> problems[i];
	}
	cin >> pplus >> mminus >> gob >> nanu;
	sumYunSan = pplus + mminus + gob + nanu;
	calc(1,problems[0]);
	sort(results.begin(), results.end());
	cout << results[results.size()-1] << endl;
	cout << results[0] << endl;
}