# Application of Stacks Queue and Priority Queue

## Stack & Queue 

Stack and Queue can be used to implement Depth First Search and Breadth First search algoritm, respectively. 
It can be use both for graphs and trees. 
For DFS in each iteration we are poping last element from stack and appending his children to the stack until stack is empty.
For BFS procedure is similar, but now we are using queue. 

## Priority Queue

Implemenation of complex Callback system. In our - so called - asynchronous program, we want to have a bunch of callbacks.
The problem is, that callbacks can be nested in our implementation (can have inner scopes). Many callbacks can be awakened by the same event,
and we want to awake first the most nested scope of callback (so we should have the highest priority, automatically). Depends on how much levels of nesting we have,
we can "grant" some high number of priority to all callbacks from the most nested scope, if the new scope comes in,
we can increase the priority for callbacks from that scope by an order of magnitude. Inside this scope, callbacks shall be awakened in FIFO manner.
