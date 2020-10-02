/* FORWARD LIST -
 Some operation -
 operator =, assign , front , empty , max_size , clear , insert_after ,  emplace_after ,reverse , sort , merge , splice_after , unique , remove ,
 remove_if , resize
*/
#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
    forward_list<int> list1 = {5,4,6,2}; //list intialization
    std::forward_list<int> list2 {1,2,3,4} ; //uniform initialization
    forward_list<int> :: iterator li; // iterator for list

    for(int i : list1 )
        cout<<i<<" ";
    cout<<endl;

    for(li = list2.begin(); li!= list2.end() ; li++)
        cout<< *li << " ";     // not giving * will give error
    cout<<endl;

    forward_list<int> list3;

    //Two ways of assign -
    list3.assign({10,20,30});
    for(li = list3.begin() ; li!= list3.end(); li++)
        cout<< *li << " ";
    cout<<endl;
    list3.assign(3,99); // set first 3 element = 99
    for(li = list3.begin() ; li!= list3.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    //This gives error -
//  cout<< list3.begin(); basically it is a pointer


    forward_list<int> :: iterator it1;
    //To insert element at the begining

    list1.push_front(1); // The value in this function copied to the address before to the current first element of container

    list1.emplace_front(3); // Here element is directly inserts at the address before the first element.
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    //To insert at any position
    it1 = list1.insert_after(list1.begin(),-1); // inserting -1 after the first element . value passed to the function is copied to specified postition
    list1.emplace_after(it1, -2); // inserting -2 after whcih it1 iterator is pointing to. . value passed to the function is directly inserted without any copy operation
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    list1.pop_front();   //deletes first element
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    it1= list1.begin();

    list1.erase_after(it1);  //erase after takes argument as iterator after which element to be deleted
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    list1.remove(6);  //delete all node whose element is 6. if it does not found any element to be removed then it does nothing(i.e. no error)
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    // below is lambda function for c++ in brackets
    list1.remove_if([](int a){return a>4;}) ; //removes element we specified only when the condition we give is true
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    list1.splice_after(list1.begin(),list2); // used to transfer one frwd list to other it places the element after the specified position
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    it1 = list1.begin();
    while(*it1 != 3)
        it1++;
    list1.splice_after(it1 , list3);  // add value of list3 after the position specified by the iterator it1
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    list1.reverse(); // reverse the elements of the forward list
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    list1.sort();    // sort the element in asscending order . I dont think there is any way to sort in descending order
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    cout<< "size of list1 is : " << distance(list1.begin(),list1.end()) << endl;  //distance is builtin function so if u are using your own created distance function then we will have to use std to call built in distance

    list1.unique();  // removes adjacent duplicate elements
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    list1.resize(2); // will keep first two elements
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;

    list1.resize(3);  // increase my list to size 7 , so an added element will become zero
    for(li = list1.begin() ; li!= list1.end(); li++)
        cout<< *li << " ";
    cout<< endl;
    return 0;
}
