#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;
vector<vector<int>> adj;
vector<int>visited;
map<string, int> stringtoNodeNumber;
int numbering = 0;
vector<string>answer;
int pathSize = 0;
string getKeybyValue(int key) {
	auto it = stringtoNodeNumber.begin();
	while (it != stringtoNodeNumber.end()){
		if (it->second == key){
			return it->first;
		}
		it++;
	}
}
void dfs(string here) {
	
	string getKey = "";
	answer.push_back(here);
	int dfsValue = 0;
	if (adj.size() <= (int)stringtoNodeNumber[here])return;
	if ((int)adj[stringtoNodeNumber[here]].size() == 0) {
		return;
	}
	vector<int>visited(pathSize, 0);
	while ((int)adj[stringtoNodeNumber[here]].size() != 0) {
		string there = "Z";

		int visitedValue = 0;
		for (int i = 0; i < (int)adj[stringtoNodeNumber[here]].size(); i++) {
			int value = adj[stringtoNodeNumber[here]][i];
			getKey = getKeybyValue(value);
			//!visited[i] => 
			if (there > getKey && !visited[value]) { //인접리스트 돌면서 사전순으로 앞에오는 노드를 찾는다
				there = getKey;
				dfsValue = i; //인접리스트에 특정 인덱스값 삭제하기 위함
				visitedValue = value;
			}
		}
		visited[visitedValue] = true;
		adj[stringtoNodeNumber[here]].erase(adj[stringtoNodeNumber[here]].begin() + dfsValue);

		dfs(there);
		if (answer.size() == pathSize) return;
		else {
			answer.pop_back();
			adj[stringtoNodeNumber[here]].push_back(visited[visitedValue]);
		}

	}

	/*
	사전순으로 앞에오는 노드를 찾았는데 1->2 / 1->3 / 3->1 인경우에는
	1->2갔다가 길이없어서 dfs가 종료하게된다 따라서 1->2갔다가 길이 없는경우에는
	다시 길을 살려놓고 1->3을 해야한다.. 어떻게해야하지?
	알파벳순 앞에오는거 찾아서 가보고! 경로생성을못한다?
	다시돌아와서 다음꺼로가보자.. 이게 어렵네
	*/
}

vector<string> solution(vector<vector<string>> tickets) {
	pathSize = tickets.size() + 1;
	adj = vector<vector<int>>(tickets.size());
	visited = vector<int>(tickets.size());
	for (int i = 0; i < (int)tickets.size(); i++) {
		for (int j = 0; j < 2; j++) {
			if (stringtoNodeNumber.find(tickets[i][j]) == stringtoNodeNumber.end()) {//넘버링되어있지 않다면
				stringtoNodeNumber[tickets[i][j]] = numbering++;
			}
			if (j == 1) {
				adj[stringtoNodeNumber[tickets[i][j - 1]]].push_back(stringtoNodeNumber[tickets[i][j]]);
			}
		}
	}
	dfs("A");
	return answer;
}
int main() {
	vector<string> answers = solution({ {"A", "B"},{"A", "C"},{"C", "A"} });
	for (int i = 0; i < (int)answers.size(); i++)cout << answers[i] << endl;
}