#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include<cstring>
using namespace std;
typedef pair<int, int>ii;
int row, col, y, x, second,t,problem[50][50],visited[50][50];
vector<int> dy[8] = { 
	{0,0,0,0},{-1,1,0,0 },{-1,1},{0,0},{-1,0},{0,1},{0,1},{-1,0}
};
vector<int> dx[8] = { 
	{0,0,0,0},{0,0,-1,1},{0,0},{-1,1},{0,1},{1,0},{-1,0},{0,-1}
};
int checkPipe[9][4][4] = {
	{

	},
{
	{1,2,5,6},{1,2,4,7},{1,3,4,5},{1,3,6,7}
},
{
	{ 1,2,5,6 },{ 1,2,4,7 }
	
},
{
	{ 1,3,4,5 },{ 1,3,6,7 }
},
{
	{1,2,5,6},{1,3,6,7}
},
{
	{1,3,6,7},{1,2,4,7}
},
{
	{1,3,4,5},{1,2,4,7}
},
{
	{1,2,5,6},{1,3,4,5}
}
};

void bfs(int y, int x) {
	visited[y][x] = 1;

	queue<ii> q;
	q.push(ii(y, x));

	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		int herePipe = problem[hereY][hereX];
		q.pop();

		for (int i = 0; i <  dy[herePipe].size(); i++) {
			int thereY = hereY + dy[herePipe][i];
			int thereX = hereX + dx[herePipe][i];
			for (int j = 0; j < 4; j++) {
				if (visited[thereY][thereX] == 0
					&& visited[hereY][hereX]<second
					&& thereY >= 0 && thereY < row
					&&thereX>=0 && thereX < col
					&&problem[thereY][thereX]==checkPipe[herePipe][i][j]
					) {
					q.push(ii(thereY, thereX));
					visited[thereY][thereX] = visited[hereY][hereX] + 1;
				}
			}
			
		}
	}
}
int main() {
	cin >> t;

	for (int a = 1; a <= t; a++) {
		cin >> row >> col >> y >> x >> second;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> problem[i][j];
			}
		}

		bfs(y, x);

		int result = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (visited[i][j] != 0) {
					result++;
				}
			}
		}

		cout << "#" << a << " " << result << endl;
		memset(problem, 0, sizeof(problem)); memset(visited, 0, sizeof(visited));
	}
}

