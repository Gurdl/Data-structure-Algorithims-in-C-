/*
   This function  is used to calculate infaltion after One year
//PRE-CONDITION:
The two arguments passed in function must not be negative and zero
 oldPrice>0 and currentPrice>0
//POST-CONDITIION:
This function will return a double value
*/
//I just added a new comment here,Hope it will be helpful for you.
#include<iomanip>
using namespace std;
double calculateInflation(double oldPrice,double currentPrice)
{
    double finalValue;
    finalValue=((currentPrice-oldPrice)/oldPrice)*100;
    return finalValue;
}
