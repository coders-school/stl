
<!-- .slide: data-background="#111111" -->

# Pre-test 📝

## Odpowiedzi

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## 1/3 Które stwierdzenia o `std::rotate` są prawdziwe?

1. <!-- .element: class="fragment highlight-red" --> Zwraca <code>void</code>
2. <!-- .element: class="fragment highlight-red" --> Jest podobny algorytm wykonujący rotację w prawo - <code>std::rrotate</code>
3. <!-- .element: class="fragment highlight-red" --> Można wykonać rotację w prawo podając specjalny argument
4. <!-- .element: class="fragment highlight-green" --> Wykonuje rotację w lewo

___

## 2/3 Które stwierdzenia o poniższym kodzie są prawdziwe?

```cpp
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v{3, 1, 4, 2, 5};
    auto result = none_of(v.begin(), v.end(), [](auto e){ return e < 5; })
}
```

1. <!-- .element: class="fragment highlight-red" --> Kod się nie kompiluje
2. <!-- .element: class="fragment highlight-red" --> Zwraca <code>true</code>
3. <!-- .element: class="fragment highlight-red" --> Zwraca <code>ForwardIt</code> do elementu na 4-tej pozycji
4. <!-- .element: class="fragment highlight-green" --> Zwraca <code>false</code>
5. <!-- .element: class="fragment highlight-red" --> Nastąpi segmentation fault

___

## 3/3 Co robi `std::partial_sort(first, middle, last)`?

1. <!-- .element: class="fragment highlight-red" --> Wykonuje algorytm quick sort na zakresie od <code>first</code> do <code>last</code> używając <code>middle</code> jako pivot
2. <!-- .element: class="fragment highlight-red" --> Sortuje tylko elementy, które są większe od <code>middle</code>
3. <!-- .element: class="fragment highlight-red" --> Ustawia <code>middle</code> na właściwej pozycji, a wszystko mniejsze niego jest przed nim, większe - za nim
4. <!-- .element: class="fragment highlight-red" --> Sortuje tylko zakres <code>[middle, last)</code>
5. <!-- .element: class="fragment highlight-green" --> Sortuje tylko zakres <code>[first, middle)</code>
