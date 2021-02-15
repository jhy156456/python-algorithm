#include<iostream>
#include<cstring>
using namespace std;


int t, n,k,result;
int problem[9][9];
int visited[9][9];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
void dfs(int y, int x,bool cutting,int depth) {
	visited[y][x] = 1;
	depth++;
	//전 단계에서 지금단계를 자르고 온것이라면
	if (cutting) {
		for (int i = 0; i < 4; i++) {
			int thereY = y + dy[i];
			int thereX = x + dx[i];
			if (thereY >= 0 && thereY < n
				&& thereX >= 0 && thereX < n
				&& visited[thereY][thereX] != 1) {
				//자르고 갈 수 없는곳만 갈 수 있다
				if (problem[y][x] > problem[thereY][thereX]) {
					dfs(thereY, thereX, 1, depth);
				}
			}
		}
		
	}
	//전 단계에서 지금단계를 자르고 온것이 아니라면
	else {
		for (int i = 0; i < 4; i++) {
			int thereY = y + dy[i];
			int thereX = x + dx[i];
			if (thereY >= 0 && thereY < n
				&& thereX >= 0 && thereX < n
				&&visited[thereY][thereX] !=1) {
				//자르지 않고 진행 가능
				if (problem[y][x] > problem[thereY][thereX]) {
					dfs(thereY, thereX, 0, depth);
				}
				//자르고 진행 가능
				else if (problem[y][x] > problem[thereY][thereX] - k) {
					for (int j = 1; j <= k; j++) {
						if (problem[y][x] > problem[thereY][thereX] - j) {
							problem[thereY][thereX] = problem[thereY][thereX] - j;
							dfs(thereY, thereX, 1, depth);
							problem[thereY][thereX] = problem[thereY][thereX] + j;
							break;
						}
					}
					
				}
			}
		}
	}
	if (result < depth) result = depth;
	visited[y][x] = 0;
}
int main() {
	cin >> t;
	for (int a = 1; a <= t; a++) {
		cin >> n >> k;
		int maxHeight = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> problem[i][j];
				if (maxHeight < problem[i][j])maxHeight = problem[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				if (maxHeight == problem[i][j]) {
					bool cutting = 0;
					dfs(i, j,cutting,0);
					memset(visited, 0, sizeof(visited));
				}
			}
		}
		cout << "#" << a << " " << result << endl;
		result = 0; maxHeight = 0; memset(problem, 0, sizeof(problem));
	}
}