#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
int v,e;
const int MAX = 401;
const int MAXE = 401*401;
const int INF = 100000000;
vvi adj;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e;
	adj = vvi(v + 1, vi(v + 1, INF));

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
	}

	//플로이드 알고리즘 첫번째
	//for (int i = 1; i <= v; i++) {
	//	for (int j = 1; j <= v; j++) {
	//		if (i != j)
	//			C[1][i][j] = min(adj[i][j], adj[i][1] + adj[1][j]);
	//		else
	//			C[1][i][j] = 0;
	//	}
	//}
	//

	//for (int k = 2; k <= v; k++) {
	//	for (int i = 1; i <=v; i++) {
	//		for (int j = 1; j <= v; j++) {
	//			C[k][i][j] = min(C[k - 1][i][j], C[k - 1][i][j] + C[k - 1][k][j]);
	//		}
	//	}
	//}

	//플로이드 알고리즘 2번째
	for (int i = 1; i <= v; i++) {
		adj[i][i] = 0;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	int result = 100000000;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;
			if (adj[i][j] < 10001) result = min(result, adj[i][j] + adj[j][i]);
			
		}
	}

	cout << result << endl;
}