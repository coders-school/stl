## std::stack
---
defined in header \<stack\>


Stack class is a type of container adaptors that gives programer the functionality of a stack, with LIFO queue(Last In First Out) - a new element is added at one end and (top) an element is removed from that end only.

#### Member function
---
(constructor) 
* default ```stack() : stack(Container()) { } ```
* copyconstructor
* move constructor
---
(destructor)
* default ```~stack();```
---
operator=
replace the stack with other
```stack = std::move(otherStack.stack)```


#### Element access
---
top - return reference to the top element of stack

#### Capacity
---
* Empty - return true if container is empty
* size - check the actual size (number) od elements

#### Modifiers
---
* push - push element to the top of stack
* pop - remove the top element
* emplace - construct element on top of the stack


##### Example
---
```\#include <iostream>
\#include <stack>
using namespace std; 
  
void showstack(stack <int> s) { 
    while (!s.empty()) { 
        cout << s.top() << " "; 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () { 
    stack <int> s; 
    s.push(3); 
    s.push(2); 
    s.push(1);  
    cout << "The stack is: "; 
    showstack(s);
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
    return 0; 
}```

---

##### Output:
>The stack is : 	1	2	3
>s.size() : 3
>s.top() : 1
>s.pop() : 	2	3
>
