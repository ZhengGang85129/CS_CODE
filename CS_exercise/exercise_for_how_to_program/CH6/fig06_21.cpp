#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1("happy");
    string s2("birthday");
    string s3,s4;

    cout<<"Enter a line of text: ";
    getline(cin,s4);

    cout<<"s1 is \""<< s1 <<"\"; s2 is \""<<s2
        <<"\"; s3 is \""<<s3 << "\"; s4 is \"" << s4
        <<"\"\n\n";
    cout<<"s1 length " <<s1.length() << "; s2 length "<< s2.length()
        <<"; s3 length "<<s3.length() <<"; s4 length "<<s4.length();

    cout<<"\n\nThe results of comparing s2 and s1:"
        <<"\ns2 == s1 yields "<<( s2 == s1 ? "true":"false")
        <<"\ns2 != s1 yields "<<( s2 != s1 ? "true":"false")
        <<"\ns2 >  s1 yields "<<( s2 >  s1 ? "true":"false")
        <<"\ns2 <  s1 yields "<<( s2 <  s1 ? "true":"false")
        <<"\ns2 >= s1 yields "<<( s2 >= s1 ? "true":"false")
        <<"\ns2 <= s1 yields "<<( s2 <= s1 ? "true":"false");
    cout<<"\n\nTesting s3.empty():"<<endl;

    if(s3.empty())
    {
        cout<<"s3 is empty; assigning s1 to s3;"<<endl;
        s3 = s1;
        cout<<"s3 is \""<<s3<<"\"";
    }
        cout<<"\n\nAfter s1 += s2, s1 is ";
        s1 += s2;
        cout<<s1;
        cout<<
        

}
