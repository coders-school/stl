#include <iostream>
#include <stack>

int main() {
    std::stack<int> st;
    st.push(12);    //now top = 12
    st.push(19);    //now top = 19
    st.push(20);    //now top = 20
    std::cout << st.top() << " " << st.size() << '\n';
    st.pop();       //now top = 19
    std::cout << st.top() << " " << st.size() << '\n';

    return 0;
}
