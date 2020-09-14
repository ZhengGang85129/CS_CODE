
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
int whatIsThis( int [] , int );
int main()
{
    const int arraySize = 10;
    int a[ arraySize ] = {
        1 , 2 , 3 , 4 ,5 , 6, 7 , 8 , 9 , 10
    };
    int result = whatIsThis( a , arraySize);
    cout<<"result: "<<result<<endl;
}
int whatIsThis(int b[], int size){
    if (size == 1)
        return b[0];
    else
        return b[ size - 1] + whatIsThis( b , size - 1); 
}
