/* simple syntax in beginning - std::map<T1 , T2> mp;
-> Here T1 is key type and T2 is value type.
-> map is associative container that store elements in key value combination where key should be unique , otherwise it overrides the previous value.
-> implemented using self-implemented binary search tree (like AVL and Red Black tree)
-> its store (key , value) pair in sorted order on the basis of key(T1) (ascending or descending) , by default ascending.
-> generally used in dictionary type problem
*/

//an example of Dictionary implementation-
#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
    std::map<string , int> m1; // string type key and integer type value
    m1["cat"] = 34;   // cat is key with 34 as value.
    m1["apple"] = 56;
    m1.insert(std::make_pair("ball" , 45));  // do same thing as above i.e. makes pair

    //iteration -
    cout << "m1 operation - " << endl;
    for(auto i: m1 )   //auto because we have a mapped data type
    {
        cout << i.first << " -> " << i.second << endl; // first is used to get key name and second is used to get value.it is just like what we use in struct
    }

    //simple access through [] :
    cout << "value at key cat before update : "<<m1["cat"] << endl;
    m1["cat"] = 46;     //we can change value but cant key . once key is fixed it remains that.
    cout << "value at key cat after update : " << m1["cat"] << endl;


    //map<string  , int , std::less<string>> m2; // for ascending but ascending is by default . so no need.
    map<string , int , greater<string> > m2; // greater means to start from high value i.e. in descending order .
                                                // providing string in greater<> is optional.
    m2["cat"] = 34;
    m2["apple"] = 56;
    m2.insert(std::make_pair("ball" , 45));

    cout<<endl << endl << "m2 operation - " << endl;
    for(auto i: m2 )
    {
        cout << i.first << " -> " << i.second << endl;
    }


    map <string  , vector<int>  , less<>> m3;
    m3["cat"].push_back(34);   //way of insertion , access , looping depends on type of data structure we use for value . for ex - here we have vector
                                // hence we used push_back for insertion.
    m3["apple"].push_back(56);
    m3["apple"].push_back(45); //apple can store two values because we have used vector data structure
    m3.insert(std::make_pair("apple" , 45)); //this will not work
    cout << endl << "m3 operation - " << endl;
    for(auto i:m3)
    {
        cout<<i.first << "-> " ;
        for(auto j:i.second)
            cout << j << " " ;
        cout << endl;
    }
    return 0 ;


}
