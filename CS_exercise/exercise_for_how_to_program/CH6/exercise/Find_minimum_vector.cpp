#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>


using namespace std;
int seed;
void Initialization( vector< int > & );
void Print( const  vector< int > & );
void Find_minimum( const vector<int> &);

int main()
{
    cout<<"Input the seed: ";
    cin>>seed;
    cout<<"\n";
    srand( time( 0 ) ) ; 
    vector<int> array1( 10 );
    Initialization( array1 );
    Print( array1 );
    Find_minimum( array1 );
}


void Initialization( vector< int > & arr )
{
    for( size_t index = 0 ; index < arr.size() ; index ++  )
    {
        arr[ index ] = rand()%seed;
    }
}

void Print( const vector< int > & arr )
{
    cout<<"Elements in the array: "<<endl;
    for( size_t index = 0 ; index < arr.size() ; index ++ )
    {
        cout<<arr[ index ]<<" ";
    }
    cout<<"\n\n";
}

void Find_minimum( const vector< int > & arr )
{
    cout<<"The minimum value of the array: ";
    int MIN = seed * seed + seed;
    for( size_t index = 0; index < arr.size() ; index++)
    {
        if( MIN > arr[ index ] )
        {
            MIN = arr[ index ];
        }
    }
    cout<<MIN<<"\n\n";
}
