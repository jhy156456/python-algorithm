#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> si;
typedef vector<vi> vvi;
int n, s, m;
vi volume;
vvi cache;
int result = 0;
map<string,string> adj;
map<string, int> mapPrice;
map<string, int>::iterator mapIterator;
void dfs(string here,int price) {
	//10%를 위로 올리고
	//90%는 자기가 갖는다.
	int upPrice = price * 0.1;
	if (here == "mary") {
		cout << ":asdf" << endl;
	}
	mapIterator = mapPrice.find(here);
	if (mapIterator == mapPrice.end()) {
		mapPrice.insert(si(here, price-upPrice));
	}
	else {
		mapIterator->second += price - upPrice;
	}

	for (int i = 0; i < 1; i++) {
		string there = adj.find(here)->second;
		if (there == "-") {
			//최대 높이에 도달
			return;
		}
		else {
			if (upPrice > 1) {
				dfs(there, upPrice);
			}
		}
	}
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;
	
	for (int i = 0; i < enroll.size(); i++) {
		string enroller = enroll[i];
		string parent = referral[i];
		adj.insert(pair<string,string>(enroller, parent));
	}

	for (int i = 0; i < seller.size(); i++) {
		int price = 100 * amount[i];
		string mySeller = seller[i];
		string there = adj.find(mySeller)->second;
		mapIterator = mapPrice.find(mySeller);
		//10%를 먼저 하고 나머지를 뺀다
		int upPrice = price * 0.1;

		if (mapIterator == mapPrice.end()) {
			mapPrice.insert(si(mySeller, price-upPrice));
		}
		else {
			mapIterator->second += price - upPrice;
		}
		if (there != "-") {
			//최대 높이에 도달
			dfs(adj.find(mySeller)->second, upPrice);
		}
		
	}

	//for (auto it = mapPrice.begin(); it != mapPrice.end(); it++) {
	//	cout << "key: " << it->first << " " << "value: " << it->second << '\n';
	//}
	for (int i = 0; i < enroll.size(); i++) {
		map<string, int>::iterator dd;
		dd = mapPrice.find(enroll[i]);

		if (dd == mapPrice.end()) {
			answer.push_back(0);
		}
		else {
			answer.push_back(dd->second);
		}

	}
	return answer;
}
int main() {

	vi answer = solution(
		{ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" },
		{ "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" },
		{ "young", "john", "tod", "emily", "mary" },
		{ 12, 4, 2, 5, 10 });
	//cin >> n >> s >> m;
	//cache = vvi(1001,vi(n,-1));
	//for (int i = 0; i < n; i++) {
	//	int a;
	//	cin >> a;
	//	volume.push_back(a);
	//}
	//
	//cout << result << endl;

}