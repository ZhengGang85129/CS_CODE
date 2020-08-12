#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void outputVector(const vector<int> &);
void inputVector(vector<int> &);

int main()
{
    vector< int > integers1( 7 );
    vector< int > integers2( 10);

    //print integers1 size and contents;
    cout<<"Size of vector integers1 is "<<integers1.size()
        <<"\nvector after initialization: "<< endl;
    outputVector( integers1);
    //print integers2 size and contents;
    cout<<"Size of vector integers2 is "<<integers2.size()
        <<"\nvector after initialization: "<< endl;
    outputVector( integers2);
   //input and print integers1 and integers2
    cout<< "\nEnter 17 integers:"<<endl;
    inputVector( integers1 );
    inputVector( integers2 );

    cout<<"\nAfter input, the vectors contain:\n"
        <<"integers1:"<<endl;
    outputVector( integers1 );
    cout<< "integers2:"<<endl;
    outputVector( integers2 );

    //use inequality(!=) operator with vector objects
    cout<<"\nEvaluating: integers1 != integers2"<<endl;

    if( integers1 != integers2)
        cout<<"integers1 and integers2 are not equal"<<endl;

    //create vector integers3 using integers1 as an
    //initializer;print size and contents
    vector< int > integers3( integers1 );

    cout<<"\nSize of vector integers3 is "<<integers3.size()
        <<"\nvector after initialization:"<<endl;
    outputVector( integers3 );
    //use overloaded assignment (=) operator
    cout<<"\nAssigning integers2 to integers1:"<<endl;
    integers1 = integers2;//assign integers2 to integers1
    
    cout<< "integers1:"<<endl;
    outputVector( integers1 );
    cout<< "integers2:"<<endl;
    outputVector( integers2 );

    // use equality (==) operator with vector objects
    cout<<"\nEvaluating: integers1 == integers2"<<endl;

    //use square brackets to create rvalue
    cout<<"\nintegers1[5] is "<<integers1[ 5 ];

    //use square brackets to create lvalue
    cout<<"\n\nAssigning 1000 to integers1[5]"<<endl;
    integers1[5] =1000;
    cout<< " integers1:"<<endl;
    outputVector( integers1 );
    //attempt to use out-of-range subscript
    cout<<"\nAttempt to assign 1000 to integers1.at(1)"<<endl;
    integers1.at( 1 ) = 1000;
}
void outputVector(const vector<int> &array)
{
    size_t i;//declare control variable

    for( i = 0; i <array.size(); i++)
    {
        cout<<setw(12)<<array[i];
        if((i+1)%4 == 0)
            cout<<endl;
    }
    if(i%4!=0)
        cout<<endl;

}
void inputVector(vector<int>&array)
{
    for(size_t i = 0; i <array.size();i++)
        cin>>array[i];
}
