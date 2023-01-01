#include<iostream>
#include<iomanip>
#include"inflation.cpp"
using namespace::std;

int main()
{
    double oldValue;
    double currentValue;
    double num;
    bool repeat=true;
    const int DECIMAL_PLACES=2;
    do
    {
        cout<<"Please, enter price before One year :"<<endl;
        cin>>oldValue;
        //if price is negative or zero ,ask input again from user:
        if(oldValue<=0)
        {
            do{
                cout<<"Please, enter price before One year,it must be grater than 0 :"<<endl;
                cin>>oldValue;
            }while(oldValue<=0);

        }
        cout<<"Please, enter current price  :"<<endl;
        cin>>currentValue;
        //if price is negative or zero ,ask input again from user:
        if(currentValue<=0)
        {
            do{
                cout<<"Please, enter current price,it must be grater than 0 :"<<endl;
                cin>>currentValue;
            }while(currentValue<=0);

        }
        cout<<"The price before one year was :"<<oldValue<<"$  and current price is :"<<currentValue<<"$"<<endl;
        cout<<"So the inflation rate is :"<<fixed<<setprecision(DECIMAL_PLACES)<<calculateInflation(oldValue,currentValue)<<"%"<<endl;
        cout<<"To continue Press 1 otherwise press anyThing else to stop"<<endl;
        cin>>num;
        if(num!=1)
        {
            repeat=false;
            cout<<"---Program End-----";
        }
        
    }while(repeat);
    return 0;
}