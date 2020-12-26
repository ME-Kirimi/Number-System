#include <iostream>
#include <iomanip>
#include <math.h>
#include <bitset>
using namespace std;

void mapnum(int number)
{
    int a[32],i;
    for(i=0; number>0; i++)
    {
        a[i]=number%2;
        number = number/2;
    }
    cout<<"\t\t";
    for(i=i-1 ;i>=0 ;i--)
    {
        cout<<a[i];
    }
    cout<<".";
}
void floatnum(double decimal)
{
    string binary = "";
    string remark = "";
    int counter = 0;
    while(counter < 6)
    {
        if(decimal == 0.0)
        {
           remark = "Exactly";
           break;
        }
        else
        {
            decimal = decimal * 2;
            int fract_bit = decimal;
            if(fract_bit == 1)
            {
                decimal = decimal - fract_bit;
                binary.push_back(1 + '0');
            }
            else
            {
                binary.push_back(0 + '0');
            }
            remark = "Approximately";
        }
        counter ++;
    }
    cout<<binary<<"       \t";
    cout<<remark;
    cout<<endl;
}
int main()
{
    //Generate random decimal float
    srand(time(NULL));
    const unsigned int size_Array = 30;
    float decValues [size_Array];
    cout<<"Decimal values  \t\t  Binary values \t\t  Remarks"<<endl;
    for (int i=0; i<size_Array; i++)
    {
        cout<<i+1<<". ";
        decValues[i] = ((float)rand()/(float)RAND_MAX) * 500;
        cout<<fixed;
        cout<<setprecision(3)<<decValues[i];
        int intnum = decValues[i];
        double decnum = decValues[i] -intnum;
        //Convert integer part of the decimal float to binary
        mapnum(intnum);
        //Convert float part of the decimal float to binary
        floatnum(decnum);
    }
    return 0;
}