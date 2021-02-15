#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<math.h>
#include<map>
using namespace std;
int n;
typedef unsigned long long ll; typedef vector<ll> vll; typedef vector<int> vi;
map<int, int> Aresults;
map<int, int> Bresults;
vi primes;
bitset<1000010> bs;
ll _sieve_size;
void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= (ll)_sieve_size; i++) {
		if (bs[i]) {
			for (ll j = i * i; j <= (ll)_sieve_size; j += i) {
				bs[j] = 0;
			}
			primes.push_back((int)i);
		}
	}
}
void AprimeFactor(int N) {
	vi factors;
	int PF_idx = 0, PF = primes[PF_idx];

	while (PF*PF <= N) {
		int cnt = 0;
		while (N%PF == 0) {
			N /= PF;
			cnt++;
		}
		if (Aresults.find(PF) != Aresults.end()) {
			Aresults[PF] = Aresults[PF] + cnt;
		}
		else {
			Aresults[PF] = cnt;
		}
		Aresults[PF] = Aresults[PF] + cnt;
		PF = primes[++PF_idx];
	}
	if (N != 1) {
		if (Aresults.find(N) != Aresults.end()) Aresults[N] = Aresults[N] + 1;
		else Aresults[N] = 1;
	}
}
void BprimeFactor(int N) {
	vi factors;
	int PF_idx = 0, PF = primes[PF_idx];
	while (PF*PF <= N) {
		int cnt = 0;
		while (N%PF == 0) {
			N /= PF;
			cnt++;
		}
		if (Bresults.find(PF) != Bresults.end()) {
			Bresults[PF] = Bresults[PF] + cnt;
		}
		else {
			Bresults[PF] = cnt;
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) {
		if (Bresults.find(N) != Bresults.end())Bresults[N] = Bresults[N] + 1;
		else Bresults[N] = 1;
	}
}
int main() {
	int n, m;
	cin >> n;
	sieve(1000000);
	while (n--) {
		int problem;
		cin >> problem;
		AprimeFactor(problem);
	}
	cin >> m;
	while (m--) {
		int problem;
		cin >> problem;
		BprimeFactor(problem);
	}
	map<int, int >::iterator mm_iter;
	bool checkNum = false;
	ll problemResult = 1;
	for (mm_iter = Aresults.begin(); mm_iter != Aresults.end(); mm_iter++) { //2가 몇개인지 등등이나옴
		//cout << "asdf : " << mm_iter->first << endl;
		//cout << "asdf : " << mm_iter->second << endl;
		if (Bresults.find(mm_iter->first) == Bresults.end()) {// A에 있는 값을 B에서 못찾았으면
			continue;
		}
		int twoResultMin = min(mm_iter->second, Bresults[mm_iter->first]);
		//cout << "two : " << twoResultMin << endl;
		for (int i = 0; i < twoResultMin; i++) {
			problemResult *= mm_iter->first;
			if (problemResult > 1000000000) {
				//cout << "nn : " << problemResult << endl;
				checkNum = true;
				problemResult %= 1000000000;
			}
		}
	}
	if (checkNum) { //10억보다 작으면
		printf("%09lld\n", problemResult);
	}
	else {
		printf("%lld\n", problemResult);
	}
}