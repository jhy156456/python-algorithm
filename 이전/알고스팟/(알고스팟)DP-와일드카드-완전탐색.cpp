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
		//���� w�� ��ġ�ϴ� ���ڰ� ���Ë����� ���纻��
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
			//��ġ�ϴ� string�̶��
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