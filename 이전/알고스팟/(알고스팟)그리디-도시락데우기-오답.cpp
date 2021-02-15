#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
using namespace std;
int c,n;
vii eatTimeAndMicroWave;
vi microWave;
vi eatTime;
int main() {
	cin >> c;
	while (c--) {
		cin >> n;
		eatTimeAndMicroWave.clear();
		microWave.assign(n, 0);
		eatTime.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> microWave[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> eatTime[i];
		}
		for (int i = 0; i < n; i++) {
			eatTimeAndMicroWave.push_back(ii(eatTime[i], microWave[i]));
		}
		//먹는시간 기준으로 내림차순정렬
		sort(eatTimeAndMicroWave.begin(), 
			eatTimeAndMicroWave.end(),greater<ii>());
		
		int wholeEatTime = 0;

		while ((int)eatTimeAndMicroWave.size() != 2 && (int)eatTimeAndMicroWave.size()>1) {
			//데우는시간을 더해욤
			wholeEatTime = eatTimeAndMicroWave[0].second;
			eatTimeAndMicroWave.erase(eatTimeAndMicroWave.begin());
		}

		//2개남은것중 먹는시간이 오래걸리는 도시락의 데우는시간을
		//더한 후에 그거 먹는시간이 다음도시락의 데우기+먹는시간과
		//비교해서 더 큰것을 더해준다
		
		if ((int)eatTimeAndMicroWave.size() == 2) {
			wholeEatTime += eatTimeAndMicroWave[0].second;
			if (eatTimeAndMicroWave[0].first
		> eatTimeAndMicroWave[1].first
				+ eatTimeAndMicroWave[1].second) {
				wholeEatTime += eatTimeAndMicroWave[0].first;
			}
			else {
				wholeEatTime += eatTimeAndMicroWave[1].first
					+ eatTimeAndMicroWave[1].second;
			}
		}
		else { //도시락 1개일떄
			wholeEatTime += eatTimeAndMicroWave[0].first+ eatTimeAndMicroWave[0].second;
		}
		cout << wholeEatTime << endl;

	}
}