#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
const int N = 50;
void selection_sort( int [] , const int , const int );
void Output(const int [] ,const int );
void Find_min(const int [] , const int , const int , int & , int &);

int series[ N ] = {0};
int main()
{
  srand(time(0));
  for( int i = 0 ; i < N ; i++)
      series[ i ] = rand()% 1000;
  Output( series , N );
  int init = 0 ;
  selection_sort( series , N , init );
  Output( series , N );
  return -1 ;
}


void Output( const int Array[] , const int arraysize)
    {
        for(int i = 0 ; i < arraysize; i++)
            cout<<setw(6)<<Array[i];
        cout<<endl;

    }
void selection_sort( int arr[] , const int size , const int Init_pos )
{
    if( Init_pos != size - 1){
        int Min = 10000000;
        int Min_pos = Init_pos ;
        Find_min( arr , size , Init_pos , Min_pos , Min );
        int tmp = arr[ Init_pos ];
        arr[ Init_pos ] = arr[ Min_pos ];
        arr[ Min_pos ] = tmp ;
        selection_sort( arr , size  , Init_pos + 1 );
    }
}
void Find_min(const int Array[] , const int Size , const int pos , int &min_pos , int &min )
{
    if( pos != Size   )
    {
        if(min > Array[ pos ] )
        {
            min = Array[ pos ] ;
            min_pos = pos ;
        }
        Find_min( Array , Size , pos + 1 ,min_pos ,  min );
    }

}
