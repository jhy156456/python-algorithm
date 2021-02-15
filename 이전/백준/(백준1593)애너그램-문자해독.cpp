#include<iostream>
#include<cstring> 
using namespace std;
#define MAX 256 
// This function returns true if contents of arr1[] and arr2[] 
// are same, otherwise false. 
bool compare(int arr1[], int arr2[])
{
	for (int i = 0; i < MAX; i++)
		if (arr1[i] != arr2[i])
			return false;
	return true;
}
int result = 0;
/* Driver program to test above function */
int main(){
	int M, N;
	string text, pat;
	cin >> M >> N;
	cin >> pat >> text;
	// countP[]:  Store count of all characters of pattern 
	// countTW[]: Store count of current window of text 
	int countP[MAX] = { 0 }, countTW[MAX] = { 0 };
	for (int i = 0; i < M; i++)
	{
		(countP[pat[i]-'A'])++;
		(countTW[text[i]-'A'])++;
	}

	// Traverse through remaining characters of pattern 
	for (int i = M; i < N; i++)
	{
		// Compare counts of current window of text with 
		// counts of pattern[] 
		if (compare(countP, countTW))
			result++;
		// Add current character to current window 
		countTW[text[i] - 'A']++;
		// Remove the first character of previous window 
		countTW[text[i - M] - 'A']--;
	}
	// Check for the last window in text 
	if (compare(countP, countTW))
		result++;
	cout << result << endl;
	return 0;
}