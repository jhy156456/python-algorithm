#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int, int>ii;
typedef vector<int> vi;
int t, n, m, k, result;
#define grid 500
int problem[grid][grid];
/*
first : 비활성값
second : 활성상태에서 값
first가 0되면 활성상태
first==0 second==0 이면 죽은상태
*/
ii lifeOrDie[grid][grid];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int main() {
	cin >> t;
	
	for (int a = 1; a <= t; a++) {
		result = 0;
		cin >> n >> m>>k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a;
				cin >> a;
				problem[i + 250][j + 250] = a;
				lifeOrDie[i + 250][j + 250].first = a;
				lifeOrDie[i + 250][j + 250].second = a;
			}
		}
		//와일문처음들어갈떄 : 1시간후
		//두번쨰실행 : 2시간후
		//세번째실행 : 3시간후
		//k가 3일떄 3번실행하고 3시간후인상태에서 검사
		while (k--) {
			//cout << "------------------" << endl;
			//for (int i = 240; i < 260; i++) {
			//	for (int j = 240; j < 260; j++) {
			//		cout << "(" << lifeOrDie[i][j].first << "," << lifeOrDie[i][j].second << ") ";
			//	}
			//	cout << endl;
			//}
			//cout << "------------------" << endl;
			for (int i = 0; i < grid; i++) {
				for (int j = 0; j < grid; j++) {
					//활성상태감소
					if (lifeOrDie[i][j].first == 0
						&& lifeOrDie[i][j].second>0) {
						lifeOrDie[i][j].second--;

						if (lifeOrDie[i][j].second == 0) {
							//죽은상태면 번식당하면안되기때문에
							//-1로 걸러준다
							//이렇게하면 (0,0)일때 생명력 1인새끼가 번식을안해버리누..
							lifeOrDie[i][j].second = -1;
						}
					}

					//비활성상태감소
					if (lifeOrDie[i][j].first != 0) {
						lifeOrDie[i][j].first--;
					}
					
				
				}
			}
			for (int i = 0; i < grid; i++) {
				for (int j = 0; j < grid; j++) {
					//번식조건 : 활성상태이고  첫 1시간이라면 번식한다
					if (lifeOrDie[i][j].first == 0
						&&( lifeOrDie[i][j].second == problem[i][j]-1
							|| lifeOrDie[i][j].second == problem[i][j] - 2
							)) {
						for (int k = 0; k < 4; k++) {
							int thereY = i + dy[k];
							int thereX = j + dx[k];

							if (thereY < grid && thereY >= 0
								&& thereX < grid && thereX >= 0
								&& lifeOrDie[thereY][thereX].first 
								== lifeOrDie[thereY][thereX].second
								&& problem[thereY][thereX]<problem[i][j]) {

								lifeOrDie[thereY][thereX].first = problem[i][j];
								lifeOrDie[thereY][thereX].second = problem[i][j];
								problem[thereY][thereX] = problem[i][j];
							}

						}
					}
				}
			}

		}

		for (int i = 0; i < grid; i++) {
			for (int j = 0; j < grid; j++) {
				if (lifeOrDie[i][j].first >0
					|| lifeOrDie[i][j].second > 0) {
					result++;
				}
			}
		}
		memset(problem, 0, sizeof(problem));
		memset(lifeOrDie, 0, sizeof(lifeOrDie));
		cout << "#" << a << " " << result << endl;
	}

}

