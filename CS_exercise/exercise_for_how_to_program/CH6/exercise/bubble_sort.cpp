#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void swap( int *const, int *const);
void BubbleSort(int [], const int );
void Assignment(int [], const int );
void Output(const int [] ,const int );

int main()
{
    const int Array_Size = 15;
    srand(time(0));
    int target[Array_Size] = {
        0
    };
    Assignment( target , Array_Size );
    cout<<"Before Sorting: \n\n"<<endl;
    Output( target , Array_Size);
    BubbleSort( target , Array_Size );
    cout<<"After Sorting: \n\n"<<endl;
    Output( target , Array_Size );
}

void swap( int *const a, int *const b){
    int temp = *a;
    *a = *b ;
    *b = temp;
}

void Assignment(int Array[] , const int arraysize)
{
    for( int i = 0 ; i <arraysize ; i++)
        Array[ i ]  = rand()%1000;
}
void Output( const int Array[] , const int arraysize)
{
    for(int i = 0 ; i < arraysize; i++)
        cout<<setw(6)<<Array[i];
    cout<<endl;
}

void BubbleSort( int Array[] , const int size)
    {
        for(int i = 0 ; i < size-1 ; i++){
            for( int j = 0 ; j < size-1 ; j++){
                if( Array[ j ] < Array [ j + 1 ]){
                    swap( &Array[ j ] , &Array[ j + 1]);
                }
            }
        }
    }
