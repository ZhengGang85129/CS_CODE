#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int size; 
    cout<<"Please enter any odd number: \n";
    cin>>size;

    int control1 = (size+1)/2;
    for( int i = 0 ; i < control1 ; i++)
    {
        int ctr = 0;
        for(int j = 0; j < control1 - i; j++)
            cout<<" ";
        while( ctr < 2*i+1)
        {
            cout<<"*";
            ctr++;
        }cout<<"\n";

    }
    for( int i = control1-1   ; i >0 ; i--)
    {
        int ctr = 0;
        for(int j = 0; j <= control1 - i  ; j++)
            cout<<" ";
        while( ctr < 2*i-1){
            cout<<"*";
            ctr++;
        }
        cout<<"\n";

    }
}
