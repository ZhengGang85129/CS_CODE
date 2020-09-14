#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
const int N = 10;

int Array[ N ] = {0};

void Init_Arr(int [] ,const int , int );
int Linear_Search( const int [] , const int , const int , const int );
void Output( const int [] , const int , int );


int main()
{
    srand(time(0));
    Init_Arr( Array , N , 0 );
    Output( Array , N , 0 );
    int KEY , Init = 0;
    cout<<"\n\nInput the key: ";
    cin>>KEY;
    cout<<"\nThe key subscript is : "<<Linear_Search( Array , N , Init , KEY )<<endl;
}

void Init_Arr( int arr[ ] , const int size , int pos )
{
    if(pos < size )
    {
        arr[ pos ] = rand()%2000;
        Init_Arr( arr , size , pos + 1 );
    }
}

int Linear_Search( const int arr[ ] , const int size , const int pos , const int key )
{
    if( pos < size )
    {
        if(arr[ pos ] == key)
            return pos ; 
        else 
            return Linear_Search(arr , size , pos + 1 , key) ; 
    }
    else 
        return -1 ;
}
void Output( const int arr[ ] , const int size , int pos)
{
    if( pos != size )
    {
        cout<<arr[ pos ]<<" ";
        Output( arr , size , pos + 1 );
    }
}
