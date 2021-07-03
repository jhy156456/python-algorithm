#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
typedef int i;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> si;
typedef vector<vi> vvi;
typedef pair<string, string> ss;
typedef vector<ii> vii;
int n;
vi vectorA;
vi vectorB;
vii problems;
priority_queue <int> pq;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vectorA.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		
		vectorB.push_back(a);
	}
	problems = vii(n);
	vii vectorMinus;
	for (int i = 0; i < n; i++) {
		problems[i] = { vectorB[i] ,vectorA[i]};
	}
	sort(problems.begin(), problems.end());
	ull result = problems[0].second;
	for (int i = 1; i < n-1; i+=2) {
		pq.push(problems[i].second);
		pq.push(problems[i+1].second);

		result += pq.top();
		pq.pop();
	}


	cout << result << endl;
}