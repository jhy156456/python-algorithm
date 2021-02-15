#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int>ii;
typedef vector<int> vi;
int t, n, m,result,problem[20][20],manageTerritory[20][20];
void manage(int y, int x,int upDownLength) {
	//상 색칠
	for (int i = 1; i < upDownLength; i++) {
		if(y-i>=0)manageTerritory[y - i][x] = 1;
	}
	//하 색칠
	for (int i = 1; i < upDownLength; i++) {
		if(y+i<n)manageTerritory[y + i][x] = 1;
	}
}
int main() {
	cin >> t;

	for (int a = 1; a <= t; a++) {
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> problem[i][j];
			}
		}
		result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 1; k <= 40; k++) {
					manageTerritory[i][j] = 1;
					manage(i, j, k);
					//오른쪽으로가면서 위아래색칠함수 콜
					for (int right = 1; right < k; right++) {
						if (j + right < n) {
							manageTerritory[i][j + right] = 1;
							manage(i, j + right, k - right);
						}
					}
					//왼쪽으로가면서 위아래색칠함수 콜
					for (int left = 1; left < k; left++) {
						if (j - left >= 0) {
							manageTerritory[i][j - left] = 1;
							manage(i, j - left, k - left);
						}
					}

					int homeCount = 0;
					for (int row = 0; row < n; row++) {
						for (int col = 0; col < n; col++) {
							//집이 있고 방범 영역이면 
							if (manageTerritory[row][col] == 1
								&& problem[row][col] == 1) {
								homeCount++;
							}
						}
					}
					int manageCost = k * k + (k - 1) * (k - 1);
					int profit = homeCount * m - manageCost;
					//손해보지않고
					if (profit > 0) {
						//서비스 가능한 최대집의 수가 전에 조사했던곳보다 많다면
						//result를 갱신한다
						if (result < homeCount) {
							result = homeCount;
						}
					}
					memset(manageTerritory, 0, sizeof(manageTerritory));
				}


			}
		}


		cout << "#" << a << " " << result << endl;
	}

}

