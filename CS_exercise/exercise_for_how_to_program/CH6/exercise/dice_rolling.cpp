
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int times = 36000;
const int size= 12;
int Possible_Sum[size]={};
void Output(const int[],const int);
void Distribution(const int[], const int);
int main()
{
    srand(time(0));
    int f_dice, s_dice, sum;
    for( int ctr = 0; ctr < times; ctr++){
        f_dice =1 + rand()%6;
        s_dice =1 + rand()%6;
        sum = f_dice + s_dice - 1 ;
        Possible_Sum[sum]++;
    }
    Output( Possible_Sum, size );
    //Distibution( Possible_Sum , size );

}

void Output( const int array[], const int SIZE )
{
    for( int i = 0 ; i < SIZE ; i++)
    {
        cout<<"SUM for "<<i + 1 <<" is "<<array[ i ] <<" with possiblity: "<<static_cast<double>(array[i]) / times <<endl;
    }
}
