## std::queue
---
defined in header \<queue\>


Queue class is a type of container adaptors that gives programer the functionality of a queue, with FIFO queue(First In First Out) - a new element is added at end and   is removed from adapter when all elements before it are previously removed.

#### Member function
---
(constructor) 
* default ```queue() : queue(Container()) { } ```
* copyconstructor
* move constructor
---
(destructor)
* default ```~queue();```
---
operator=
replace the stack with other
```queue = std::move(otherQueue.queue)```


#### Element access
---
front - return reference to the first element of queue
back - return reference to the last element of queue

#### Capacity
---
* Empty - return true if container is empty
* size - check the actual size (number) od elements and return it

#### Modifiers
---
* push - push element at the end of queue
* pop - remove the first element
* emplace - construct element at the end of the queue
* swap - swap elements of two given containers, might be diffrent size
```std::swap(q1, q2);'''


##### Example
---
```
#include <iostream>
#include <stack>
using namespace std;
void showQueue(queue<int> q) {
    queue <int> tempQ = q;
    while(!tempQ.empty()) {
        cout << tempQ.front() << " ";
        tempQ.pop();
    }
    cout << '\n';
}
int main() {
    queue<int> q;
    q.push(3);
    q.push(2);
    q.push(1);
    cout << "The queue is: ";
    showQueue(q);
    cout << "\nq.size(): " << q.size();
    cout << "\nq.front(): " << q.front();
    cout << "\nq.back(): " << q.back();
    cout << "\nq.pop(): ";
    q.pop();
    showQueue(q);
    queue<int> q2;
    q2.push(5);
    swap(q, q2);
    cout << "The swap queue is: ";
    showQueue(q);
    return 0;
}
```

---
##### Output:
>The queue is : 	3	2	1
>q.size() : 3
>q.front() : 3
>q.back() : 1
>s.pop() : 	2	1
>The swap queue is: 5




