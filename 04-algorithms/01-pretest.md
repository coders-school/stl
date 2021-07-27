
<!-- .slide: data-background="#111111" -->

# Pre-test 📝

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## 1/3 Które stwierdzenia o `std::rotate` są prawdziwe?

1. Zwraca `void`
2. Jest podobny algorytm wykonujący rotację w prawo - `std::rrotate`
3. Można wykonać rotację w prawo podając specjalny argument
4. Wykonuje rotację w lewo

___

## 2/3 Które stwierdzenia o poniższym kodzie są prawdziwe?

```cpp
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v{3, 1, 4, 2, 5};
    auto result = none_of(v.begin(), v.end(), [](auto e){ return e < 5; });
}
```

1. Kod się nie kompiluje
2. Zwraca `true`
3. Zwraca `ForwardIt` do elementu na 4-tej pozycji
4. Zwraca `false`
5. Nastąpi segmentation fault

___

## 3/3 Co robi `std::partial_sort(first, middle, last)`?

1. Wykonuje algorytm quick sort na zakresie od `first` do `last` używając `middle` jako pivot
2. Sortuje tylko elementy, które są większe od `middle`
3. Ustawia `middle` na właściwej pozycji, a wszystko mniejsze od niego jest przed nim, większe - za nim
4. Sortuje tylko zakres `[middle, last)`
5. Sortuje tylko zakres `[first, middle)`
