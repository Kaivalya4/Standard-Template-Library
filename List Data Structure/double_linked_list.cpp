/*  list in stl -
-> list is sequence container(there are three types of container) that allow non contiguous memory allocation
-> faster as compared to other sequence container (vector , forward list, deque) in terms of insertion , deletion , moving elements in any position provided
   we have the iterator of the position

-> operator = , assign , front , back , empty , size , max_size , clear , insert, emplace , push_back  pop_back , push_front, pop_front , reverse , sort ,
   merge , splice , unique , remove , remove_if , resize;
*/

#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> list1 = {5,2,3,6};
    list<int> list2 = {1,2,3,4,5};

    for(auto &lst1 : list1)
        cout << lst1 << " ";
    cout<<endl;

    for(int i : list2)
        cout<< i << " ";
    cout<<endl;

    // copy list1 in list2 and discard initial elements of liste -
    list2 = list1;
    for(auto &lst2 : list1)
        cout << lst2 << " ";
    cout<<endl;

    list<int> list3 ;
    list<int> :: iterator it;
    for(int i=0 ; i<3 ;i++)
        list3.push_front(i);   // adds elements at front of the list
    for(int i=0 ; i<3 ; i++)
        list3.push_back(i+10);  // adds elements at end of the list
    it = list3.begin();      // begin() return the iterator pointing to the begining of the list
    for(it ; it !=list3.end() ; it++) // end() returns the iterator pointing to the last element of the list
        cout<< *it << " ";
    cout<< endl;

    it = list3.begin();
    list1.insert(it , -2);    // insert element before the element pointed by the iterator
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;
    it = list3.begin();
    list1.insert(++it , -3); // insert -3 between first and second element i.e. before to pointer pointed by it
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;
    //another way of insert -
    it = list3.begin();
    list3.insert(it,2 ,  30 );   //insert 2 element of value 30 before it is pointing to
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    list2.assign(5,44); // adds 5 elemnts to list2 each of value 44 removing previous elements
    for(it = list2.begin() ; it !=list2.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    cout<< " before erasing last element of the list3 is : " << list3.back(); // back return reference to the last element of the list
    list3.pop_back();  // removes last element of the list
    cout<< endl << "after pop_back() last element is : "<< list3.back();

    cout<<endl << " before erasing first element of the list3 is : " << list3.front(); // front return reference to the first element of the list
    list3.pop_front();  // removes first element of the list
    cout<< endl << "after pop_front() last element is : "<< list3.front();

    cout<<endl << " before erase  element of the list3 is : " ;
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;
    it = list3.begin();
    list3.erase(it); // remove elements where iterators points
    cout<< " after erase  element of the list3 is : " ;
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    cout<<endl << " before remove  element of the list3 is : " ;
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;
    list3.remove(10); // remove all elements with value 30
    cout<< " after after  element of the list3 is : " ;
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    list3.remove_if([](int a){return a < 0 ;});
    cout<< "list3 after remove_if with condition (int a){return a < 0 } : ";
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    list3.empty() ? cout<< "list3 is empty" : cout<< "list3 is not empty " << endl ; // boolean operator - returns 1 or True if list is empty otherwise 0 or False

    list3.reverse(); // reverse the list
    cout<< " after applying reverse  element of the list3 is : " ;
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    list3.sort(); // sort the element in ascending order
    cout<< " after applying sort  element of the list3 is : " ;
    for(it = list3.begin() ; it !=list3.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    cout<< "total elements in the list are or size of the list3 is : " << list3.size();
    cout<<endl;

    cout<< list3.max_size() << endl;  //total elements possible int the list

    list1.merge(list2);   // it basically concats list2 after list1
    cout<<  "list1 after merge is : " ;
    for(it = list1.begin() ; it !=list1.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    list<int> demolist ={5,1,9} ;
    list1.splice(list1.begin(),demolist); // will copy element of demolist after the beggining of list1 . Basically we can provide iterator pointing to any position in list1
    cout<< "After Splice after we have in list1 : ";
    for(it = list1.begin() ; it !=list1.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    list1.unique(); // will remove adjacent duplicate element
    cout<< "list1 after unique operation : ";
    for(it = list1.begin() ; it !=list1.end() ; it++)
        cout<< *it << " ";
    cout<< endl;

    return 0;
}
