#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
const int N = 1000;

int main()
{
  long double Pi ;
  for( int i = 0 ; i < N ; i++)
  {
      if(i%2 == 0)
          Pi += 4. /(static_cast< long double >(i)* 2. + 1.);
      else 
          Pi -= 4. /(static_cast< long double >(i)* 2. + 1.);
  }
  cout<<"Pi is approximated to "<<Pi<<endl;
}
