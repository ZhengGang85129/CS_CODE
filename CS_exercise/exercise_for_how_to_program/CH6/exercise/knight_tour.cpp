#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int SQUARE = 8;
int board[SQUARE][SQUARE] ;
int currentRow , currentColumn;
const int PossibleMove = 8;
int horizontal[ PossibleMove ] = {
    2, 1,-1,-2,-2,-1, 1, 2
}, vertical[ PossibleMove ] = {
    -1,-2,-2,-1, 1, 2, 2, 1
};
bool flag = true;
void Initialization( int[][SQUARE] , const int );
void display( const int[][SQUARE] , const int );
int main()
{
  currentRow = 3 ;
  currentColumn = 4;
  Initialization( board , SQUARE);
  board[ currentRow ][ currentColumn ] = 1;
  int tempRow, tempCol;
  int square_left = 63;
  display(board, SQUARE);
  while( square_left ){
    bool flag = false;
    for( int moveType = 0 ; moveType < PossibleMove ; moveType++){
        tempRow = currentRow;
        tempCol = currentColumn;
        currentRow    += vertical[ moveType ];
        currentColumn += horizontal[ moveType ] ;
        if(currentColumn >=0 && currentColumn <=7 && currentRow >= 0 && currentRow <=7)
        {
            if( board[ currentRow ][ currentColumn ] != 0){
                currentRow = tempRow;
                currentColumn = tempCol;
            }
            else{
                flag = true;
                board[ currentRow ][ currentColumn ]++;
                break;
            }

        }
            
    }
    if(flag == true)
        square_left--;
    else
    {
        cout<<"Row: "<<currentRow<<" Col: "<<currentColumn<<endl;
        break; 
    }
  }
  display(board, SQUARE); 
  cout<<"There are "<<square_left<<" squares left !"<<endl;
}
void display(const int arr[][SQUARE], const int size){
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
