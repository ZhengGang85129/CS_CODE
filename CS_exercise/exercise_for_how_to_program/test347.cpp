#include <iostream>
using namespace std;
int main()
{
    int c =7;
    int *a = &c, *b;
    
    a=&c;
    b=a;
    cout<<*a<<" "<<*b<<endl;
    ++c;
    cout<<*a<<" "<<*b<<endl;
    

}

