#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
  double side1 = 1 ;
  double side2 = 1 ;
  double side3 = 1 ; 
  double hypotenuse = 1 ;
  int Upper_Bound = 500;
  for( ; side1 < Upper_Bound ; side1++)
  {
      for( ; side2< Upper_Bound ; side2++)
      {
          side3 = sqrt( side2*side2 + side1 * side1 );
          bool kTrue = true;
          while( kTrue )
          {
              if( hypotenuse < side3)
                  hypotenuse++;
              else
                  kTrue = false;
          }
          if( hypotenuse < Upper_Bound && hypotenuse == side3 )
          {
          cout<<"("<<side1<<", "<<side2<<", "<<hypotenuse<<")\n";
          }
      }
      side2 = 1;
      hypotenuse = 1 ;
  }
}
