#include <iostream>
#include <string>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
int dy[4] = { -1,1,0,0 };//상,하,좌,우
int dx[4] = { 0,0,-1,1 };
/*
void dfs(int y, int x, int pixel) {
	visited[y][x] = true;
	areaCount++;
	//cout << "??" << endl;
	for (int i = 0; i < 4; i++) {
		int thereY = y + dy[i];
		int thereX = x + dx[i];
		if (thereY >= 0 && thereY < row
			&& thereX >= 0 && thereX < col && !visited[thereY][thereX]) {
			if (pixel == problems[thereY][thereX]) {
				dfs(thereY, thereX, pixel);
			}
		}
	}
}
*/
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	queue<ii> q;
	int number_of_area = 0;
	bool visited[100][100] = { 0, };
	int max = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int areaCount = 0;
			//방문한적이 없다면 큐에넣자!
			if (!visited[i][j] && picture[i][j] != 0) {
				q.push(ii(i, j));
				number_of_area++;
				visited[i][j] = true; 
			}
			while (!q.empty()) {
				areaCount++;
				ii front = q.front();
				
				q.pop();
				for (int i = 0; i < 4; i++) {
					int thereY = front.first + dy[i];
					int thereX = front.second + dx[i];
					if (!visited[thereY][thereX]
						&& thereY >= 0 && thereY < m
						&& thereX >= 0 && thereX < n
						&& picture[thereY][thereX]==picture[front.first][front.second]) {
						visited[thereY][thereX] = true;
						q.push(ii(thereY, thereX));
					}
				}
			}	
			if (max < areaCount)max = areaCount;
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max;
	return answer;
}
int main()
{
	vector<vector<int>> picture = { {1, 1, 1, 0},{1, 1, 1, 0},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} };

	vector<int> results = solution(6,4, picture);

	cout << results[0] << " " << results[1] << endl;
	//for (int i = 0; i < 50; i++) {
	//	cout << "{";
	//	for (int j = 0; j < 50; j++) {
	//		if (j == 49) {
	//		cout << 1;
	//		break;
	//		}
	//		cout << 1 << ",";
	//	}
	//	cout << "},";
	//}
}