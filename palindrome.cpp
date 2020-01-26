
//Program: to check if given input is palindrome or not.

#include<iostream>
#include<string>
using namespace std;

//function returns boolean(t/f) based on, if input is palindrome or not.
bool check_palindrome(const string& input)
{
	for (int i = 0,j=input.length()-1 ; i<j ; ++i,--j)
		if (input[i] != input[j])
			return false;
	return true;
}

//Driver code
int main()
{
	string input;
	do {
		getline(cin, input);
		if (input.empty())
			cout << "Input cannot be empty, Enter again!!: ";
	} while (input.empty());
	
	check_palindrome(input) ? cout << "It's a palindrome!" : cout << "Sorry, not a palindrome!";

	cin.ignore();
	cin.get();
	return 0;
}