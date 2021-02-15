#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
vector<iii> oneJa;
int direction[1001];
int energy[1001];
//좌표에있는 원자의 인덱스
int problem[4001][4001];
int problemSize[4001][4001];
int selectedOneJa[1001];
vector<int> boomOneJa;

int t, n,result;
int dy[] = {1,-1,0,0 };
int dx[] = { 0,0,-1,1 };
int main(){
	cin >> t;

	for (int a = 1; a <= t; a++) {
		cin >> n;
		memset(problem,-1, sizeof(problem));

		for (int i = 0; i < n; i++) {
			int b, c, d, e;
			cin >> b >> c >> d >> e;
			//pair.second = 1이면 충돌한것, 0이면 충돌하지않은것
			oneJa.push_back(iii(ii((b+1000)*2,(c+1000)*2),0));
			problem[(c + 1000) * 2][(b + 1000) * 2]=1;
			direction[i] = d; energy[i] = e;
		}
		int firstOneJaSize = n;

		while (firstOneJaSize != 0) {
			for (int i = 0; i < (int)oneJa.size(); i++) {
				if (!oneJa[i].second) {
					int hereX = oneJa[i].first.first;
					int hereY = oneJa[i].first.second;

					int thereX = hereX + dx[direction[i]];
					int thereY = hereY + dy[direction[i]];
					if (thereY<0 || thereX<0 || thereY>4000 || thereX>4000) {
						oneJa[i].second = 1;//이제 사용하지 않을 원자 :1
						problem[hereY][hereX]=-1;
						firstOneJaSize--;
						continue;
					}
					oneJa[i].first.first = thereX;
					oneJa[i].first.second = thereY;
					//0이라면
					if (problem[thereY][thereX]==-1) {
						problem[thereY][thereX] = i;

					}
					//0이아니고 어떤 원자가 미리 그 좌표에 있었다면
					else {
						
						if (selectedOneJa[problem[thereY][thereX]] == 0) {
							boomOneJa.push_back(problem[thereY][thereX]);
							selectedOneJa[problem[thereY][thereX]]++;
							problemSize[thereY][thereX]++;
						}
						if (selectedOneJa[i] == 0) {
							boomOneJa.push_back(i);
							selectedOneJa[i]++;
							problemSize[thereY][thereX]++;
						}
						problem[thereY][thereX] = i;
					}
					//이동한 뒤 원래있던위치 -1으로
					problem[hereY][hereX] = -1;
				}
			}

			for (int i = 0; i < (int)oneJa.size(); i++) {
				if (!oneJa[i].second) {
					int checkY = oneJa[i].first.second;
					int checkX = oneJa[i].first.first;
					if (problemSize[checkY][checkX]>=2) {
						for (int j = 0; j <boomOneJa.size(); j++) {
							result += energy[boomOneJa[j]];
							oneJa[boomOneJa[j]].second = 1;
							problemSize[oneJa[boomOneJa[j]].first.second][oneJa[boomOneJa[j]].first.first]--;
							problem[oneJa[boomOneJa[j]].first.second][oneJa[boomOneJa[j]].first.first] = -1;
							firstOneJaSize--;
						}
						boomOneJa.clear();
						break;
						
					}
				}
			}
		}

		cout << "#" << a << " " << result << endl;
		oneJa.clear(); result = 0; memset(direction, 0, sizeof(direction)); memset(energy, 0, sizeof(energy));
		memset(selectedOneJa, 0, sizeof(selectedOneJa)); memset(problemSize, 0, sizeof(problemSize));
	}
}
