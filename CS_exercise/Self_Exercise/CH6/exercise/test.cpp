#include <iostream>
#include <iomanip>
using namespace std;
const int size = 3;
void print( const int [][size] ,const int ,const int );
int main()
{
    int a[ size ][ size ] = {
        {
            1 , 2 , 3 
        },
        {
            4 , 5 , 6
        },
        {
            7 , 8 , 9
        }
    };

    print( a , size - 1  , size - 1 );
}

void print( const int arr [][size] , const int s1 ,const int s2){
    if ( s1 > 0 || s2 > 0 ){
    print(arr , s1 , s2 - 1 );
    print(arr , s1 - 1 , s2 );

    }

    cout<<arr[ s1 ][ s2 ]<<setw(5)<<endl;
}

