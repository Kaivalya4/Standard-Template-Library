/* std::queue -
 -> It is First in and First out data structure .
 -> we can push(insert) at rear and pop (remove) at front
 -> it gives font , back , push , pop , empty , size.
*/

#include<iostream>
#include<queue>

using namespace std;

void print(std::queue<int> queue1)
{
    while(!queue1.empty())
    {
        cout<< queue1.front();
        queue1.pop();      // we are poping an element in front
    }
    cout<<endl;
    /*
    Below code will generate error as we can not iterate over queue
    Hence we used pop() above . we are poping elements in queue to get new value present at front
    for(int i: queue1)
        cout<< i << endl;
    */
}

int main()
{
    std::queue<int> queue1;

    queue1.push(2);
    queue1.push(3);
    queue1.push(4);
    print(queue1);
    return 0;
}
