#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
#define StoD(X)(X==0? 0:X-'0')
int n;
char problem[4][10002];
string answer[251];
void reverse(char *arr, int len) {
	char temp;
	for (int i = 0; i < len / 2; i++) {
		temp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = temp;
	}
}
string hiPlus(string  a, string b,string c) {
	strcpy(problem[0], a.c_str()); strcpy(problem[1], b.c_str()); strcpy(problem[2], c.c_str());
	int len, up = 0;
	len = max(max(strlen(problem[0]), strlen(problem[1])), strlen(problem[2]));
	reverse(problem[0], strlen(problem[0])); reverse(problem[1], strlen(problem[1])); reverse(problem[2], strlen(problem[2]));
	for (int i = 0; i <= len; i++) {
		problem[3][i] = (StoD(problem[0][i]) + StoD(problem[1][i])+ StoD(problem[2][i]) + up) % 10 + '0';
		if (i == len && up >=1) break;
		int hi = (StoD(problem[0][i]) + StoD(problem[1][i]) + StoD(problem[2][i])) + up;
		if (hi > 9 && hi<20) up = 1;
		else if (hi >= 20 && hi < 30)up = 2;
		else if (hi >= 30 && hi < 40)up = 3;
		else if (hi >= 40 && hi < 50)up = 4;
		else if (hi >= 50 && hi < 60)up = 5;
		else if (hi >= 60 && hi < 70)up = 6;
		else if (hi >= 70 && hi < 80)up = 7;
		else if (hi >= 80 && hi < 90)up = 8;
		else if (hi >= 90 && hi < 100)up = 9;
		else up = 0;
	}
	if (up >=1)len++;
	if (problem[3][len] == '0') problem[3][len] = 0;
	reverse(problem[3], strlen(problem[3]));
	
	return problem[3];
}
int main() {
	cin >> n;
	answer[0] = '1'; answer[1] = '1'; answer[2] = '3';

	for (int i = 3; i <= n; i++) {
		answer[i] = hiPlus(answer[i - 1], answer[i - 2], answer[i - 2]);
		memset(problem, '0', sizeof(problem));
	}
	cout << answer[n] << endl;

}