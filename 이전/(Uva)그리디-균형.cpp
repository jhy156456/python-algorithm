#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<string>
#include<cstring>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;
typedef vector<vector<double>> vvd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<double> vd;
#define INF 1000000000
using namespace std;
int n, k;
vvd centriFugation;
vd mass;
int main() {
	while (true) {
		cin >> n >> k;
		if (n == '\n') break;
		centriFugation = vvd(n, vd());
		mass = vd(k);
		for (int i = 0; i < k; i++) {
			cin >> mass[i];
		}
		for (int i = k; i < 2 * n; i++) {
			mass.push_back(0);
		}

		sort(mass.begin(), mass.end());
		for (int i = 0; i < n; i++) {
			centriFugation[i].push_back(mass[i]);
			centriFugation[i].push_back(mass[mass.size() - i - 1]);
		}
		double sum = 0.0;
		for (int i = 0; i < (int)mass.size(); i++) {
			sum += mass[i];
		}

		double imbalance = sum / n;
		double imbalanceResult = 0.0;

		for (int i = 0; i < n; i++) {
			cout << i << ": ";
			double eachCase = 0.0;
			for (int j = 0; j < (int)centriFugation[i].size(); j++) {
				if (centriFugation[i][j] != 0) {
					cout << (int)centriFugation[i][j] << " ";
					eachCase += centriFugation[i][j];
				}
			}

			imbalanceResult += abs(eachCase - imbalance);
			cout << endl;
		}
		cout << fixed;
		cout.precision(5);
		cout << imbalanceResult << endl;

	}
}