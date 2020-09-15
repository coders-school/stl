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
  
 Additionally, the container must be sequential (stl containers that fulfill these requirements: string, array, vector, deque, foward_list, list).  
| Stack Interface | Description |
| :---        |    ----:   |  
| top()      | reads the element that will be popped first        | 
|empty()  | checks if the stack is empty        | 
|size()  | returns the size of the stack        | 
|push()  | adds the element to the stack        | 
|pop()  | removes the element from the stack        | 
|emplace()  | constructs the element in-place and adds to the structure        | 

### Examples of usage
- can be used to simulate putting stuff into backpack
