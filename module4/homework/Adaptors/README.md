# Adaptors
They are used as container wrappers. That means they are not independent containers, but they use them underneath. Adaptors allow you to use a normal container as if it was a certain data structure. If you use adaptor you can only use it's interface, the container that is underneath is now inaccesible.

- Stack  
In order to use this adaptor the container which you want to transform must support these operations:
  - back()
  - push_back()
  - pop_back()  
  
  Additionally, the container must be sequential (stl containers that fulfill these requirements: string, array, vector, deque, foward_list, list).
