#include<iostream>
#include <algorithm>
#include <string>
#include<vector>
using namespace std;
typedef pair<int, int> ii;
int n, p;
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

	bool exitWhile = true;
	int startIndex = 0;
	vector<int> answer;
	while (startIndex !=(int)progresses.size()) {
		bool goBaePo = false;
		int baePoCount = 0;
		progresses[startIndex] += speeds[startIndex];
		if (progresses[startIndex] >= 100) {
			baePoCount++;
			goBaePo = true;
		}
		for (int i = startIndex+1; i < (int)progresses.size(); i++) {
			progresses[i] += speeds[i];
			if (progresses[i] >= 100 && goBaePo==true) {
				baePoCount++;
			}
			else {
				goBaePo = false;
			}
		}
		if (baePoCount) {
			answer.push_back(baePoCount);
		}
		startIndex += baePoCount;
		baePoCount = 0;
		
	}
	return answer;
}

int main() {
	vector<int> answer = solution({ 93,30,55 }, { 1,30,5 });
	for (int i = 0; i < (int)answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
	
}