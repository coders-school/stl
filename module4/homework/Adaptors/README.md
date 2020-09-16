# Adaptors
They are used as container wrappers. That means they are not independent containers, but they use them underneath. Adaptors allow you to use a normal container as if it was a certain data structure. If you use adaptor you can only use it's interface, the container that is underneath is now inaccesible.  
**Caution!**
Adaptors do not support methods such as:
  - begin()  
  - end()  
  
That means you **cannot** use stl algorithms or for ranged loops with:
- Stack  
- Queue  
- Priority Queue  
## Stack
Stack is a LIFO structure which means Last In First Out. The last element that will be added to the structure also will be the first one to be removed from the structure.  
Example:  
  ```cpp
  #include <stack>
  
  std::stack<int, std::vector<int>> stack{{1, 5, 8, 3, 4}}; //the order of the elements is preserved,
                                                            //1 will be removed as last from the stack
  std::cout << stack.top() << '\n'; // 4  
  stack.pop();  
  std::cout << stack.top() << '\n'; // 3  
  stack.push(10);  
  std::cout << stack.top() << '\n'; // 10  
  ```
  
In order to use this adaptor the container which you want to transform must support these operations:
  - back()
  - push_back()
  - pop_back()  
  
 Additionally, the container must be sequential (stl containers that fulfill these requirements: **string, array, vector, deque, foward_list, list**).  
| Stack Interface | Description |
| :---        |    :----   |  
|top()      | reads the element that will be popped first        | 
|push()  | adds the element to the stack        | 
|pop()  | removes the element from the stack        | 
|emplace()  | constructs the element in-place and adds to the structure        | 
|empty()  | checks if the stack is empty        | 
|size()  | returns the size of the stack        |  

#### Examples of usage
- can be used to simulate putting stuff into backpack (elements added first will be on the bottom)
- can be used to simulate building a tower (elements added first will be on the bottom)

## Queue
Queue is a FIFO structure which means First In First Out. The first element that will be added to the structure will also be the first one to be removed from the structure.
Example:
  ```cpp
  #include <queue>
  
  std::queue<int, std::list<int>> queue{{3, 6, 2, 8, 1}};  // the order of the elements is preserved
                                                           // 3 will be removed from the queue as first
  std::cout << queue.front() << '\n'; // 3
  std::cout << queue.back() << '\n'; // 1
  queue.push(10);
  std::cout << queue.front() << '\n';  // 3
  std::cout << queue.back() << '\n';   // 10
  queue.pop();
  std::cout << queue.front() << '\n';  // 6
  std::cout << queue.back() << '\n';   // 10
  ```
  
 In order to use this adaptor the container which you want to transform must support these operations:
  - back()
  - front()  
  - push_back()
  - pop_front()  
  
Additionally, the container must be sequential (stl containers that fulfill these requirements: **deque, list**).  

| Queue Interface | Description |
| :---        |    :----   |  
|front()      | reads the first element    | 
|back()  | reads the last element      | 
|push()  | adds the element to the end of queue        | 
|pop()  | removes the element from the beginning of queue        | 
|emplace()  | constructs the element in-place and adds to the beginning of queue        | 
|empty()  | checks if the queue is empty        | 
|size()  | returns the size of the queue        |

#### Examples of usage
- can be used when working with printer  
- can be used to simulate the movement of the snake in the classical snake-game (single snake move could be removing one element from the end, and adding one element to the front)

## Priority Queue
Priority Queue is built like a heap data structure. It provides constant time lookup of the largest (by default) element. However, **adding & removing** elements is **logarithmic complexity**! This is due to the fact that when adding or inserting elements the order of the structure must be preserved and `std::heap_push` / `std::heap_pop` are called. This adapter gives us the guarantee that the heap data structure will not be malformed by any operations. We have to use this adapter with random access container.
Example:
  ```cpp
  #include <queue>
  
  std::priority_queue<int> pqueue{std::less<int>(), {5, 3, 1, 8, 10}};  // we must specify the Comparator in the c-tor
                                                                        // the elements will be sorted instantly
                                                                        // the order is descending 10, 8, 5, 3, 1
  std::cout << pqueue.top() << '\n';  //10
  pqueue.pop();
  std::cout << pqueue.top() << '\n'; //8
  pqueue.pop();
  std::cout << pqueue.top() << '\n'; //5
  ```
  
 If we would like to change the Comparator to std::greater (in which case the first element would be the smallest):
  ```cpp
  std::priority_queue<int, std::deque<int>, std::greater<int>> pqueue{std::greater<int>(), {5, 3, 1, 8, 10}};  
                                                                        // the elements will be sorted instantly
                                                                        // the order is now ascending 1, 3, 5, 8, 10
  std::cout << pqueue.top() << '\n';  //1
  pqueue.pop();
  std::cout << pqueue.top() << '\n'; //3
  pqueue.pop();
  std::cout << pqueue.top() << '\n'; //5
  ```
  
   In order to use this adaptor the container which you want to transform must support these operations:
  - front()  
  - push_back()
  - pop_back()  
  
  Additionally, the container must be sequential and it must support **Random Access Iterator** (stl containers that fulfill these requirements: **vector, deque**).  
  Priority Queue interface is the same as Stack interface:  
| Priority Queue Interface | Description |
| :---        |    :----   |  
|top()      | reads the first element in the structure     | 
|push()  | adds the element to the priority queue [calls c.push_back(); std::heap_push(begin(c), end(c), comp);]        | 
|pop()  | removes the element from priority queue [calls std::heap_pop(begin(c), end(c), comp); c.pop_back();]      | 
|emplace()  | constructs the element in-place, adds it and sorts the structure     |
|empty()  | checks if priority queue is empty        | 
|size()  | returns the size of the priority queue        |

#### Examples of usage
-   
- 
