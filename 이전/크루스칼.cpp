#include<iostream>
#include <string>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;
int n;
typedef pair<int, int> ii;
typedef vector<int> vi;
vector<pair<int,pair<int,int>>> edj;
class UnionFind {
private:
	vi p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)p[i] = i;
	}
	int findSet(int a) {
		return (p[a] == a) ? a : (p[a] = findSet(p[a]));
	}
	bool isSameSet(int a, int b) {
		return (findSet(a) == findSet(b));
	}
	void unionSet(int a, int b) {
		if (!isSameSet(a, b)) { //다른 집합이면
			int x = findSet(a), y = findSet(b);
			if (rank[x] > rank[y])p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}

};
void floyd(int start) {

}
int main() {
	cin >> n;
	//edj = vector<pair<int, pair<int, int>>>(n); //각 간선은 가중치, 두 정점의 페어로 표시
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a != 0) {
				edj.push_back(make_pair(a, ii(i, j)));
			}
		}
	}
	sort(edj.begin(), edj.end());

	long long mstCost = 0;
	UnionFind UF(n);
	for (int i = 0; i < (int)edj.size(); i++) {
		pair<int, ii> front = edj[i];
		if (!UF.isSameSet(front.second.first, front.second.second)) {
			mstCost += front.first;
			UF.unionSet(front.second.first, front.second.second);
		}
	}
	cout << mstCost << endl;
}