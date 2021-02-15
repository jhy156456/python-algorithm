#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
vector<ii> home;
vector<ii> chicken;
vector<int> chickenDistance;
int n, m;
vector<int> a;
int next_combi() {
	//chicken.size() C m 
	//5C3 을구하려면 
	//i에 3 , 구하고자하는 수 +1 = n 한값을 a[i]== n 에 놓는다.
	int i = m;
	while (i >= 0 && a[i] == (chicken.size() + 1) - m + i) i--;
	if (i<0) return 0;
	a[i]++;
	for (int j = i + 1; j<m; j++) a[j] = a[i] + j - i;
	return 1;
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				home.push_back(ii(i, j));
			}
			else if (a == 2) {
				chicken.push_back(ii(i, j));
			}
		}
	}
	a.resize(chicken.size() + 1);
	for (int i = 0; i < chicken.size() + 1; i++) {
		a[i] = i + 1;
	}
	int answer = 0;
	int result = 10000;
	do {
		vector<int> minDistance(home.size(), 10000);
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < (int)home.size(); i++) {
				int distance = abs(chicken[a[j] - 1].first - home[i].first)
					+ abs(chicken[a[j] - 1].second - home[i].second);
				if (minDistance[i] > distance) minDistance[i] = distance;
			}
		}
		int sum = 0;
		for (int i = 0; i < (int)home.size(); i++) {
			sum += minDistance[i];
		}
		if (sum < result) result = sum;
	} while (next_combi());

	cout << result << endl;
	//recur(0,0);
}
