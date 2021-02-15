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
			if (there > getKey && !visited[value]) { //��������Ʈ ���鼭 ���������� �տ����� ��带 ã�´�
				there = getKey;
				dfsValue = i; //��������Ʈ�� Ư�� �ε����� �����ϱ� ����
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
	���������� �տ����� ��带 ã�Ҵµ� 1->2 / 1->3 / 3->1 �ΰ�쿡��
	1->2���ٰ� ���̾�� dfs�� �����ϰԵȴ� ���� 1->2���ٰ� ���� ���°�쿡��
	�ٽ� ���� ������� 1->3�� �ؾ��Ѵ�.. ����ؾ�����?
	���ĺ��� �տ����°� ã�Ƽ� ������! ��λ��������Ѵ�?
	�ٽõ��ƿͼ� �������ΰ�����.. �̰� ��Ƴ�
	*/
}

vector<string> solution(vector<vector<string>> tickets) {
	pathSize = tickets.size() + 1;
	adj = vector<vector<int>>(tickets.size());
	visited = vector<int>(tickets.size());
	for (int i = 0; i < (int)tickets.size(); i++) {
		for (int j = 0; j < 2; j++) {
			if (stringtoNodeNumber.find(tickets[i][j]) == stringtoNodeNumber.end()) {//�ѹ����Ǿ����� �ʴٸ�
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