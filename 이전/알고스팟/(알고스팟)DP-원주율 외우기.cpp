#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<map>
const int INF = 987654321;
using namespace std;
int c, n;
string problem;
int stringSize;
int cache[10002];
int classify(const string &s) {
	//s.size() = 3,4,5
	if (s == string(s.size(), s[0]))return 1;
	bool progressive = true;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i + 1] - s[i] != s[1] - s[0]) progressive = false;
	}
	if (progressive && abs(s[1] - s[0]) == 1) return 2;
	bool alternating = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[i % 2]) alternating = false;
	}
	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}
int getClassify(int here) {
	//here~i
	//기저사례??
	if (here >= problem.size()) return 0;
	int &ret = cache[here];
	//메모이제이션
	if (ret != -1) return ret;
	int a[3] = { 0,0,0 };
	int index = 0;
	for (int i = 3; i < 6; i++) {
		string subString = problem.substr(here, i);
		//기저사례
		if (here + i > problem.size()) {
			a[index] = INF;
		}
		else {//키를 찾지못했다면
 			a[index] = getClassify(here + i) + classify(subString);
		}
		index++;
	}
	return ret = min(a[0], min(a[1], a[2]));
}
int main(){
	cin >> c;
	while (c--) {
		memset(cache, -1, sizeof(cache));
		cin >> problem;
		stringSize = problem.size();
		cout << getClassify(0) << endl;
	}

}