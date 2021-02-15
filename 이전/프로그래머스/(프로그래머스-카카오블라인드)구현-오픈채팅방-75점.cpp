#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<sstream>
using namespace std;

int main() {
	
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	vector<vector<string>> answers(record.size(),vector<string>(record.size()));

	int index = 0;
	for(int recordIndex=0; recordIndex<record.size(); recordIndex++){
		vector<string> cutString;
		istringstream iss(record[recordIndex]);
		string token;
		while (getline(iss, token, ' '))
		{
			cutString.push_back(token);
		}
		
		if (cutString[0] == "Enter") {
			for (int i = 0; i < answers.size(); i++) {
				if (cutString[1] == answers[i][1]) {
					answers[i][2] = cutString[2];
				}
			}
			answers[index][0] = "Enter";
			answers[index][1] = cutString[1];
			answers[index][2] = cutString[2];
			answers[index][3] = "님이 들어왔습니다.";
			index++;
		}
		else if (cutString[0] == "Leave") {
			answers[index][0] = "Leave";

			answers[index][1] = cutString[1];

			for (int i = 0; i < answers.size(); i++) {
				if (cutString[1] == answers[i][1]) { //uid와 같은 uid를가진사람의 닉네임을 가져올것
					cutString.push_back(answers[i][2]);
					break;
				}
			}

			answers[index][2] = cutString[2];
			answers[index][3] = "님이 나갔습니다.";
			index++;
		}
		else if (cutString[0] == "Change") {
			for (int i = 0; i < answers.size(); i++) {
				if (cutString[1] == answers[i][1]) { //uid가 같다면
					if (answers[i][0] == "Enter") { //입장메세지라면
						answers[i][2] = cutString[2];
						answers[i][3] = "님이 들어왔습니다.";
					}
					else { //나간메세지라면
						answers[i][2] = cutString[2];
						answers[i][3] = "님이 나갔습니다.";
					}
				}
			}
		}
	}
	vector<string> answer;
	for (int i = 0; i < answers.size(); i++) {
		if(answers[i][2] != "") answer.push_back(answers[i][2] + answers[i][3]);
	}
	cout << "사이즈?  : " << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
}