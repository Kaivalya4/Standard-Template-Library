//duplicate value in sorted order .
// keys can't be modified once inserted . Only possible way is we have to delete and update with a new value.

#include<iostream>
#include<map>
#include<typeinfo>

using namespace std;

int main()
{
    multimap<int  , int> m1;
    multimap<int , int> ::iterator it;

    for(int i =0 ; i<5 ; i++)
        m1.insert(pair<int , int>(i , 10*i));  //two types of pair technique to insert element
    m1.insert(make_pair(10  , 10));

    cout<<"Element of m1 is : "<< endl;
    for(pair<int , int> i:m1)
    {
        cout<< i.first << " -> " << i.second << endl ;
    }

    //assigning all elements of m1 to m2
    multimap<int  , int> m2(m1.begin() , m1.end()); //begin() return iterator to beginning while end() returns iterator to end of the map.

    //it = m2.rbegin(); this will not work as it is iterator not reverse iterator
    multimap<int , int> ::reverse_iterator it2; // reverse_iterator is used to create reverse pointer iterator

    //rbegin() return reverse pointer . so it will return pointer to last element and incrementing it will move towards beginning . lly ,  with rend()
    cout<< "Element of m2  in reverse order are : " << endl;
    for(it2 = m2.rbegin() ; it2 != m2.rend() ; it2++)
        cout<< it2 -> first <<  " -> " << it2 -> second << endl;


    //cbegin() returns constant pointer to the beginning . it can help us to iterate but we cannot use this to modify value.
    //cend() returns constant pointer to the last .........
    //const_iterator is used to create constant pointer iterator
    cout<< "Element of m2 in correct order are : " << endl;
    for(multimap<int , int> ::const_iterator it = m2.cbegin() ; it != m2.cend() ; it++)
        cout << it -> first << " -> " << it-> second << endl;

    cout<< "size of m2 is : " << m2.size() ; //size() returns number of elements

    cout<< endl << "max size of m2 is  : " << m2.max_size() << endl ; //returns maximum capacity of the multimap

    m2.empty() ? cout<< "m2 is empty" : cout<< "m2 is not empty " << endl; // empty returns true if m2 is empty otherwise not.

    //clear() will delete all element from multimap
    m2.clear();
    cout<< "After clear() operation  : "<< m2.empty() ? cout<< "\bm2 is empty " << endl: cout << "\bm2 is not empty " << endl;


    //find(key) returns iterator or constant iterator that refers to the key specified . In case multiple of same keys present , the iterators refer to one of
    // of the keys typically the first one .To get all element of that key we can use equal range. If key is not present in map
    //it returns iterator refering to m1.end()
    multimap<int , int> ::iterator itr = m1.find(1);
    cout<< "After find operation on m1: " << itr -> first << " -> " << itr -> second;


    //erase(key) : will delete the value with specified key.
    m1.erase(1);
    cout<< "After erase operation on m1 : "<< endl;
    it = m1.lower_bound(0); //lower_bound(key) - return iterator to specified first key pair
    itr = m1.upper_bound(10); //upper_bound(key) returns iterator to first element after the last key value pair specified . If element is not there then
                                //it returns zero
    for(auto i = it ; i != itr ; i++)
        cout<< i -> first << " -> " << i -> second << endl;


    //swap - swap values of m1 and m2 irrespective of their size unlike map.
    cout<< "values of m1 before swap : " <<endl;
    for(auto i:m1)
        cout<< i.first << " -> " << i.second << endl;
    for(int i = 0 ; i<=6 ; i++)
        m2.insert(pair<int , int>(2*i , 2*i+1));
    cout<< "values of m2 before swap : " << endl;
    for(auto i: m2)
        cout<< i.first << " -> " << i.second << endl;
    m1.swap(m2);
    cout<< "values of m1 after swap : " <<endl;
    for(auto i:m1)
        cout<< i.first << " -> " << i.second << endl;
    cout<< "values of m2 after swap : " <<endl;
    for(auto i:m2)
        cout<< i.first << " -> " << i.second << endl;
    return 0;
}
