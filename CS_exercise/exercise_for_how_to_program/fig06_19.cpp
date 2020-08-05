#include <iostream>
#include <iomanip>

using namespace std;

const int students = 10;
const int tests = 3;

int minimum( const int [][tests], int , int );
int maximum( const int [][tests], int , int );
double average( const int [][tests], int );
void outputGrades( const int [][tests], int , int );
void outputBarChart( const int [][tests], int , int );

int main()
{
    int studentGrades[ students ][ tests ] =
    {
        {
            87 , 96 , 70
        },
        {
            68 , 87 , 90
        },
        {
            94 ,100 , 90
        },
        {
           100 , 81 , 82 
        },
        {
            83 , 65 , 85
        },
        {
            78 , 87 , 65
        },
        {
            85 , 75 , 83
        },
        {
            91 , 94 ,100
        },
        {
            76 , 72 , 84
        },
        {
            87 , 93 ,73 
        }

    };
    outputGrades ( studentGrades, students , tests );

    cout << "\nLowest of all the grades is "<<
        minimum( studentGrades, students , tests)
        <<"\nHighest of all the grades is "
        <<maximum( studentGrades , students , tests)
        <<endl;
    outputBarChart( studentGrades , students , tests);
}
 
int minimum( const int a[][tests] , int rows , int cols){
    int lowGrade = 100;
    for ( int i = 0; i <rows ; i++){
        for(int j = 0 ; j <cols ; j++){
            if(a[i][j] < lowGrade)
                lowGrade = a[i][j] ;
        }
    }
    return lowGrade;
}
int maximum( const int a[][tests] , int rows , int cols){
    int highGrade = 0;
    for ( int i = 0; i <rows ; i++){
        for(int j = 0 ; j <cols ; j++){
            if(a[i][j] > highGrade)
                highGrade = a[i][j] ;
        }
    }
    return highGrade;
}
double average( const int setOfGrades[] , const int gradeCount){
    int total = 0;

    for( int grade = 0; grade < gradeCount ; grade ++)
        total  += setOfGrades[grade];
    return static_cast< double >( total ) / gradeCount;
}

void outputBarChart( const int grades[][ tests ], int rows, int cols){
    cout << "\nOverall grade distribution:" <<endl;
    const int frequencySize = 11;
    int frequency[ frequencySize ] = {};
    
    for( int student = 0; student < rows ; student ++){
        for( int test = 0; test < cols ; test ++){
            ++frequency[grades[student][test]/10];
        }
    }
    for (int count = 0 ; count < frequencySize; count ++){
        if (count == 0 )
            cout<<"0-9: ";
        else if(count == 10)
            cout<<"100: ";
        else 
            cout<<count * 10<<"-"<<count*10 + 9 <<": ";
    
    for ( int stars = 0; stars < frequency[ count ]; stars ++)
        cout<<"*";
    cout<<endl;
}
}
void outputGrades( const int grade[][tests] , int rows, int cols )
{
    cout<<"\nThe grades are:\n\n";
    cout<<"            ";

    for(int test = 0; test< tests; test ++)
        cout<< " Test "<<test + 1<<"  ";

    cout<<"Average"<<endl;
    for(int student = 0 ; student < rows; student ++){
        cout<<"Student "<<setw(2)<<student + 1;
        for(int test = 0; test < cols; test ++)
            cout<<setw(8)<<grade[ student ][ test ];
        
        double averageGrade = average(grade[student], tests);
        cout<<setw( 9 )<<setprecision(2) <<fixed<<averageGrade<<endl;

    }
}


