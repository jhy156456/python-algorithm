#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
int c,n;
vs problems;
vector<vector<int>> adj;
void printVector(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
vi seen, order;
void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); there++) {
		if (adj[here][there] && !seen[there]) {
			dfs(there);
		}
	}
	order.push_back(here);
}

vi topoligicalSort() {
	int n = adj.size();
	seen = vi(n, 0);
	order.clear();
	for (int i = 0; i < n; i++) {
		if (!seen[i]) dfs(i);
	}
	reverse(order.begin(), order.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++){
			if (adj[order[j]][order[i]]) {
				return vi();
			}
		}
	}
	return order;
}

void makeGraph(vector<string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
	printVector(adj);

}
int main(){

	cin >> c;
	while (c != 0) {
		c--;
		cin >> n;
		problems.clear();
		for (int i = 0; i < n; i++) {
			string a;
			cin >> a;
			problems.push_back(a);
		}
		makeGraph(problems);
		vi result = topoligicalSort();
		for (int i = 0; i < result.size(); i++) {
			cout << (char)(result[i] + 'a');
		}
		cout << endl;
	}
}



