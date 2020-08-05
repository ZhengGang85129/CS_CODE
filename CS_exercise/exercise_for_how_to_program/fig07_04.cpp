#include <iostream>
using namespace std;

int main()
{
    int a;
    int *aPtr;

    a = 7;
    aPtr = &a;

    cout<<"The address of a is: "
        <<&a<<endl;
    cout<<"value of Ptr is: "
        <<aPtr;
    cout<<"\n\nShowing that * and & are inverses of "
        <<"each other.\n&*aPtr = "<<&*aPtr
        <<"\n*&aPtr = "<<*&aPtr<<endl;
}
