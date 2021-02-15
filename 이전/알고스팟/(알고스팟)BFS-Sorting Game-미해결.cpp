#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;
map<vector<int>, int> toSort;
int n;
void precalc(int n) {
	vector<int> perm(n);
	for (int i = 0; i < n; i++)perm[i] = i;
	queue<vector<int>>q;
	q.push(perm);
	toSort[perm] = 0;
	while (!q.empty()) {
		//cout << "와일안"<<endl;
		vector<int> here = q.front();
		q.pop();
		cout << "q사이즈 : " << q.size() << endl;
		int cost = toSort[here];
		for (int i = 0; i < n; i++) {
			for (int j = i + 2; j <= n; j++) {
				reverse(here.begin() + i, here.begin() + j);
				//for (int i = 0; i < here.size(); i++) cout << here[i] << " ";
				if (toSort.count(here) == 0) {
					//cout << "if안" << endl;
					toSort[here] = cost + 1;
					q.push(here);
				}
				//cout << "포포안" << endl;
				reverse(here.begin() + i, here.begin() + j);
			}
			//cout << "포안" << endl;
		}
	}
}
int solve(const vector<int> & perm) {
	int n = perm.size();
	vector<int> fixed(n);
	
	for (int i = 0; i < n; i++) {
		int smallcount = 0;
		for (int j = 0; j < n; j++) {
			if (perm[i] < perm[j])
				smallcount++;
		}
		fixed[i] = smallcount;
	}
	return toSort[fixed];
}
int main(){
	
	int count = 0;
	cin >> count;
	while (count--) {
		vector<int> problems(8);
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> problems[i];
		}
		
		precalc(n);
		//cout << "?<";
		cout << solve(problems) << endl;

		
	}

}