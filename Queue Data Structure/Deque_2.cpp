#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> dequename;
    dequename= {1,2,3,4,5};
    cout<< "element of dequename : ";
    for(int i: dequename)
        cout<< i << " ";
    cout<< endl;

    //creating de1ue with 10 empty elements i.e. value = 0 -
    deque<int> marks(10);
    cout<< "element of deque marks : ";
    for(int i: marks)
        cout<< i << " ";
    cout<< endl;

    //creating a deque with 10 elements, each element have value 3 :
    deque<int> marks1(10,3);
    cout<< "element of deque marks1 : ";
    for(int i: marks1)
        cout<< i << " ";
    cout<< endl;

    //Array to Deque-
    //start from first positon and go till 4th position -
    int arr[5] = {1,2,3,4,5};
    deque<int> ranks(arr , arr+4);
    cout<< "element of deque ranks : ";
    for(int i: ranks)
        cout<< i << " ";
    cout<< endl;

    //copy element of other deque to another
    deque<int> deque1(dequename);
    cout<< "elements of deque deque1 : ";
    for(int i=0 ; i<5 ; i++)
        cout<< deque1[i] << " ";
    cout<< endl;

    //push_back inserts element at the end(rear) of deque -
    deque1.push_back(6);
    cout<< "elements of deque deque1 after push_back : ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    //push_front() inserts elements at the front of deque -
    deque1.push_front(0);
    cout<< "elements of deque deque1 after push_font: ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    /*
    one way of insert() -
    we can insert an element at particulat position pointed by the iterator -
    (iteratr , value)
    */
    deque<int> :: iterator  it; // making an iterator
    it = deque1.begin();
    deque1.insert(it , -1 );
    cout<< "elements of deque deque1 after first insert: ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    /*
    another way of insert() -
    we can insert an element n number of times at front of deque -
    (iterator , n , vlaue)
    */
    it = deque1.begin();
    it++;
    deque1.insert(it , 2 , 007 );
    cout<< "elements of deque deque1 second insert : ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    /*
    another way of insert() -
    we can insert array elements from particular index to another index -
    (iterator , array_start_index , array_end_index)
    */
    int arr1[] = {10 , 20 ,30 , 40 ,50};
    it = deque1.end();
    deque1.insert(it , arr1 , arr1 +2); //first position to last position(included)
    cout<< "elements of deque deque1 third insert : ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    //assign(n,value) inserts value into deque n times . Any previous value(if there) will be erased .
    deque1.assign(8, 4 ); //first position to last position(included)
    cout<< "elements of deque deque1 after assign : ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    //pop_back() will deletes last(at rear'th position) element of deque -
    deque1.pop_back();
    cout<< "elements of deque deque1 after pop_back(): ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    //pop_front() will deletes first element of the deque -
    deque1.pop_front();
    cout<< "elements of deque deque1 after pop_front(): ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    //fillng some elements
    it = deque1.begin();
    deque1.insert(it+2 , -1 );
    cout<< "elements of deque deque1 after  insert: ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    //erase() function deletes the element which pointed by the iterator -
    it = deque1.begin();
    it = it+2;
    deque1.erase(it); // deleting the elements we just added;
    cout<< "elements of deque deque1 after erase: ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    //clear() removes all elements from the deque -
    deque1.clear();
    cout<< "elements of deque deque1 after clear: ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    //checking deque1 is empty or not . empty() is boolean function and returns true when deque is empty-
    deque1.empty() ? cout<<"it is empty " : cout<<"it is not empty"; // if we does no provide any cout statement then also program will run fine
                                                                        //as ? operator can have any expression as result
    cout<< endl;

    //size() - returns an int depicting number of elements in the deque
    //resize() can be applied to increase or decrease the current size of the deque -
    //max_size() - returns maz_size of a deque . It  is system and architecture dependent
    deque1 = {2,3,4,5};
    cout<< "size of deque1 after inserting {2,3,4,5} is : " << deque1.size() << endl;
    deque1.resize(2);
    cout<< "size of deque1 after resize(2) applied : " << deque1.size() << endl ;
    cout<< "max_size of deque is : " << deque1.max_size() << endl ;

    //swap() - swap all elements of  the two deque  -
    cout<< "element of dequename before swap : ";
    for(int i: dequename)
        cout<< i << " ";
    cout<< endl;
    cout<< "elements of  deque1 before swap : ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;
    deque1.swap(dequename);
    cout<< "element of dequename after swap with deque1 : ";
    for(int i: dequename)
        cout<< i << " ";
    cout<< endl;
    cout<< "elements of  deque1 after swap dequename : ";
    for(int i: deque1)
        cout<< i << " ";
    cout<< endl;

    return 0;
}
