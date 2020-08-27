#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
const int SQUARE = 8;
int board[SQUARE][SQUARE] ;
int accessibility[ SQUARE ][ SQUARE ] =
{
    {
        2 , 3 , 4 , 4 , 4 , 4 , 3 , 2 
    },
    {
        3 , 4 , 6 , 6 , 6 , 6 , 4 , 3
    },
    {
        4 , 6 , 8 , 8 , 8 , 8 , 6 , 4
    },
    {
        4 , 6 , 8 , 8 , 8 , 8 , 6 , 4
    },
    {
        4 , 6 , 8 , 8 , 8 , 8 , 6 , 4
    },
    {
        4 , 6 , 8 , 8 , 8 , 8 , 6 , 4
    },
    {
        3 , 4 , 6 , 6 , 6 , 6 , 4 , 3
    },
    {
        2 , 3 , 4 , 4 , 4 , 4 , 3 , 2
    }
};
const int PossibleMove = 8;
int horizontal[ PossibleMove ] = {
    2, 1,-1,-2,-2,-1, 1, 2
}, vertical[ PossibleMove ] = {
    -1,-2,-2,-1, 1, 2, 2, 1
};
void Initialization( int[][SQUARE] , const int );
void Display( const int[][SQUARE] , const int ,const int  , const int , const int );
void Tour( int[][SQUARE] , int[][SQUARE] , const int ,const int , const int , bool& , int&);
int main()
{
  srand(time(0));
  int counter = 0;
  int success_counter = 0;
  for( int i = 0 ; i < SQUARE ; i++)
  {
      for( int j = 0; j < SQUARE ; j++)
      {
          bool f = false;
          int COL = j ;
          int ROW = i  ;
          ++counter ;
          cout<<"=========== Round "<<counter<<" ==========="<<endl;
          Initialization( board , SQUARE );
          Tour( board , accessibility,  SQUARE ,COL , ROW , f ,success_counter);
          if(f == true)
          {
                cout<<"Screening of the current board: "<<endl;
                cout<<"  ";
                for(int row = 0 ; row < SQUARE ; row ++){
                    
                    cout<<setw(5)<<row; 
                }
                cout<<"\n"<<endl;
                Display( board, 0 , 0 , SQUARE , SQUARE); 
          }
                      
      }
  }
    cout<<"Success "<<success_counter<<" times ."<<endl;
    Initialization( board , SQUARE);
}
void Tour ( int arr[][SQUARE] , int acs[][SQUARE] , const int size, const int Init_Col, const int Init_Row , bool &flag1 , int &ctr )
{
   static int currentRow , currentCol ; 
   currentRow = Init_Row ;
   currentCol = Init_Col ; 
   arr[ currentRow ][ currentCol ] = -1 ;
   int square_left = size * size - 1 ;
   while( square_left )
   {
    bool flag  = false;
    static int tempRow, tempCol ;
    static int bestRow , bestCol ; 
    int min_acess = 10000;
    for( int moveType = 0 ; moveType < PossibleMove ; moveType++){
        tempRow = currentRow;
        tempCol = currentCol;
        currentRow    += vertical[ moveType ];
        currentCol += horizontal[ moveType ] ;
        if(currentCol >=0 && currentCol <=size - 1 && currentRow >= 0 && currentRow <=size - 1)
        {
            if( arr[ currentRow ][ currentCol ] == 0 && acs[ currentRow ][ currentCol ] < min_acess)
            {
                min_acess = acs[ currentRow ][ currentCol ];
                bestRow = currentRow ;
                bestCol = currentCol ; 
                flag = true ;
            }
        }
        currentRow = tempRow;
        currentCol = tempCol;
    }
    if(flag == false)
    {
        cout<<"failed"<<endl;
        break;
    }

    else
    {
        currentRow  = bestRow ;
        currentCol  = bestCol ; 
        acs[ currentRow ][ currentCol] --;
        arr[ currentRow ][ currentCol] = size*size - square_left;
        square_left -- ;
        if(square_left == 0 ){
            ctr ++;
            flag1 = true;
            cout<<"success"<<endl;
            break;
        }

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
