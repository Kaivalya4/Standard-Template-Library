#include<iostream>
using namespace std;
// non template function --
int max(int a , int b)      // --- a
{
    cout<<" max(int , int )is called" ;
    return a>b ? a: b;
}
template <typename T >     // --- b
T max(T a, T b)
{
    cout<<"max(T ,T )is called";
    return a>b ? a: b;
}
template<typename T>      // --- c
T max(T a, T b , T c)
{
    cout<<"max(T,T,T) is called";
    return max(max(a,b) , c);     // both inner and outer called a since it is not specified to call a template function.
}
int main()
{
    // we used scope resolution because there is also a inbuilt function max . So we say to compiler - dont include yours include mine
    cout<< ::max(10.0 , 20.0) << endl;   // ---1     calls b since type is double not match with a
    cout<< ::max('a' , 'j') << endl;    //---2      calls b
    cout<< ::max(2 , 3) << endl;        //---3      calls a(between a and b) since it was not specified that we can call template function or not
    cout<< ::max<>(2 , 3) << endl;      //---4      calls b . <> tells compiler to call a template function
    cout<< ::max<double>(2 , 3) << endl;    //---4   calls b with type double
    cout<< ::max(10 , 20 , 30) << endl;     // ---5  calls c
}

