#include<iostream>
#include<queue>

using namespace std;

void see(queue<int> q)
{
    for(int i=0 ; i<5 ; i++)
    {
        cout<< q.front() << " ";  // front() - returns the pointer reference of the front(first) element of the queue
        //as function is called by value . Hence any changes caused here is affect the original queue
        q.pop() ;        //pop() - removes elements from the front side of the queue
    }
}
int main()
{
    /*
    Below line will generate error . This is initialization is possible in other many containers but not in queue
    queue<int> q1 ={1,2,3,4,5};
    */
    queue<int> q1 , q2;
    cout<<"elements added in the q1 5 times using push() : ";
    for(int i=0 ; i<5 ; i++)
    {
        q1.push(i+1); // Queue us FIFO . Hence element is added at rear(back)
    }
    for(int i=0 ; i<4 ; i++)
    {
        q2.push(i+10);
    }

    //calling function(by variable) to see elements of queue -
    cout<< "Elements in the q1 are : ";
    see(q1);
    cout<<endl;

    //empty() - boolean function that returns 1 when function is empty -
    q1.empty() ? cout<< "q1 is empty " : cout<< "q1 is not empty ";
    cout<<endl;

    cout<< "first element in the queue is : ";
    cout<< q1.front() << endl;

    cout<< "The last element in queue is : ";
    cout<<q1.back() << endl;      //returns the pointer reference of the last element of the queue

    cout<< "The size of the queue is : ";
    cout<< q1.size() << endl << endl;     // returns the size of the queue


    // swap() - swap the elements of q1 to q2 and elements of q2 to q1 -
    cout<< "elements of q1 before swapping with q2 : " ;
    see(q1);
    cout<<endl;
    cout<< "elements of q2 before swapping with q1 : " ;
    see(q2);
    cout<<endl;
    q1.swap(q2);
    cout<< "elements of q1 after swapping with q2 : " ;
    see(q1);
    cout<<endl;
    cout<< "elements of q2 after swapping with q1 : " ;
    see(q2);

    return 0;
}
