#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<vector<int>> adj(26,vector<int>(26,0));
int C;
vector<string> problems;
vector<int> indegree(26);
vector<int> outdegree(26);
void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < adj.size(); there++) {
		while (adj[here][there] > 0) {
			adj[here][there]--;
			//adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}
vector<int> getEulerTrailOrCircuit() {
	vector<int> circuit;
	for (int i = 0; i < 26; i++) {
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}

	}
	return circuit;
}
bool checkEuler() {
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || 1 < delta) return false;
		if (delta == 1)plus1++;
		if (delta == -1) minus1++;

	}
	return(plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}
int main(){
	cin >> C;
	vector<int> circuit;
	while (C--) {
		int n;
		cin >> n;
		
		problems.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> problems[i];
		}
		int count = n;
		int i = 0;
		while (count--) {
			//cout << problems[i] << endl;
			int start = problems[i].at(0)-'a';
			//cout << "start : " << start<<endl;
			int end = problems[i].at(problems[i].size() - 1)-'a';
			//cout << "end : " << end << endl;
			adj[start][end]++;
			outdegree[start]++;
			indegree[end]++;
			i++;
		}
		if (!checkEuler()) cout << "IMPOSSIBLE" << endl;
		else {
			circuit = getEulerTrailOrCircuit();
			if (circuit.size() != n + 1) {
				cout << "IMPOSSIBLE" << endl;
				break;
			}
			/*for (int i = 0; i < circuit.size(); i++)cout << circuit[i] << " ";
			cout << endl;*/
			reverse(circuit.begin(), circuit.end());
			for (int i = 0; i < (circuit.size() - 1); i++) {
				for (int j = 0; j < problems.size(); j++) {
					int start = problems[j].at(0) - 'a';
					int end = problems[j].at(problems[j].size() - 1) - 'a';
					if (start == circuit[i] && end == circuit[i + 1]) {
						cout << problems[j] << " ";
						break;
					}
				}
				//cout << circuit[i] << " "; 

			}
			cout << endl;
		}
	}

}