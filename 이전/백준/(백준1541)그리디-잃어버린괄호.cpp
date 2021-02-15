#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<char> vs;
using namespace std;
vi number;
vs kiho;
int main() {
	string math;
	cin >> math;
	string myNumber = "";
	for (int i = 0; i < (int)math.size(); i++) {
		if (math[i] != '-' && math[i] != '+') {
			myNumber.push_back(math[i]);
		}
		else {
			kiho.push_back(math[i]);
			number.push_back(stoi(myNumber));
			myNumber = "";
		}
	}
	number.push_back(stoi(myNumber));
	int answer = 0;
	int i = 0;
	for (i = 0; i < (int)kiho.size(); i++) {
		if (kiho[i] == '-') {
			answer += number[i];
			int j = 0;
			for (j = i + 1; j < (int)kiho.size(); j++) {
				answer -= number[j];
			}
			answer -= number[j];
			break;
		}
		else {
			answer += number[i];
		}
	}
	if (i == (int)kiho.size()) answer += number[i];
	cout << answer << endl;

}