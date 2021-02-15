#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>ii;
typedef pair<ii, int>iii;

struct Person {
	int y, x, arrivalTime,selectStair;
};
bool cmp(Person a, Person b) {
	if (a.arrivalTime < b.arrivalTime)return true;
	else return false;
}
int t, n, personCount, result;
vector<int> stairAorB[2];
vector<iii> stair;
vector<Person>person;
void r(int personNumber) {
	//기저사례
	if (personNumber == personCount) {
		stairAorB[0].assign(3, 0); stairAorB[1].assign(3, 0);
		//도착시간 계산
		vector<Person> tempPerson(personCount);
		for (int i = 0; i < (int)person.size(); i++) {
			person[i].arrivalTime = abs(person[i].y - stair[person[i].selectStair].first.first)
				+ abs(person[i].x - stair[person[i].selectStair].first.second);

			tempPerson[i] = person[i];
		}
		//도착시간순으로 오름차순 정렬
		sort(tempPerson.begin(), tempPerson.end(), cmp);

		for (int i = 0; i < (int)tempPerson.size(); i++) {
			int min = 9999999;
			int stairIndex = 0;
			for (int j = 0; j < 3; j++) {
				if (stairAorB[tempPerson[i].selectStair][j] < min) {
					stairIndex = j;
					min = stairAorB[tempPerson[i].selectStair][j];
				}
			}
			if (tempPerson[i].arrivalTime >= min) {
				stairAorB[tempPerson[i].selectStair][stairIndex]
					= tempPerson[i].arrivalTime+ 1 + stair[tempPerson[i].selectStair].second;
			}
			else {
				stairAorB[tempPerson[i].selectStair][stairIndex]
					= stairAorB[tempPerson[i].selectStair][stairIndex] +
					stair[tempPerson[i].selectStair].second;
			}
		}

		int max = 0;
		for (int i = 0; i < 3; i++) {
			if (max < stairAorB[0][i])max = stairAorB[0][i];
		}
		for (int i = 0; i < 3; i++) {
			if (max < stairAorB[1][i])max = stairAorB[1][i];
		}
		if (result > max) {
			result = max;
			//cout << "-------------" << endl;
			//for (int i = 0; i < 6; i++) {
			//	cout << person[i].selectStair << " " << person[i].arrivalTime << endl;
			//}
			//cout << "-------------" << endl;
			//for (int i = 0; i < 3; i++) {
			//	cout << stairAorB[0][i] << " ";
			//}
			//cout << "-------------" << endl;
			//for (int i = 0; i < 3; i++) {
			//	cout << stairAorB[1][i] << " ";
			//}
			//cout << "-------------" << endl;
		}
		return;
	}
	person[personNumber].selectStair = 0;
	r(personNumber + 1);
	person[personNumber].selectStair = 1;
	r(personNumber + 1);
}
int main() {
	cin >> t;
	for (int a = 1; a <= t; a++) {
		cin >> n;
		
		result = 100000;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int d;
				cin >> d;
				if (d != 0 && d != 1) {
					stair.push_back(iii(ii(i, j),d));
				}
				else if (d == 1) {
					personCount++;
					Person p;
					p.y = i;
					p.x = j;
					person.push_back(p);
				}
			}
		}
		person[0].selectStair = 0;
		r(1);
		person[0].selectStair = 1;
		r(1);
		stair.clear(); person.clear(); personCount = 0;
		cout << "#" << a << " " << result << endl;
	}
}