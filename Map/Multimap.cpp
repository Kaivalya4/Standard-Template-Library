/*multimap<T1 , T2> obj;
->  T1 is key type and T2 is value type
->  multimap is an associative container (i.e. contains mapped value) in sorted order on the basis of keys(T1) while permitting multiple entries at the same
    time for the same key
->  multimap<char , int  , std::greater<>> m1 ; // for descending . we have ommited things inside greater<>
    multimap<char , int  , std::less<>> m2 ; // for ascending . but by default it is ascending
->  no one knows what data structure it uses as standard , but most assume it to be red-black tree
->  at() and [] can't be used here unlike map.
->  lookup functions - count , find , contains(c++20) ,equal_range , lower_bound , upper_bound
*/


/* we could have used this instead of multimap -
map<char , vector<int>> m1;
but this will increase our workload
*/


#include<iostream>
#include<map>
#include<typeinfo>

using namespace std;

int main()
{
    std::multimap<char , int> m1;
    m1.insert(pair<char , int>('a' ,1));
    m1.insert(make_pair('a' ,1)); //1 can be stored again
    m1.insert(make_pair('a' ,2)); // we can use both pair and make_pair
    m1.insert(make_pair('b' ,1));
    m1.insert(make_pair('b' ,3));

   /* for(auto i:m1)
    {
        cout<< m1.first << " -> " << m1.second;
        cout<< endl;
    }*/

    pair<multimap<char , int>::iterator , multimap<char , int>::iterator >range = m1.equal_range('a'); //equal range returns pair of two iterators
                                                                            //here it will return pair of iterator
     //first element holds address of first a i.e.(a,1) and second iterator holds address of last a i.e.(a,2)


    /*above one can be simply be written as -
        auto <char , int> :: iterator range = m1.equal_range;
    */

    cout<< typeid(range).name() << endl; // to get the type of range variable

    for(auto i = range.first ; i!= range.second ; i++)  // we start from first a which is hold by first part of range and loop till last a which is hold
                                                            // by second part of range
        cout<< i -> first << " -> " << i -> second << endl;

    // count gives total number of particular key
    cout<< "number of a is  : " << m1.count('a'); //if I use semicolon it will not work
    cout<< endl;

    //pair gives first pair related to key given;
    multimap<char , int> ::iterator pairs = m1.find('a');  // we could simply used auto pairs = .......
    cout<< pairs -> first << " -> " << pairs-> second << endl;

    //gives lower bound of key provided i.e. the smallest value for that key because it will come first in case of ascending.
    multimap<char , int> ::iterator lb = m1.lower_bound('a');
    cout<< lb -> first << " -> " << lb -> second << endl;

    //it will the just after element after the upper bound of that key
    multimap<char , int> ::iterator ub = m1.upper_bound('a');
    cout<< ub -> first << " -> " << ub -> second << endl;
    auto ubs = m1.upper_bound('b');
    cout<< ubs -> first << " -> " << ubs -> second << endl; // it will give zero since there is no element after (b ,3)

    return 0;
}
