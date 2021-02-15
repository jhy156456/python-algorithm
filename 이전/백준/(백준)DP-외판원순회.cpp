#include<cstring>
#include <iostream>
#include<algorithm>
using namespace std;

int n, dist[17][17];
int cache[17][1 << 17];
int shortestPath2(int here, int visited) {
	//cout << visited << endl;
	if (visited == (1 << n) - 1 && dist[here][0]!=0) return dist[here][0];
	else if (visited == (1 << n) - 1 && dist[here][0] == 0) return 1000000000;
	int &ret = cache[here][visited];
	if (ret >= 0)return ret;
	ret = 1000000000;
	for (int next = 0; next < n; next++) {
		if (visited & (1 << next)) continue;
		if (dist[here][next] != 0) {
			int cand = dist[here][next]
				+ shortestPath2(next, visited + (1 << next));
			ret = min(ret, cand);
		}
	}
	//cout << ret << endl;
	return ret;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	cout << shortestPath2(0, 1) << endl;
}