#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    q.push(2);      //now front = 2
    q.push(3);      //now front = 3
    std::cout << q.front() << '\n';
    q.pop();        //now front = 2
    std::cout << q.front() << '\n';

    return 0;
}
