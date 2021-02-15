#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<vector<string>> cutString(record.size());
	map<string, string> hello;
	for (int recordIndex = 0; recordIndex < (int) record.size(); recordIndex++) {
		istringstream iss(record[recordIndex]);
		string token;
		while (getline(iss, token, ' '))
		{
			cutString[recordIndex].push_back(token);
		}
	}
	for (int i = 0; i < (int)record.size(); i++) {
		if (cutString[i][0] == "Enter") {
			//들어왔을때 출력해야할 횟수증가 
			//닉네임을 바꿔서 들어올 수도 있으므로 value값 수정
			hello[cutString[i][1]] = cutString[i][2];
		}
		else if (cutString[i][0] == "Change") {
			hello[cutString[i][1]] = cutString[i][2];
		}
	}
	vector<string> answer;
	for (int i = 0; i <(int)record.size(); i++) {
		if (cutString[i][0] == "Change") continue; //change건너뜀
		else if (cutString[i][0] == "Enter") {
			answer.push_back(hello[cutString[i][1]] + "님이 들어왔습니다.");
		}
		else if (cutString[i][0] == "Leave") {
			answer.push_back(hello[cutString[i][1]] + "님이 나갔습니다.");
		}
	}
	return answer;
}
int main() {

	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan","Leave uid1234" };
	vector<string> answer = solution(record);
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}

