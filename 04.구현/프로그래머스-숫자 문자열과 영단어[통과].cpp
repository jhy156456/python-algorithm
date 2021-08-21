#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#include<sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> si;
typedef vector<vi> vvi;
typedef vector<vector<int>> vvi;
vvi graph;
int n;
string convertEnglishToNumber(string s) {
	if (s == "zero") {
		return "0";
	}
	else if (s == "one") {
		return "1";
	}
	else if (s == "two") {
		return "2";
	}
	else if (s == "three") {
		return "3";
	}
	else if (s == "four") {
		return "4";
	}
	else if (s == "five") {
		return "5";
	}
	else if (s == "six") {
		return "6";
	}
	else if (s == "seven") {
		return "7";
	}
	else if (s == "eight") {
		return "8";
	}
	else if (s == "nine") {
		return "9";
	}
	else {
		return "-1";
	}
}
int solution(string s) {
	int answer = 0;

	string strAnswer = "";
	string number = "";
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		
		if (isdigit(c) == 0) {
			//숫자가 아니다
			//sixseven 이면?
			string convertString = convertEnglishToNumber(number) ;
			if (convertString == "-1") {
				//convertEnglishToNumber(number)=="-1" -> 여태 쌓은게 변환이 가능 하지 않으면
				//문자열을 더 쌓아나간다.
				number += c;
				continue;
			}
			else if(number.size() > 0){
				//여태 쌓은게 변환이 가능한다면
				strAnswer += convertString;
				number = "";
				number += c;
				continue;
			}
			
		}else if (number.size() > 0) {
			//숫자다
			strAnswer += convertEnglishToNumber(number);
			number = "";
		}
		strAnswer += s[i];
		
	}
	if (number.size() > 0) {
		strAnswer += convertEnglishToNumber(number);
	}
	return stoi(strAnswer);
}
int main()
{
	cout << solution("2three45sixseven") << endl;;
}