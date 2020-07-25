#include "sort.hpp"

deq lengthSort(const flist& flist) {
    auto myList = flist;
    myList.sort(cmp);
    deq myDeque(myList.begin(), myList.end());
    return myDeque;
}
