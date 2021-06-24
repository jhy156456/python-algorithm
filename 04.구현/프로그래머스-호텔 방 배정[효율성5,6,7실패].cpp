#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;  
vector<pair<ll, ll>> problems;
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	multiset<ll> remainRooms;
	for (ll i = 1; i <= k; i++) {
		remainRooms.insert(i);
	}
	for (ll i = 0; i < (ll)room_number.size(); i++) {
		multiset<ll>::iterator it = remainRooms.find(room_number[i]);
		if (it != remainRooms.end()) {
			//남아있는 방 중에 원하는 방이 있다면
			answer.push_back(*it);
			remainRooms.erase(it);
		}
		else {
			//방 안에 원하는 값이 없다면 맨앞꺼로다가 한다
			multiset<ll>::iterator lowerBountit = remainRooms.lower_bound(room_number[i]);
			//*rooms.begin(); 이건 왜 안됐을까? 나중에 찾아보기
			answer.push_back(*(lowerBountit));
			remainRooms.erase(lowerBountit);
		}
	}

	//for (int i = 0; i < answer.size(); i++) {
	//	cout << answer[i] << endl;
	//}

	return answer;
}
int main() {
	
	vector<ll> dd = { 1,3,4,3};
	solution(10, dd);

}




