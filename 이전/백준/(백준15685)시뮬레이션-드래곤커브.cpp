#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
typedef pair<int, int> ii;
int problem[101][101];
int dy[] = { 0,-1,0,1 };//0(오른쪽),1(위),2(왼쪽),3(아래)
int dx[] = { 1,0,-1,0 };
int n;
int reverseClockWise(int direction) {
	if (direction == 0) return 1;
	else if (direction == 1) return 2;
	else if (direction == 2) return 3;
	else if (direction == 3) return 0;
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;

		cin >> x >> y >> d >> g;

		vector<ii> dragon;
		vector<int> direction;
		
		//우선 벡터에넣고 좌표확인 한 후에 벡터 필요없고 배열에 바로
		//true값 표현 가능하기떄문에 디버깅 한 후에 코드 변경하자
		dragon.push_back(ii(y,x));
		dragon.push_back(ii(y+dy[d], x+dx[d]));
		direction.push_back(d);
		//1세대 이상이면 세대만큼 for문돔
		for (int j = 0; j < g; j++) {
			vector<int> reverse;
			for (int k = (int)direction.size()-1; k >=0 ; k--) {
				direction.push_back(reverseClockWise(direction[k]));
				dragon.push_back(ii(
					dragon.back().first+dy[reverseClockWise(direction[k])],
					dragon.back().second+dx[reverseClockWise(direction[k])]));
			}
			
		}

		for (int k = 0; k < (int)dragon.size(); k++) {
			problem[dragon[k].first][dragon[k].second] = 1;
		}
		dragon.clear();
		direction.clear();
	}
	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (problem[i][j] == 1 && problem[i + 1][j] == 1
				&& problem[i][j + 1] == 1 && problem[i + 1][j + 1] == 1)
				count++;
		}
	}

	cout << count << endl;
}