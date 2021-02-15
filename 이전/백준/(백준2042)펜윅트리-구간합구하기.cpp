#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
using namespace std;
int n;
typedef long long ll; typedef vector<ll> vll;
#define LSOne(S) ((S) & -(S))
class FenwickTree {
private: vll ft; int n;        // recall that vi is: typedef vector<int> vi;
public: 
	FenwickTree(int _n) : n(_n) { ft.assign(n + 1, 0); }    // n+1 zeroes
	FenwickTree(const vll& f) { 
		n = f.size() - 1;
		ft.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {                                  // O(n)
			ft[i] += f[i];                                      // add this value
			if (i + LSOne(i) <= n) {    // if index i has parent in the updating tree
				ft[i + LSOne(i)] += ft[i];
			}
		}
	}        // add this value to that parent
	ll rsq(int b) {//RangeSumQuery
		ll sum = 0;
		for (; b; b -= LSOne(b)) {
			sum += ft[b];
		}
		return sum;
	}
	ll rsq(int a, int b) {
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	void update(int i, ll v) {
		for (; i <= n; i += LSOne(i)) ft[i] += v;
	}

};
int main(){
	int n, m, k;

	cin >> n >> m >> k;

	vll f(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	FenwickTree ft(f);
	int count = m + k;
	while (count--) {
		int a;
		cin >> a;
		if (a == 1) {
			int b; ll c;
			cin >> b >> c;
			ll diff = c - f[b];
			f[b] = c;
			ft.update(b, diff);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << ft.rsq(b, c) << endl;
		}
	}
}

