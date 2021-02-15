#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int c, n;
bool findWildCard(const string &w, const string &s) {
	int pos = 0;
	cout << "--------------" << endl;
		cout << "w : " << w << endl;
	cout << "s : " << s << endl;

	while ((int)w.size() > pos && (int)s.size() > pos
		&&( w[pos] == '?' || w[pos] == s[pos]))
		pos++;
	if (pos == w.size())return pos == s.size();
	if (w[pos] == '*') {
		//다음 w와 일치하는 문자가 나올떄까지 맞춰본다
		for (int skip = 0; pos+skip <= (int)s.size(); skip++) {
			if (findWildCard(w.substr(pos+1),s.substr(pos+skip))) {
				return true;
			}
		}
	}
	return false;
}
int main(){
	cin >> c;
	vector<string> results;
	while (c--) {
		string w;
		cin >> w;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			//일치하는 string이라면
			if (findWildCard(w, s)) {
				results.push_back(s);
			}
		}
		sort(results.begin(), results.end());
		for (int i = 0; i < (int)results.size(); i++) {
			cout << results[i] << endl;
		}
		results.clear();
	}
	
}