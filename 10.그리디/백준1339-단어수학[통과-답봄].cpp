#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <numeric>
using namespace std;
typedef long long ll;
typedef int i;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<string> vs; typedef vector<bool> vb;	
typedef pair<string, int> si;
typedef vector<vi> vvi;
typedef pair<string, string> ss;
typedef vector<ii> vii;

int n;
vs problems;
vi numberProblems(30,0);
vii charNumbers(30,ii(0,0));

int main(){
	cin >> n;
	int maxLength = 0;
	for (int i = 0; i < 30; i++) {
		charNumbers[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a; 
		for (int j = 0; j < a.length(); j++) {
			charNumbers[a[j]-'A'].first += pow(10, a.length() - 1 - j);
		}
		problems.push_back(a);
	}
	sort(charNumbers.begin(), charNumbers.end());
	int number = 9;
	for (int i = 29; i >= 0; i--) {
		//각 문자 인덱스에 맞는 숫자(9,8,7...)를 할당한다
		if (charNumbers[i].first == 0)break;
		numberProblems[charNumbers[i].second] = number;
		number--;
	}
	vi myNumbers;
	for (int i = 0; i < n; i++) {
		string indexString = problems[i];
		string hi = "";
		for (int j = 0; j < indexString.length(); j++) {
			hi += to_string(numberProblems[indexString[j] - 'A']);
		}
		myNumbers.push_back(stoi(hi));
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += myNumbers[i];
	}
	cout << sum<< endl;


}