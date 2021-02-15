#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> ii;
int problem[31][11];
int n, m, h,findAnswer;
int result = 4;
/*
getResults()함수에서 1~n까지 출발지점,도착지점을 벡터에넣고
전부 조사 한 후에 벡터를 사이즈만큼돌면서
(출발지점과, 도착지점)이 다른 좌표를 조사했는데 시간초과났음
그럴필요 없이 세로선1줄마다 도착지점을 비교하면서 도착지점이 다르다면
false를 반환하게하여 시간안에 AC판정
*/
bool getResults() {
	bool same = true;
	for (int i = 1; i <= n; i++) {
		int hereY = 0, hereX = i;
		while (hereY != h + 1) {
			hereY++;
			//좌표자신이 1이라면 오른쪽으로 증가
			if (problem[hereY][hereX] == 1) {
				hereX++;
			}
			//왼쪽이 1이라면 왼쪽으로 증가
			else if (problem[hereY][hereX - 1] == 1) {
				hereX--;
			}
		}
		if (i != hereX) {
			same = false;
			break;
		}
	}
	return same;
}
bool putLadder(int y, int x) {
	//사다리를 놓을 수 있는 조건은
	//자신이 0이 아니면서 자신의 왼쪽이 1이아니고 오른쪽도 1이 아닐때
	if (problem[y][x] == 0 && problem[y][x - 1] != 1
		&&problem[y][x+1]!=1) {
		return true;
	}
	return false;
}
/*
처음 코드 짰을때의 문제점
사다리를 놓는다-> 정답이아니다 -> depth증가
사다리를 놓는다-> 정답이다 -> 출력
*/
void dfs(int y, int x,int depth) {
	//놓을 수 있는 사다리 좌표쌍을 전부 구한다.
	for (int i = y; i <= h; i++) {//가로
		for (int j = 1; j <n; j++) {//세로
			if (putLadder(i, j)) {
				problem[i][j] = 1;
				if (getResults()) {
					if (result > depth) { 
						result = depth; 
					}
				}
				else if (depth < 3) {
					depth++;
					dfs(i, j, depth);
					depth--;
				}
				problem[i][j] = 0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int y, x;
		cin >> y >> x;
		problem[y][x] = 1;
	}
	if (getResults()) {
		cout << 0 << endl;
	}
	else {
		dfs(1,1,1);
		if (result >= 4) {
			cout << -1 << endl;
		}
		else {
			cout << result << endl;
		}
	}
}