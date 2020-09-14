#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
const int SQUARE = 8;
const int TRY = 1000;
int board[SQUARE][SQUARE] ;
const int PossibleMove = 8;
int horizontal[ PossibleMove ] = {
    2, 1,-1,-2,-2,-1, 1, 2
}, vertical[ PossibleMove ] = {
    -1,-2,-2,-1, 1, 2, 2, 1
};
int Track[ 1000 ] ={0};
void Initialization( int[][SQUARE] , const int );
void Display( const int[][SQUARE] , const int ,const int  , const int , const int );
void Tour( int[][SQUARE] , const int , bool& , int& , int , int );
bool random_pick(int [][SQUARE], int & ,  int &, int &);
void print(const int [] , const int );
int main()
{
  srand(time(0));
  Initialization( board , SQUARE);
  int counter = 0;
  int DISTANCE ; 
  int Column = rand()%8;
  int Row = rand()%8;
  bool FLAG = true;
  while( DISTANCE != 64 )
  {
      DISTANCE = 1 ;
      Tour(board, SQUARE, FLAG , DISTANCE , Column, Row );
      //Track[ counter ] = DISTANCE;
      counter ++;
      Initialization( board , SQUARE);
      Column = rand()%8;
      Row    = rand()%8;
      FLAG = true;
      if(DISTANCE != 64)
        cout<<setw(5)<<DISTANCE;
      if((counter+1) % 20 == 0)
          cout<<"\n";
  }
  cout<<"\n";
  cout<<"This program has tried "<<counter<<" times.\n";
  //print(Track,counter-1);
}
void Tour ( int arr[][SQUARE] ,  const int size, bool & flag , int &distance  , int col , int row)
{
    if(flag)
    {
        arr[ row ][ col ] = distance ;
        flag = random_pick( arr , col , row , distance );
        Tour( arr , size , flag , distance , col , row );
    }
    else
    {
        if(distance == 64 )
        {
            cout<<"\n\nSuccess!"<<endl;
            cout<<"  ";
            for(int row = 0 ; row < SQUARE ; row ++)
                cout<<setw(5)<<row;
            cout<<"\n\n";
            Display( arr, 0 , 0 , SQUARE , SQUARE );
            cout<<"\n"<<endl;
        }
        else
        {
//            cout<<"Fail!"<<endl;
//            cout<<"The knight has only "<<distance<<" moves. "<<endl;
        }

    }

}
void Display(const int arr[][SQUARE], const int ROW , const int COL ,const int size_row , const int size_col){
    if( ROW == size_row - 1 and COL == size_col - 1 )
        cout<<setw(5)<< arr[ ROW ][ COL ]<<endl;
    else if ( COL < size_col - 1  )
    {
        if(COL == 0 )
            cout<<ROW<<" ";
        cout<<setw(5)<<arr[ ROW ][ COL ];
        Display( arr , ROW , COL + 1 , size_row , size_col );
    }
    else if ( COL == size_col - 1 and ROW < size_row - 1 )
    {
        cout<<setw(5)<<arr[ ROW ][ COL ]<<"\n"<<endl;
        Display( arr , ROW + 1 , 0 , size_row , size_col );
    }
}
void Initialization(int arr[][SQUARE],const int size)
 {
    for( int row = 0 ; row < size ; row++)
    {
        for( int col = 0 ; col < size ; col++)
        {
            arr[ row ][ col ] = 0 ; 
        }
    }
 }

bool random_pick( int a[][SQUARE] ,int &COL , int &ROW , int &DISTANCE )
{
    int current_col = COL ;
    int current_row = ROW ;
    int pick_list[ SQUARE ] = {
        0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 
    };
    int cnt = SQUARE ;
    int TYPE;
    do
    {
        TYPE = rand() % cnt ;
        current_col += horizontal[ pick_list[ TYPE ] ];
        current_row += vertical[ pick_list[ TYPE ] ];
        if(current_col < 8 and current_col >= 0 and current_row < 8 and current_row >= 0  and a[ current_row ][ current_col ] == 0)
        {
            DISTANCE ++ ;
            a[current_row][current_col] = DISTANCE ;
            COL = current_col;
            ROW = current_row;
            return true;
        }
        current_row = ROW ;
        current_col = COL ;
        int tmp = pick_list[ TYPE ];
        pick_list[ TYPE ] = pick_list[ cnt - 1  ];
        cnt-- ;
    }while(cnt > 0);
    return false;
}
void print(const  int track[] , const int pos)
{
    if(pos == 0 )
        cout<<setw(5)<<track[pos];
    else
    {
        print( track , pos - 1 );
        cout<<setw(5)<<track[pos];
        if( (pos+1) % 10 == 0)
            cout<<endl;
    }
}
