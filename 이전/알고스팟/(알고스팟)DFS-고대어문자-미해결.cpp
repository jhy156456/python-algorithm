#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int c, n;
vector<string> problems;
vector<vector<int>> adj(26,vector<int>(26,0));
vector<int> visited;
vector<int>orders(26);
void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < adj.size(); i++) {
		if (!visited[i] && adj[here][i])//there과 인접해있는 정점이 있다면
			dfs(i);
	}
	orders.push_back(here);
}
void maxGraph() {
	string a;
	string b;
	for (int i = 0; i < problems.size()-1; i++) {
		a = problems[i];
		b = problems[i + 1];
		int k = min(a.size(), b.size());
		for (int j = 0; j < k; j++) {
			if (a[j] != b[j]) {
				int row = a[j] - 'a';
				int col = b[j] - 'a';
				adj[row][col] = 1;
				break;
			}
		}
	}
}
int main() {
	
	cin >> c;

	while (c--) {
		cin >> n;
		problems.resize(n);
		visited.resize(26);
		for(int i=0; i<n; i++){
			cin >> problems[i];

		}


		maxGraph();
		problems.clear();
	
		
		for (int i = 0; i < adj.size(); i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		reverse(orders.begin(), orders.end());
		for (int i = 0; i < adj.size(); i++) { 
			char a = orders[i] + 'a';
			cout << a << endl; }
		visited.clear();
	}

}