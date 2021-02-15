#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
int t,n;
vector<pair<ii, int>> problem;
int visited[5001][5001];
class UnionFind {      
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { 
		return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
	}
	bool isSameSet(int i, int j) { 
		return findSet(i) == findSet(j); 
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
			else {
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
	int numDisjointSets() { return numSets; }
};
double distance(const int p1X, const int p1Y,const int p2X,const int p2Y) {
	double distance;
	distance = sqrt(pow(p1X - p2X, 2) + pow(p1Y - p2Y, 2));
	return distance;
}
int main() {
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 100; j++) {
			cout << i << " " << j << " " << 4000 << endl;
		}
	}*/
	cin >> t;
	while (t--) {
		cin >> n;
		memset(visited, -1, sizeof(visited));
		UnionFind uf(n);
		for (int k = 0; k < n; k++) {
			int x, y, r;
			cin >> x >> y >> r;
			problem.push_back(make_pair(ii(x, y), r));
		}
		for (int i = 0; i < n; i++) {
			for (int j = i; j <n; j++) {
				//int r1 = problem[i].second로 하면 틀림... int와 double형변환에 관해서 공부하자
				double r1 = problem[i].second;
				double r2 = problem[j].second;
				double centerToCenter = distance(problem[i].first.first, problem[i].first.second, problem[j].first.first, problem[j].first.second);
				if (centerToCenter <= r1 + r2) {
					uf.unionSet(i, j);
				}
			}
		}
		cout << uf.numDisjointSets() << endl;
		problem.clear();
	}
}