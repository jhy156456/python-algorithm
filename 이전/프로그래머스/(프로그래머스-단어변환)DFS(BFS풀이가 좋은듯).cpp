#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;
vector<string> mWords;
vector<int>visited;
int wordsSize = 0;
int eachWordSize = 0;
int minDepth = 1000000000;
int getOneWord(int wordIndex) { //현재의 워드인덱스
	int returnIndex = -1;
	for (int i = 0; i < wordsSize; i++) {
		if (!visited[i]) { //방문한곳이아니라면 단어가 1개차이나는지 검사해본다
			vector<int> zeroCount;
			for (int j = 0; j < eachWordSize; j++) {
				zeroCount.push_back((mWords[wordIndex].at(j) - 'a') - (mWords[i].at(j) - 'a'));
			}
			int nonZeroNumber = 0;
			for (int k = 0; k < (int)zeroCount.size(); k++) {
				if (zeroCount[k] != 0)nonZeroNumber++;
			}
			if (nonZeroNumber == 1) {
				return i;
			}
			
		}
	}
	return -1;
}
void dfs(int here,int depth) {

	visited[here] = true;
	if (mWords[here] == mWords[mWords.size() - 1]) { 
		visited[here] = false;
		if (minDepth > depth) {
			minDepth = depth;
		}
		return;
	}
	for (int i = 0; i < (int)mWords.size(); i++) {
		if (!visited[i]) { 
			int there = getOneWord(here);
			if (there == -1) return;
			cout << "here : " << here << endl;
			cout << "there : " << there << endl;
			visited[there] = true;
			dfs(there, depth + 1);
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	int hi =0;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == target)  hi = 1;
	}
	if (hi != 1) return 0;
	mWords = words;
	
	visited = vector<int>(words.size()+2,0);
	wordsSize = words.size();
	eachWordSize = words[0].size();
	mWords.push_back(begin);//mWords.size()-2, 
	mWords.push_back(target);//mWords.size()-1
	int firstVisit = getOneWord(mWords.size() - 2);
	dfs(firstVisit,1);
	int answer = minDepth;
	return answer;
}
int main() {

	int answer = solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });

	cout << answer << endl;
}