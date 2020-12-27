#include <iostream>
using namespace std;
void binary(int num)
{
	int x[10], i, temp = num;
	cout << "\t\t";
	for (i = 0; num > 0; i++)
	{
		x[i] = num % 2;
		num = num / 2;
	}
	if (temp == 0)
	{
		cout << "0";
	}
	for (i = i - 1; i >= 0; i--)
	{
		cout << x[i];
	}
}

void hexadecimal(int decimal)
{
	int temp, remainder;
	string hexanum = "";
	char hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	temp = decimal;
	if (temp == 0)
	{
		hexanum = "0";
	}
	while (temp > 0)
	{
		remainder= temp % 16;
		hexanum = hex[remainder] + hexanum;
		temp = temp / 16;
	}
	cout << "          \t\t";
	cout << hexanum << endl;

}

int main()
{
	cout << "Decimal(base 10)\tBinary (base 2)\t\tHexadecimal (base 16)" << endl;
	for (int i = 0; i <= 256; i++)
	{
		cout << "\t";
		cout << i;
		binary(i);
		hexadecimal(i);
	}
	
}