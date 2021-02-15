#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> adj(1000,vector<int>(1000,0));
void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < adj.size(); there++) {
		while (adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}
int main(){

	int n;
	cin >> n;
	int edges = 0;
	vector<int> circuit;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a != 0) {
				adj[i][j] += a;
				edges += a;
			}

		}
	}
	int check = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += adj[i][j];
		}
		if (sum % 2 != 0) {
			check = 1;
			break;
		}
	}
	if (check == 1) {
		cout << -1 << endl;
	}
	else {
		getEulerCircuit(0, circuit);
		if (edges / 2 + 1 != circuit.size()) {
			cout << -1 << endl;
			return 0;
		}
		
		reverse(circuit.begin(), circuit.end());
		for (int i = 0; i < circuit.size(); i++)cout << circuit[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}