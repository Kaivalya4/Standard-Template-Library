/* std::deque {Double ended queue}(see rema) - can compared with vector

-> it is an indexed sequence container just like a vector
-> it allows insertion(and del) at both end and beginning unlike a vector which allows push, pop only at rear(back).
-> unlike vector elements are not stored contiguous.
   In vector we have a large size array whereas in deque we have multiple arrays linked together.
   deque uses individual allocated fixed size array ,  with additional bookkeping , meaning index based access  to deque
   vecotr uses one pointer dereferencing(just like array - arr[1]) but deque use two pointer - one to know in which array our data is and second to access the data from the required cell of that array(just like 2d array)
-> the storage of deque is automatically expanded and contracted as needed.
-> Expansion of deque is cheaper(we just append extra array and linked it to previous one) than expansion of vector(where we have to double the size of array and copy old data)
-> size of all array will be same .

operation -
-> random access - O(1)
-> Insetion or removal of element form front and rear - O(1)
-> Insertion or removal of element (apart from front and rear) - O(n)
*/

#include<iostream>
#include<deque>

using namespace std;

void print(const std::deque<int> &dqu)
{
    int num ;
    for(int num : dqu)  // you will have to write int here otherwise it will be error and this num will be different from previous one
        cout << num << " ";
    cout<< endl;
}

int main()
{
    {
        std::deque<int> dqu = {2,3,4};
        dqu.push_front(1);
        dqu.push_back(5);
        print(dqu);
    }
    {
        std::deque<int> dqu = {2,3,4};
        dqu.pop_front();
        dqu.pop_back();
        print(dqu);
    }
    return 0;
}
