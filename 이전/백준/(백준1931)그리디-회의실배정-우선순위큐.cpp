#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vii;
typedef vector<ii> vii;
using namespace std;
int n;
priority_queue<ii,vii,greater<ii>> pq;
int main() {
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		pq.push(ii(b, a));
	}
	int count = 1;
	ii first = pq.top();
	pq.pop();
	while (!pq.empty()) {
		if (first.first > pq.top().second) {
			pq.pop();
		}
		else {
			first = pq.top(); pq.pop();count++;
		}
	}
	cout << count << endl;
}