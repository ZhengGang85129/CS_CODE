#include <iostream>
#include "fig05_25.h"
using namespace std;

int main()
{
    int int1,int2,int3;
    cout<<"Input three integer values: ";
    cin>>int1>>int2>>int3;
    
    cout<<"The maximum int value is : ";
    cout<<maximum(int1,int2,int3)<<endl;;
    double double1,double2,double3;
    cout<<"Input three double values: ";
    cin>>double1>>double2>>double3;

    cout<<"The maximum double value is : ";
    cout<<maximum(double1,double2,double3);
}
