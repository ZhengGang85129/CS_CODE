#include <iostream>
using namespace std;

int main()
{
    char c;
    short s;
    int i ;
    long l;
    float f;
    double d;
    long double ld;
    int array[20];
    int *ptr = array;

    cout<<"size of c "<<sizeof c
        <<"\tsize of(char) "<<sizeof(char)
        <<"\nsize of s "<<sizeof s
        <<"\tsize of short "<<sizeof(short)
        <<"\nsizeof i "<<sizeof i
        <<"\tsizeof int "<<sizeof(int)
        <<"\nsizeof l "<<sizeof l
        <<"\tsizeof long "<<sizeof(long)
        <<"\nsizeof f "<<sizeof f
        <<"\tsizeof float "<<sizeof(float)
        <<"\nsizeof d "<<sizeof d
        <<"\tsizeof double "<<sizeof(double)
        <<"\nsizeof ld "<<sizeof ld
        <<"\tsizeof long double "<<sizeof(long double)
        <<"\nsizeof array "<<sizeof array
        <<"\tsizeof ptr "<<sizeof ptr<<endl;


}
