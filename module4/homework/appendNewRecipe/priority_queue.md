## std::priority_queue
---
defined in header \<queue\>


Queue class is a type of container adaptors that gives programer the functionality close to heap, with adittional advantage: the heap can't be accidently invalidatet.

#### Member function
---
(constructor) 
* default ```priority_queue() : priority_queue(Compare(), Container()) { } ```
* copy constructor
* move constructor
---
(destructor)
* default ```~priority_queue();```
---
operator=
replace the stack with other
```priorityQueue = std::move(otherPriorityQueue.priorityQueue)
```

#### Element access
---
top - return reference to the top element of priority queue

#### Capacity
---
* Empty - return true if container is empty
* size - check the actual size (number) od elements and return it

#### Modifiers
---
* push - push element to container and sort all queue
* pop - remove the top element in container and sort all queue
* emplace - construct element at the end of the queue
* swap - swap elements of two given containers, might be diffrent size
```std::swap(q1, q2);
```

##### Example
---
```#include <iostream>
#include <queue>
using namespace std;
void showQueue(priority_queue<int> q) {
    priority_queue <int> tempQ = q;
    while(!tempQ.empty()) {
        cout << tempQ.top() << " ";
        tempQ.pop();
    }
    cout << '\n';
}
int main() {
    priority_queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "The priority queue is: ";
    showQueue(q);
    cout << "\nq.size(): " << q.size();
    cout << "\nq.top(): " << q.top();
    cout << "\nq.pop(): ";
    q.pop();
    showQueue(q);
    Priority_queue<int> q2;
    q2.push(5);
    swap(q, q2);
    cout << "The swap queue is: ";
    showQueue(q);
    return 0;
}
```

---
##### Output:
>The priority queue is : 	3	2	1
>q.size() : 3
>q.top() : 3
>s.pop() : 	2	1
>The swap queue is: 5




