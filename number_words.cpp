//Compiler Used: g++
//Sourabh Mahesh Pankhawala

//Program: to convert a given number to its appropriate word representation.

//constraints: number <= 10^18 (shankh)

#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

//constants
const char *ones[] = {"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ",
"Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen " };
const char *tens[] = { "","","Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety " };
const char *high[] = {"","","","Hundred ","Thousand ","","Lakh ","","Crore ","","Arab ",
"","Kharab ","","Neel ","","Padma ","","Shankh ",""};


void init(string &num)
{
	if (num.length() % 2 == 0) //Ex. thousand --> ten thousand 4500 to 04500
		num.insert(0, "0");
}

//for printing two digit number to its appropriate word.
void twoDigit(string digits)
{
	if ((stoi(digits) / 10) > 1)
		cout << tens[stoi(digits) / 10] << ones[stoi(digits) % 10];
	else
		cout << ones[stoi(digits)];
}
//Main function to print number -> words.

void print(string digits,int len)
{
	if (len != 3)
		twoDigit(digits);
	else
	{
		if (strcmp(ones[stoi(digits) / 100], ""))
			cout << ones[stoi(digits) / 100] << high[3];
		twoDigit(digits.substr(1, len));
	}

	if (len > 3 && stoi(digits))
		cout << high[len - 1];
}

void conversion(string num)   
{
	for (int i = 0;;i+=2)
	{
		if (num.length() - i > 3){
			print(num.substr(i, 2), num.length() - i);
		}
		else 
		{
			print(num.substr(i, num.length()), num.length() - i);	
			break;
		}
	}
}
int checkZero(string num)
{
	for (int i = 0; num[i]; i++)
		if (num[i] != '0')
			return 0;
	return 1;
}
//Driver code.
int main()
{
	string number;
	cout << "Enter Number: " << endl;
	cin >> number;
	
	init(number);
	if (checkZero(number))
		cout << "Zero";
	else
		conversion(number);
	cin.ignore();
	cin.get();

	return 0;
}
