#include<iostream>
#include<vector>
using namespace std;

int nearest[6] = { 0 };
int distanced[6] = { 0 };

class edge {
public:
	int v1, v2, cost;
};

void prim(int n, int W[][100], vector<edge> &F) {
	int i, vnear;
	int min;
	for (i = 2; i <= n; i++) {
		nearest[i] = 1;
		distanced[i] = W[1][i];
	}
	int count = n-1;

	int first = 1;
	vnear = 1;

	while (count--) {
		first = vnear;
		min = 10000;
		for (i = 2; i <= 5; i++)
			if (0 <= distanced[i]&& distanced[i] < min) {
				min = distanced[i];
				vnear = i;
			}

	/*	edge e;
		e.v1 = first;
		e.v2 = vnear;
		e.cost = W[first][vnear];
		F.push_back(e);*/

		distanced[vnear] = -1;
		for (i = 2; i <= n; i++)
			if (W[i][vnear] < distanced[i]) {
				distanced[i] = W[i][vnear];
				nearest[i] = vnear;
			}
	}
}

int main() {
	int W[100][100];
	vector<edge> F;
	W[1][1] = 0;
	W[1][2] = 1;
	W[1][3] = 3;
	W[1][4] = 10000;
	W[1][5] = 10000;
	W[2][1] = 1;
	W[2][2] = 0;
	W[2][3] = 3;
	W[2][4] = 6;
	W[2][5] = 10000;
	W[3][1] = 3;
	W[3][2] = 3;
	W[3][3] = 0;
	W[3][4] = 4;
	W[3][5] = 2;
	W[4][1] = 10000;
	W[4][2] = 6;
	W[4][3] = 4;
	W[4][4] = 0;
	W[4][5] = 5;
	W[5][1] = 10000;
	W[5][2] = 10000;
	W[5][3] = 2;
	W[5][4] = 5;
	W[5][5] = 0;
	prim(5, W, F);

	for (int i = 1; i <= 5; i++) {
		cout << distanced[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= 5; i++) {
		cout << nearest[i] << " ";
	}
	cout << endl;
	//for (int i = 0; i <= 3; i++) {
	//	cout << F[i].cost << " ";
	//}
	//cout << endl;
	return 0;
}