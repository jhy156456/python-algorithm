#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int n;
int answerCount = 1;
vector<vector<int>>problems;
vector<vector<int>>visited;
vector<int> answers;
int dy[4] = {-1,1,0,0};//╩С,го,аб,©Л
int dx[4] = {0,0,-1,1};
void dfs(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int goY = y + dy[i];
		int goX = x + dx[i];

		if (goY<0 || goX<0 || goX>=n || goY>=n) continue;
		if (!visited[goY][goX]
			&&problems[goY][goX]==1) {
			answerCount++;
			dfs(goY, goX);
		}
	}
	
}
int main() {
	cin >> n;

	problems = vector<vector<int>>(n, vector<int>(n, 0));
	visited = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			problems[i][j] = a - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && problems[i][j] == 1) {
				dfs(i, j);
				answers.push_back(answerCount);
				answerCount = 1;
			}
		}
	}
	sort(answers.begin(), answers.end());
	cout << answers.size() << endl;
	for (int i = 0; i < answers.size(); i++)cout << answers[i] << endl;

}