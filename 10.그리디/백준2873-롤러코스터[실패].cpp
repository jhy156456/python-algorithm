#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
int r, c;
vvi problems;
priority_queue <iii> pq;
vector<int> resultsValue;
string firstDown(int startY,int startX,int endY,int endX) {
	string result = "";
	int sum = 0;
	for (int i = startX; i < endX; i++) {
		for (int j = startY; j < endY; j++) {
			sum += problems[j][i];
			if (j == endY - 1) continue;
			if (r % 2 == 0 && c % 2 == 0) {
				if (i % 2 != 0) {
					//r,c 둘다 짝수이면 로직을 반대로 태워야 한다..
					result += "D";
				}
				else {
					result += "U";
				}
			}
			else {
				if (i % 2 == 0) {
					result += "D";
				}
				else {
					result += "U";
				}
			}


		}
		result += "R";
	}
	resultsValue.push_back(sum);
	return result.substr(0, result.length() - 1);
}
string firstRight(int startY,int startX,int endY,int endX) {
	string result = "";
	int sum = 0;
	for (int i = startY; i < endY; i++) {
		for (int j = startX; j < endX; j++) {
			sum += problems[i][j];
			if (j == endX - 1) continue;
			if (r % 2 == 0 && c % 2 == 0) {
				if (i % 2 != 0) {
					//r,c 둘다 짝수이면 로직을 반대로 태워야 한다..
					result += "R";
				}
				else {
					result += "L";
				}
			}
			else {
				if (i % 2 == 0) {
					result += "R";
				}
				else {
					result += "L";
				}
			}
		}
		result += "D";
	}
	resultsValue.push_back(sum);
	return  result.substr(0, result.length() - 1);
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int main() {
	cin >> r>>c;
	problems = vvi(r, vi(c, 0));
	int sum = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++) {
			int a;
			cin >> a;
			sum += a;
			problems[i][j] = a;
		}
	}
	string result = "";
	if (r % 2 != 0) {
		//행이 홀수이면 행렬 전부 탐색이 가능하므로 우측으로 시작해서 전부 탐색한다
		result = firstRight(0,0,r,c);
	}
	else if(c%2!=0){
		//열이 홀수이면
		result = firstDown(0,0,r,c);
	}
	else {
		vector <string> stringResults;

		stringResults.push_back("D" + firstRight(1, 0, r, c));
		resultsValue[0] += problems[0][0];
		stringResults.push_back("R" + firstDown(0, 1, r, c));
		resultsValue[1] += problems[0][0];
		stringResults.push_back(firstDown(0, 0, r, c-1) + "R");
		resultsValue[2] += problems[r-1][c-2];
		stringResults.push_back(firstRight(0, 0, r-1, c)+"D");
		resultsValue[3] += problems[r-2][c-1];


		int max = 0;
		for (int i = 0; i < 4; i++) {
			if (max < resultsValue[i]) {
				max = resultsValue[i];
				result = stringResults[i];
			}
		}
	}
	cout << result << endl;

}