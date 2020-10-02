//used to write generic program i.e. work for differnt type of data type
//we pass data type as parameter to function or class.
//- 1. function template 2. class template
#include<iostream>
using namespace std;



int getmaxint(int a, int b)
{
    return a>b ? a : b;
}
char getmaxchar(char a, char b)
{
    return a>b ? a : b;
}
template <typename T>   //syntax . you can give any name in place of T. Should be placed exactly above the desired generic function .
T getmax(T a , T b)
{
    return a>b ? a : b ;
}

int main()
{
    int a = 10 , b = 20 ;
    char c = 'a' , d = 'z' ;
    cout << "The big number is : " << getmaxint(a,b) << endl ;
    cout << "The big character is : "<<getmaxchar(c,d) << endl ;   // creating same type of function for different data type is waste of time
    cout << "The big number is : " << getmax<int>(a,b) << endl ;    // create 1 copy of function for int data type .
    cout << "The big character is : "<< static_cast<char>(getmax<char>(c,d)) << endl ;  // create 1 copy of function for char data tyoe .  Also type casting is not necessary
    return 0 ;
}
