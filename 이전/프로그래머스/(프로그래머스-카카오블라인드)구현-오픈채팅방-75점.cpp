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
			answers[index][3] = "���� ���Խ��ϴ�.";
			index++;
		}
		else if (cutString[0] == "Leave") {
			answers[index][0] = "Leave";

			answers[index][1] = cutString[1];

			for (int i = 0; i < answers.size(); i++) {
				if (cutString[1] == answers[i][1]) { //uid�� ���� uid����������� �г����� �����ð�
					cutString.push_back(answers[i][2]);
					break;
				}
			}

			answers[index][2] = cutString[2];
			answers[index][3] = "���� �������ϴ�.";
			index++;
		}
		else if (cutString[0] == "Change") {
			for (int i = 0; i < answers.size(); i++) {
				if (cutString[1] == answers[i][1]) { //uid�� ���ٸ�
					if (answers[i][0] == "Enter") { //����޼������
						answers[i][2] = cutString[2];
						answers[i][3] = "���� ���Խ��ϴ�.";
					}
					else { //�����޼������
						answers[i][2] = cutString[2];
						answers[i][3] = "���� �������ϴ�.";
					}
				}
			}
		}
	}
	vector<string> answer;
	for (int i = 0; i < answers.size(); i++) {
		if(answers[i][2] != "") answer.push_back(answers[i][2] + answers[i][3]);
	}
	cout << "������?  : " << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
}