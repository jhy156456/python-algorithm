#include <iostream>
#include <string>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
map<ii, int>check,problem1,problem2;
int str1Size, str2Size;
int solution(string str1, string str2) {
	for (int i = 0; i < (int)str1.size() - 1; i++) {
		int a = -1, b = -1;
		//첫번째글자
		if (str1[i] >= 'a'&&str1[i] <= 'z') {
			a = str1[i] - 'a';
		}
		else if (str1[i] >= 'A'&&str1[i] <= 'Z') {
			a = str1[i] - 'A';
		}
		//두번째글자
		if (str1[i + 1] >= 'a'&&str1[i + 1] <= 'z') {
			b = str1[i + 1] - 'a';
		}
		else if (str1[i + 1] >= 'A'&&str1[i + 1] <= 'Z') {
			b = str1[i + 1] - 'A';
		}
		if (a != -1 && b != -1) {
			problem1[{ ii(a, b )}]++;
			str1Size++;
		}
	}
	for (int i = 0; i < (int)str2.size() - 1; i++) {
		//첫번째글자
		int a = -1, b = -1;
		if (str2[i] >= 'a'&&str2[i] <= 'z') {
			a = str2[i] - 'a';
		}
		else if (str2[i] >= 'A'&&str2[i] <= 'Z') {
			a = str2[i] - 'A';
		}
		//두번째글자
		if (str2[i + 1] >= 'a'&&str2[i + 1] <= 'z') {
			b = str2[i + 1] - 'a';
		}
		else if (str2[i + 1] >= 'A'&&str2[i + 1] <= 'Z') {
			b = str2[i + 1] - 'A';
		}
		if (a != -1 && b != -1) {
			problem2[{ ii(a, b)}]++;
			str2Size++;
		}
	}
	map< ii, int >::iterator Iter_Pos;
	int kyo = 0;
	for (Iter_Pos = problem1.begin(); Iter_Pos != problem1.end(); ++Iter_Pos){
		if (problem2.find(Iter_Pos->first) != problem2.end()) {
			if (Iter_Pos->second < problem2.find(Iter_Pos->first)->second) {
				kyo += Iter_Pos->second;
			}
			else if (Iter_Pos->second > problem2.find(Iter_Pos->first)->second) {
				kyo += problem2.find(Iter_Pos->first)->second;
			}
			else {
				kyo += Iter_Pos->second;
			}
		}
	}
	
	int hapSize = str1Size+str2Size - kyo;
	if (hapSize == 0 && kyo == 0) return 65536;
	else return kyo * 65536 / hapSize;
}
int main() {
	cout<<solu
}