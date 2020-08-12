#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void BubbleSort(int [], const int );
void Assignment(int [], const int );
void Output(const int [] ,const int );

int main()
{
    const int Array_Size = 10;
    srand(time(0));
    int target[Array_Size] = {
       0
    };
    Assignment( target , Array_Size );
    cout<<"Before Sorting: \n\n";
    Output( target , Array_Size);
    BubbleSort( target , Array_Size );
    cout<<"After Sorting: \n\n";
    Output( target , Array_Size );
}
void Assignment(int Array[] , const int arraysize)
{
    for( int i = 0 ; i <arraysize ; i++)
        Array[ i ]  = rand()%50;
}
void Output( const int Array[] , const int arraysize)
{
    for(int i = 0 ; i < arraysize; i++)
        cout<<setw(6)<<Array[i];
    cout<<endl;
}

void BubbleSort( int Array[] , const int size)
{
    bool flag = true;
    int counter = 0;
    for( int i = 0 ; i < size-1 ; i++){
        if(flag)
        {
            int index = i;
            int temp = Array[ i ] ;
            for( int j = i ; j < size ; j++)
            {
                counter  = size - i;
                if(temp < Array[ j ])
                {
                    temp = Array[ j ] ; 
                    index = j ;
                    counter -- ;
                }
            }
            if(counter == 0){
                flag=false;
            }
            Array[ index ] = Array [ i ];
            Array [ i ] = temp;
            counter = 0;

        }
        else
            break;
    }

}



        

