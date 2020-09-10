# Exercise 2

## Adaptors

Container adaptors are not full container classes, but classes that provide a specific interface relying on an object of one of the container classes (such as deque or list) to handle the elements. The underlying container is encapsulated in such a way that its elements are accessed by the members of the container adaptor independently of the underlying container class used.
There are three containers adaptors in STL:

* stack
* queue
* prority_queue

___

## **stack**

**The stack** container is used to replicate stacks in c++, insertion and deletion is always performed at the top of the stack.

* Adapts container and provides LIFO (Last in - first out) interface
* Container type has to supports methods as:
  * push_back
  * pop_back
  * back
* Methods:
  * to / pop
  * push / emplace
  * swap / empty / size

### Example of stack

``` c++
    std::stack<int> st;
    st.push(12);    //now top = 12
    st.push(19);    //now top = 19
    st.push(20);    //now top = 20
    std::cout << st.top() << " " << st.size() << '\n';
    st.pop();       //now top = 19
    std::cout << st.top() << " " << st.size() << '\n';
```

`OUTPUT: 20 3 19 2`

### Usage of stack

* Simple reversing a word (adding word to a stack, and then reading it backward)
* Expression Conversion(Infix to Postfix, Postfix to Prefix etc)
* Iterative Tree traversal (Inorder traversal)

___

## **queue**

**The queue** container is used to replicate queue in C++, insertion always takes place at the back of the queue and deletion is always performed at the front of the queue.

* Provides FIFO (First in - first out) interface
* Container type has to supports methods as:
  * push_back
  * pop_front
  * back
  * front
* Methods:
  * front / back
  * push / emplace / pop
  * swap / empty / size

### Example of queque

``` c++
    std::queue<int> q;

    q.push(2);      //now front = 2
    q.push(3);      //now front = 3
    std::cout << q.front() << '\n';
    q.pop();        //now front = 3
    std::cout << q.front() << '\n';
```

`OUTPUT: 2 3`

### Usage of queque

* Iterative tree traversal (Levelorder tree traversal)
* Serving requests on a single shared resource, like a printer, CPU task scheduling etc.
* In real life scenario, Call Center phone systems uses Queues to hold people calling them in an order, until a service representative is free.
* Handling of interrupts in real-time systems. The interrupts are handled in the same order as they arrive i.e First come first served.

___

## **priority_queue**

**priority_queue** is just like a normal *queue* except the element removed from the queue is always the greatest among all the elements in the queue, thus this container is usually used to replicate **Max Heap** in C++. Elements can be inserted at any order and it have **O(log(n))** time complexity for insertion.

* Elements are prioritized accodring to comparator
* Container type has to supports methods as:
  * push_back
  * pop_back
  * back
* Methods:
  * top
  * push / emplace / pop
  * swap / empty / size

### Example of priority_queue

``` c++
    std::priority_queue<int> pq1;

    pq1.push(30);  // inserts 30 to pq1 , now top = 30
    pq1.push(40);  // inserts 40 to pq1 , now top = 40 ( maximum element)
    pq1.push(90);  // inserts 90 to pq1 , now top = 90
    pq1.push(60);  // inserts 60 to pq1 , top still is 90
    std::cout << pq1.top() <<' ';
    pq1.pop();  // removes 90 ( greatest element in the queue)
    std::cout << pq1.top() << '\n';
```

`OUTPUT: 90 60`

___
