#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int , int> m1 , m2;
    map<int, int> :: iterator it;  // creating iterator for map

    //insertion of element increase size of array. since map contains unique key , it always check whether any element already inserted or not with same key
    //one way to insert -
    for(int i=0 ; i<5 ; i++)
    {
        m1.insert(pair<int , int> (i , i*10));
        m2.insert(pair<int , int> (1 , (i+1)*10)); // see here we provided key as constant . so only first value will be inserted as value of key
                                                // rest value are popped out as duplicates
    }


    it = m1.begin() ; //begin() return iterator to the beginning
    cout<< "m1 values : "<< endl;
    for(it ; it != m1.end() ; it++ ) // end() return iterator to the end of the map.
    {
         cout << it -> first << " -> " << it -> second; // like we use in class and structure since it is pointer
         cout<< endl;
    }


    cout<< "m2 values : "<< endl;
    for(auto i:m2 )
        cout << i.first << " -> " << i.second;
    cout << endl;

    //another way of insertion using iterator -
    it  = m1.begin(); //begin() returns iterator to the beginning
    it++;
    m1.insert(it , pair<int  , int>(99 , 99)); // even though it is inserted at second but due to ordering property(ascending by default) it will be inserted
                                                // in last
    it = m1.end();
    m1.insert(it , pair<int , int>(10 , -1));


    cout<< "m1 after some insertion : " << endl;
    for(auto i:m1)
    {
        cout<< i.first << " -> " << i.second;
        cout<< endl;
    }

    //erase() - can remove single or range of elements . also size of map will decrease due to deletion
    //deleting single element
    it = m1.begin();
    m1.erase(it); // will delete key 0
    cout<< "m1 after one erase operation : " << endl;
    for(auto i:m1)
    {
        cout<< i.first << " -> " << i.second;
        cout<< endl;
    }


    //deleting range of values
    it = m1.begin();
    m1.erase(it , m1.end()); // this will delete entire map


    //empty() - returns 1 when map is empty otherwise 0 -
    m1.empty() ? cout << "m1 is empty " : cout << "m1 is not empty";
    cout<< endl;


    //clear() - removes all element of map reducing its size to 0 -
    it = m2.begin();
    m2.clear();
    m2.empty() ? cout << "m2 id empty " : cout << "m2 is not empty";

    cout<< endl << "size of m2 after clear() : " << m2.size();


    //again creating m1 and m2 -
    for(int i=0 ; i<5 ; i++)
    {
        m1.insert(pair<int , int> (i , i*10));
        m2.insert(pair<int , int> (i , i+i));
    }
    cout << endl << "size of newly created m2 : " << m2.size();


    //map_size() returns maximum size a map can have
    cout << endl << "max size of m1 is : " << m1.max_size();


    //swap() - swap elements of two maps . size of two map should be same
    cout << endl << "m1 before swap operation : " << endl;
    for(auto i:m1)
    {
        cout<< i.first << " -> " << i.second;
        cout<< endl;
    }
    cout<< "m2 before swap operation : " << endl;
    for(auto i:m2)
    {
        cout<< i.first << " -> " << i.second;
        cout<< endl;
    }
    m1.swap(m2);
    cout << "m1 after swap operation : " << endl;
    for(auto i:m1)
    {
        cout<< i.first << " -> " << i.second;
        cout<< endl;
    }
    cout << "m2 after swap operation : " << endl;
    for(auto i:m2)
    {
        cout<< i.first << " -> " << i.second;
        cout<< endl;
    }
    return 0;
}
