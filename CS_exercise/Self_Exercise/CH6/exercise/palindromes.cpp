#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>


using namespace std;
void palindromes( string );
int main()
{
    string s;
    cout<<"Enter a line of text: ";
    getline( cin , s );
    palindromes( s );
}

void palindromes( string str )
{
    string str1;
    bool flag =true ;

    for(size_t index = 0  ; index < str.length() ; index ++ )
    {
        str1[ index ] = str[ str.length() - 1 - index ];
        if(str1[ index ] != str[ index ])
            flag = false ;
    }
    if(flag == true )
        cout<<"The string is palindromes. \n\n";
    else 
        cout<<"The string is not palindromes. \n\n";

}
