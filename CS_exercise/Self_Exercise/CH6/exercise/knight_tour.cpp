#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
const int SQUARE = 8;
int board[SQUARE][SQUARE] ;
const int PossibleMove = 8;
int horizontal[ PossibleMove ] = {
    2, 1,-1,-2,-2,-1, 1, 2
}, vertical[ PossibleMove ] = {
    -1,-2,-2,-1, 1, 2, 2, 1
};
void Initialization( int[][SQUARE] , const int );
void Display( const int[][SQUARE] , const int );
void Tour( int[][SQUARE] , const int ,const int , const int );
int main()
{

  srand(time(0));
  Initialization( board , SQUARE );
  Display( board, SQUARE ); 
  Tour( board , SQUARE ,3 , 4);
  Display( board, SQUARE ); 

}
void Tour ( int arr[][SQUARE] , const int size, const int Init_Col, const int Init_Row)
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
    for( int moveType = 0 ; moveType < PossibleMove ; moveType++){
        tempRow = currentRow;
        tempCol = currentCol;
        currentRow    += vertical[ moveType ];
        currentCol += horizontal[ moveType ] ;
        if(currentCol >=0 && currentCol <=size - 1 && currentRow >= 0 && currentRow <=size - 1)
        {
            if( arr[ currentRow ][ currentCol ] == 0)
            {
                arr[ currentRow ][ currentCol ] = size * size - square_left;
                flag = true;
                square_left -- ;
                break;
            }
        }
        currentRow = tempRow;
        currentCol = tempCol;
    }
    if(flag == false)
    {
        break;
    }
   }
   cout<<"The last step is at Row : "<<currentRow<<" Column: "<<currentCol<<endl;
   cout<<"There are "<<square_left<<" squares left !"<<endl;

}
void Display(const int arr[][SQUARE], const int size){
    cout<<"Screening of the current board: "<<endl;
    cout<<"  ";
    for(int row = 0 ; row < size ; row ++){
        cout<<setw(5)<<row; 
    }
    cout<<"\n"<<endl;
    for( int i = 0 ; i < size ; i++){
        cout<<i<<" ";
        for(int j = 0 ; j < size ; j ++ ){
            cout<<setw(5)<<arr[ i ][ j ];
        }
        cout<<"\n"<<endl;
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
