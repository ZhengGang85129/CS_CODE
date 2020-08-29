#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
const int N = 10 ;
int Array[ N ] = {
   62 , 30 , 8 , 900 , 120 , 35 , 47 , 98, 1002 , 100 
};
void bucket_sort( int []  , const int ,const int ,const int &);
void Find_Max(int [] , const int ,const int , int &);
void output(const int[],const int );
int main()
{
    int max = -10000000;
    int DIGIT = 0;
    output( Array , 0 );
    Find_Max( Array , 0 , N , max );
    cout<<"max: "<<max<<endl;
    bucket_sort( Array , N, max , DIGIT ) ;   
    output( Array , 0 );
}
void output(const  int arr[],const int pos)
{
    if(pos == N-1 ){
        cout<<arr[ pos ];
        cout<<"\n";
    }
    else
    {
        cout<<arr[ pos ]<<" ";
        output(arr,pos+1);
    }
}
void bucket_sort( int arr[], const int size ,const int max ,const int &power)
{
    int digit = pow(10,power);
    if( max > digit/10){
        int bucket[10][ N ] = {0};
        int tmp = 0 ;
        for(int i = 0 ; i < size ; i++)
        {
            if(arr[ i ] > digit )
                tmp = arr[ i ] % digit ;
            else
                tmp =  arr[i];
            for( int m = 0 ; m < 10 ; m++)
            {
                if( tmp < (m+1) * digit/10 and tmp >= m * digit/10 )
                {
                    bucket[ m ][ i ] = arr[ i ];
                }
            }
        }
        int n = 0;
        for(int row = 9 ; row >=0 ; row --)
        {
            for(int col = 0 ; col < size ; col ++)
            {
                if(bucket[ row ][ col ] != 0 )
                {
                    arr[ n ] = bucket[ row ][ col ];
                    n++;
                }
            }
        }
        bucket_sort(arr,size,max,power+1);
    }
}
void Find_Max(int arr[] , const int pos , const int size ,int & max)
{
   if(pos < size )
   {
        if(max < arr[ pos ])
            max = arr[ pos ];
        Find_Max(arr,pos+1,size,max);
   }

}
