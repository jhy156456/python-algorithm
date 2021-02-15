#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int v, e;
vector<vector<int>>adj;
vector<int> dfs_low;
vector<int> dfs_num;
vector<int> parent;
vector<int> cutVertex;
int dfsCounter = 0;
int dfsRoot,rootChildren=0;
void findCutVertex(int u) {
	dfs_num[u] = dfs_low[u] = dfsCounter++;

	for (int i = 0; i < adj[u].size(); i++) {
		int there = adj[u][i];
		if (dfs_num[there] ==-1) {
			parent[there] = u;
			if (u == dfsRoot)rootChildren++;
			findCutVertex(there);
			if (dfs_low[there] >= dfs_num[u]) {
				//cout << "비교속에 들어온것 : u,there" << u << there << endl;
				cutVertex[u] = 1;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[there]);
		}
		else {
			if (there != parent[u]) {
				dfs_low[u] = min(dfs_low[u], dfs_num[there]);
			}
		}
	}
}
int main() {
	cin >> v >> e;
	adj = vector<vector<int>>(v+1);
	dfs_low = vector<int>(v+1, 0);
	dfs_num = vector<int>(v+1, -1);
	parent = vector<int>(v+1, 0);
	cutVertex = vector<int>(v+1, 0);

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=0; i<e; i++){
		if (dfs_num[i] == -1) { 
			dfsRoot = i; rootChildren = 0;
			findCutVertex(i); 
			cutVertex[dfsRoot] = (rootChildren > 1);
		
		}
	}
	int cutCount = 0;
	for (int i = 0; i < v + 1; i++) {
		if (cutVertex[i]) { 
			cutCount++;
		}
	}
	cout << cutCount << endl;
	
	for (int i = 0; i < v + 1; i++) {
		if (cutVertex[i]) {
			cout << i << " ";
		}
	}
}