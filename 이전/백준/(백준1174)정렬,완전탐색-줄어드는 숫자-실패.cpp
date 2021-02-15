#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>
#include<string>
using namespace std;
int n;
vector<int> problems(100001);
void divideCipher(int number) {

}
int main() {
	cin >> n;

	int number = 9, nCount = 10;

	
	if (n <= number+1) {
		cout << n -1 << endl;
		return 0;
	}
	int prevNumber = 0;

	while (true&&nCount!=n ) {
		bool isDown = false;
		prevNumber = ++number;
		while (number != 0) {
			int prev = number % 10;
			number /= 10;
			int now = number % 10;
			if (prev < now) {
				isDown = true;
			}
			else {
				if (number == 0) {
					isDown = true;
				}
				else {
					isDown = false;
				}
				break;
			}
		}
		if (isDown == true) {
			problems[nCount] = prevNumber;
			nCount++;
		}
		number = prevNumber;
	}

	cout << problems[n-1] << endl;

}
