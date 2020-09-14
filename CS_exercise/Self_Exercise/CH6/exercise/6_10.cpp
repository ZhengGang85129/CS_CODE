#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int Type = 9;
int Number[Type] = {
    0
};
void Distribution(int[],int[],const int,  const int ,bool[]);
void Output_histogram(const int[] , const int) ;
int main()
{
    srand(time(0));
    const int NumberOfPerson = 30;
    int Salaries[NumberOfPerson] ;
    bool flag[NumberOfPerson] ;
    int index;
    for(index = 0; index < NumberOfPerson; index ++){
        Salaries[index] = (rand()%20000)*0.09+200;
        flag[index] = true;
    }
    Distribution(Number, Salaries,Type, NumberOfPerson,flag);
    Output_histogram(Number,Type) ;
}

void Distribution( int N[], int S[], const int sizeN,const int sizeS, bool f[]){
    for(int i = 0; i < sizeN ; i++){
        for(int j = 0 ; j <sizeS ; j++ )
        {
            if(((299+i*100) > S[j]) && f[j] == true){
                N[i] ++;
                f[j] = false;
            }
        }
    }
}
void Output_histogram(const int N[], const int sizeN){
    cout<<"Distribution diplayed in number:\n\n";
    for(int i = 0 ; i < sizeN; i++)
    {
        if(i <sizeN-1)
            cout<<"$"<<200+i*100<<setw(3)<<"-"<<setw(5)<<299+i*100<<"  : "<<N[i]<<"\n";
        else
            cout<<"$"<<200+i*100<<setw(9)<<" and over: "<<N[i]<<"\n\n";
        }
    cout<<"Distribution displayed in historgram:\n\n";
    for(int n = 0 ; n < sizeN; n++ )
    {
       if(n < sizeN -1)
        cout<<"$"<<200+n*100<<setw(3)<<"-"<<setw(5)<<299+n*100<<"  :"<<setw(2);
       else
        cout<<"$"<<200+n*100<<setw(9)<<" and over: ";
        for(int k = 0; k < N[n] ; k++)
            cout<<"*";
        cout<<"\n";
    }
}
