#include<iostream>
using namespace std;
/*
template <typename T>
T getmax(T a , T b)         // for 1 it will fail as it will not be able to decide weather T is int or float.
{
    return a>b ? a : b ;
}
*/
template <class T1 , class T2 >   // we can also use class in place of typename
T1 getmax(T1 a , T2 b)   // now it will work fine for both 1 n 2
{
    return a>b ? a : b;   // 30.5 will be returned but as return type is of int so we will get int as output . So how to solve this data loss
}
template <class rt , class T1 , class T2 >   // rt for return type . you can use any name
rt getmax1(T1 a , T2 b)
{
    return a>b ? a : b;
}
template <class T1 , class T2 >
auto getmax2(T1 a , T2 b)       //auto will deduce return type automatically
{
    return a>b ? a : b;
}
int main()
{
    int a = 10 , b = 20 ;
    char c = 'a' , d = 'z' ;
    cout << "The big number is : " << getmax(20,30.5) << endl ;    //---- 1
    cout << "The big character is : "<< getmax(c,d) << endl ;      // --- 2
    // to solve data loss-
    // if we use getmax instead of getmax 1 with same sintax then function will assume that T1 is float
    cout << "The big number is : " << getmax1<float>(20,30.5) << endl ;   // we assumed that float is biggest of two so we used it and float will be used as rt
    // you can also pass the parameter for the values but by default they are not required as it use auto deduction mechanism .
    cout << "The big number is : " << getmax1<float , int , float>(20,30.5) << endl ;
    //another way --
    cout << "The big number is : " << getmax2(20,30.5) << endl ;
    return 0;
}
