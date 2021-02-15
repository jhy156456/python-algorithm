#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int c, n;
int cache[101][101];
string W, S;
bool findWildCard(int w,int s) {
	int &ret = cache[w][s];
	if (ret != -1)return ret;
	while ((int)W.size() > w && (int)S.size() > s
		&& (W[w] == '?' || W[w] == S[s])) {
		w++; s++;
	}
	if (w == W.size())return s == S.size();
	if (W[w] == '*') {
		//다음 W와 일치하는 문자가 나올떄까지 맞춰본다
		for (int skip = 0; s+skip <= (int)S.size(); skip++) {
			if (findWildCard(w+1,s+skip)) {
				return ret=1;
			}
		}
	}
	return ret = 0;
}
int main(){
	cin >> c;
	vector<string> results;
	while (c--) {
		cin >> W;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> S;
			//일치하는 string이라면
			if (findWildCard(0,0)) {
				results.push_back(S);
			}
		}
		sort(results.begin(), results.end());
		for (int i = 0; i < (int)results.size(); i++) {
			cout << results[i] << endl;
		}
		results.clear();
	}
	
}