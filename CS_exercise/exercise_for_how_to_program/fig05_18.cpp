#include <iostream>
using namespace std;

int squareByValue(int);
void squareByReference( int &);

int main()
{
    int x=2;
    int z=4;
    cout<<"x = "<<x<<" before squareByValue\n";
    cout<<"Value returned by squareByValue: "<<squareByValue(x)<<endl;
    cout<<"x = "<<x<<" after squareByValue\n"<<endl;

    cout<<"z = "<<z<<" before squareByReference"<<endl;
    squareByReference( z );
    cout<<"z = "<<z<<" after squareByReference"<<endl;
}

int squareByValue(int x)
{
    x *= x;
    return x ;
}

void squareByReference(int &z)
{
    z *= z ;
}
