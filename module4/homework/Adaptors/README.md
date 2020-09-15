## Adaptors
They are used as container wrappers. That means they are not independent containers, but they use them underneath. Adaptors allow you to use a normal container as if it was a certain data structure. If you use adaptor you can only use it's interface, the container that is underneath is now inaccesible.  
**Caution!**
Adaptors do not support methods such as:
  - begin()  
  - end()  
  
That means you cannot use stl algorithms or for ranged loops with
- Stack  
- Queue  
- Priority Queue  
# Stack
Stack is a LIFO structure which means Last In First Out. The last element that will be added to the structure also will be the first one to be removed from the structure.  
Example:  
  ```cpp
  std::stack<int, std::vector<int>> stack{std::vector<int>{1, 5, 8, 3, 4}};  
  std::cout << stack.top() << '\n'; // 4  
  s.pop();  
  std::cout << s.top() << '\n'; // 3  
  s.push(10);  
  std::cout << s.top() << '\n'; // 10  
  ```
  
In order to use this adaptor the container which you want to transform must support these operations:
  - back()
  - push_back()
  - pop_back()  
  
 Additionally, the container must be sequential (stl containers that fulfill these requirements: string, array, vector, deque, foward_list, list).  
 From now on the stack allows us to use this interface:  
   - top()             //allows us to read the element that will be popped first  
   - empty() / size()  
   - push()            //adds the element to the stack  
   - pop()             //removes the element from the stack  
    
