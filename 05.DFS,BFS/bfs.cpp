#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
int c,n;
vi problems;
vector<vector<int>> adj;
vi order;
void bfs(int start) {

	queue<int> q;
	q.push(start);
	vector<bool> discovered(adj.size(), false);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		order.push_back(here);
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
}
int main(){

	cin >> c;
	while (c != 0) {
		c--;
		cin >> n;
		problems.clear();
		problems = vi(n);
		for (int i = 0; i < n; i++) {
			cin >> problems[i];
		}


	}
}



