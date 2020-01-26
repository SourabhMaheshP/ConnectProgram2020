//compiler used : g++ compiler 
//Sourabh Mahesh Pankhawala

#include<iostream>
#include<string>
#include<math.h>
using namespace std;


//Constraint:
// BaseX <= Base36
// BaseY <= Base36

//this function is used for computation and printing values to the console.
//this function is recursive.
//Example if input: 26 Base_x = 10 Base_y = 16 then ordinary computation gives output as: "A1" 
//but this function outputs require "actual" output as reverse: "1A"

void compute(int num, int y, int res)
{
	if (num == 0 && res == 0)
		return;
	compute(num / y, y, num % y);
	if (res >= 0 && res <= 9)
		cout << res << " ";
	else if (res >= 10 && res <= 36)
		cout << (char)(res + 55) << " ";
}

//function for conversion 
void conversion(string str, int x, int y)
{
	int i=0,num = 0, res = -1,j=0;
	//1. string to integer 2. change any base x to Decimal
	for (i = str.length()-1,j=0 ; i >= 0 ; --i,++j) 
	{
		if (str[i] >= '0' && str[i] <= '9')
			num += (pow(x, j) * (str[i] - '0'));
		else if (str[i] >= 'A' && str[i] <= 'Z')
			num += (pow(x, j) * (str[i] - 55));
	}	 
               	
	//3. Decimal to Base Y
	if (y != 10)          //because num is decimal 
		compute(num, y, res);
	else
		cout << num << endl;
}

//This function will check if the given inputs are valid for conversion.
int validate(string str, int x)
{
	
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= '0' && str[i] <= '9')) 
		{
			if ((str[i] - '0') >= x)
				return true;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
				if ((str[i] - 55) >= x)
					return true;
	}
	return false;
}
//Driver Code
int main()
{
	string number;
	int base_x, base_y;
	
	//Required inputs 
	cout << "Enter Number " << endl;
	getline(cin, number);
	do {
		cout << "Enter Base X:" << endl;
		cin >> base_x;
		if (validate(number, base_x))
			cout << "Incorrect Base X!!!" << endl;
	} while (validate(number, base_x) || base_x < 2);
	
	do {
		cout << "Enter Base Y:" << endl;
		cin >> base_y;
		if (base_y < 2)
			cout << "Incorrect Base Y!!" << endl;
	} while (base_y < 2);

	//This function will convert a given input to any base
	conversion(number,base_x,base_y);
	
	//to hault the command prompt for a character input.
	cin.ignore();
	cin.get();
	
	return 0;
}
//Code snippet for conversion to Binary (using bitwise operator)- for optimization purpose.
/*for (i = 7; i >= 0; --i)
		((num >> i) & 1) ? cout << "1" : cout << "0";
	*/
