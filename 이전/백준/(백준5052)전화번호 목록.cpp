#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


vector<string> phone;
int N;
int main() {


	int T;
	cin >> T;
	while (T--) {
		string tmp;
		cin >> N;
		phone = vector<string>(N);
		for (int i = 0; i < N; i++) {
			cin >> phone[i];
		}
		sort(phone.begin(), phone.end());
		bool Answer = true;
		for (int i = 1; i < N; i++) {
			string a = phone[i - 1]; //string &a = 과 string a= 의 차이는 모르겠다
			string b = phone[i];
			if (a.size() > b.size()) continue;
			/*
			정렬이 완료되고 
			1234
			13
			이런건 비교할 필요없이 다음항으로 넘어가야하므로
			사이즈조사를해줘서 다음 for문으로 넘어가게한다.
			*/
			if (a == b.substr(0, a.size())) { //같은 문자열인지 ==로 비교한다
				Answer = false;
			}
		}
		cout << (Answer ? "YES" : "NO");
		cout << endl;
	}


}