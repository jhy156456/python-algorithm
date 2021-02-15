#include<iostream>
#include<vector>
using namespace std;

int nearest[1000] = { 0 };
int distanced[1000] = { 0 };

void prim(int n, int **W) {
	int i, vnear;
	int min;
	int start = n / 2;
	for (i = 0; i < n; i++) {
		nearest[i] = start;
		distanced[i] = W[start][i];
	}
	int count = n-1;
	int first = start;
	vnear = start;
	while (count--) {
		min = 10000;
		for (i = 0; i < n; i++)
			if (0 <= distanced[i]&& distanced[i] < min) {
				min = distanced[i];
				vnear = i;
			}
		distanced[vnear] = -1;
		for (i = 0; i < n; i++)
			if (W[i][vnear] < distanced[i]) {
				distanced[i] = W[i][vnear];
				nearest[i] = vnear;
			}
	}
}

int main() {
	
	int N;
	cin >> N;
	int **W = new int*[N];
	for (int i = 0; i < N; i++) {
		W[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	prim(N, W);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += W[i][nearest[i]];
	}
	cout << sum<<endl;
	return 0;
}