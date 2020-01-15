//compile used : g++ compiler 
//Sourabh Mahesh 

#include<iostream>
#include<string>
#include<math.h>
using namespace std;


//Constraint:
// BaseX <= Base36
// BaseY <= Base36


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
int main()
{
	string number;
	int base_x, base_y;
	
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

	conversion(number,base_x,base_y);

	cin.ignore();
	cin.get();
	
	return 0;
}
/*for (i = 7; i >= 0; --i)
		((num >> i) & 1) ? cout << "1" : cout << "0";
	*/
