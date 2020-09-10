#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq1;

    pq1.push(30);  // inserts 30 to pq1 , now top = 30
    pq1.push(40);  // inserts 40 to pq1 , now top = 40 ( maximum element)
    pq1.push(90);  // inserts 90 to pq1 , now top = 90
    pq1.push(60);  // inserts 60 to pq1 , top still is 90
    std::cout << pq1.top() << ' ';
    pq1.pop();  // removes 90 ( greatest element in the queue)
    std::cout << pq1.top() << '\n';

    return 0;
}
