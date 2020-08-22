<!-- .slide: data-background="#111111" -->

# Algorytmy

___

## Typy algorytmów

Podaj, jakie znasz algorytmy:

* <!-- .element: class="fragment fade-in" --> Niemodyfikujące sekwencji?
* <!-- .element: class="fragment fade-in" --> Modyfikujące sekwencje?
* <!-- .element: class="fragment fade-in" --> Partycjonujące?
* <!-- .element: class="fragment fade-in" --> Sortujące?
* <!-- .element: class="fragment fade-in" --> Przeszukujące binarnie?
* <!-- .element: class="fragment fade-in" --> Operujące na kopcu (ang. Heap)?
* <!-- .element: class="fragment fade-in" --> Min/max?
* <!-- .element: class="fragment fade-in" --> Porównujące?
* <!-- .element: class="fragment fade-in" --> Dokonujące permutacji?
* <!-- .element: class="fragment fade-in" --> Numeryczne?

___

## Quiz

Korzystając z [cppreference](https://en.cppreference.com/w/) odpowiedz na pytania:

* <!-- .element: class="fragment fade-in" --> Jaką złożoność ma <code>std::sort()</code>?
* <!-- .element: class="fragment fade-in" --> Jaki algorytm użyjesz dla połączenia 2 kontenerów naprzemiennie?
* <!-- .element: class="fragment fade-in" --> Jaki algorytm użyjesz, aby zsumować wszystkie elementy w <code>std::vector</code>?
* <!-- .element: class="fragment fade-in" --> Jaki algorytm użyjesz, aby pomnożyć 2 kontenery ze sobą?
* <!-- .element: class="fragment fade-in" --> Jaki algorytm użyjesz, aby usunąć liczby parzyste?
* <!-- .element: class="fragment fade-in" --> Jaki algorytm użyjesz, aby wypełnić strukturę wartościami od 0 do n?
* <!-- .element: class="fragment fade-in" --> Jaki algorytm użyjesz, aby zawsze na 1. miejscu (0 index) znajdował się największy element?
* <!-- .element: class="fragment fade-in" --> Jaki algorytm użyjesz, by wyszukać czy dana liczba znajduje się w posortowanym kontenerze?
* <!-- .element: class="fragment fade-in" --> Jaki algorytm użyjesz, aby podzielić kontener na 2 zakresy, zawierające mniejsze i większe wartości niż 10?
* <!-- .element: class="fragment fade-in" --> Jaki algorytm użyjesz, aby zmienić kolejność 2 elementów w kontenerze?

___

## std::rotate

[Materiał wideo z przykładem](https://youtu.be/W2tWOdzgXHA?t=560)

___

## Zadanie 1

Napisz funkcję, która przyjmie `std::vector<int>&`, zmienną `int value`, oraz zmienną `int new_pos`. Funkcja powinna odnaleźć `value` w `std::vector<int>` i jeżeli ją znajdzie wstawić ją na nowe miejsce `new_pos`, odpowiednio przesuwając resztę elementów by nie zaburzyć ich sekwencji. Następnie zwróć `true`, jeżeli proces się udał, lub `false`, jeżeli nie dało się zmienić kolejności (np. nie istnieje wartość).

`bool ChangePos(std::vector<int>& vec, int value, int new_pos)`
<!-- .element: class="fragment fade-in" -->

___

## Rozwiązanie 1

```C++
bool ChangePos(std::vector<int>& vec, int value, int new_pos) {
    if (new_pos >= vec.size())
    if (new_pos >= vec.size()){
        return false;
    }

    auto begin = vec.begin();
    auto end = vec.end();
    auto it = std::find(begin, end, value);
    if (it == end)
    if (it == end){
        return false;
    }

    auto item_pos = std::distance(begin, it);
    if (item_pos > new_pos) {
        std::rotate(begin + new_pos, begin + item_pos, begin + item_pos + 1);
    } else {
        std::rotate(begin + item_pos, begin + item_pos + 1, begin + new_pos + 1);
    }

    return true;
}
```

___

## std::stable_partition

[Przykład wideo](https://youtu.be/W2tWOdzgXHA?t=798)

___

## Zadanie 2

Napisz funkcję, która przyjmie dwa `std::vector<int>` oraz zmienną `int`. Pierwszy `std::vector<int>` zawiera kontener na którym operujemy, drugi zawiera wartości jakie chcemy przenieść, a wartość `int` to numer indexu, na który chcemy przenieść wartości.

`void ChangePos(std::vector<int>& vec, const std::vector<int>& values, int position)`
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Rozwiązanie 2

```C++
void ChangePos(std::vector<int>& vec, const std::vector<int>& values, int new_pos) {
    auto pred {[&](auto& el){
        return (std::find(values.begin(), values.end(), el) == values.end());
    }};

    auto middle = vec.begin() + new_pos + values.size() - 1;
    std::stable_partition(vec.begin(), middle, pred);
    std::stable_partition(middle, vec.end(), [&](auto& el){ return !pred(el); });
}

void PrintVec(const std::vector<int>& vec) {
    for (const auto el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    PrintVec(vec);
    ChangePos(vec, {1, 3, 9}, 4);
    PrintVec(vec);

    return 0;
}
```

___

## Zadanie 3

Napisz funkcję Gather, która przyjmie `std::vector<char>` oraz spowoduje, że
wszystkie wystąpienia `*` pojawią się w środku `std::vector<char>`.

Input: `std::vector<char> vec {'*', '$', '@', '*', '#', '@', '^', '*', '(', ')', '$', '*'};`
<!-- .element: class="fragment fade-in" -->

Output: `$ @ # @ * * * * ^ ( ) $`
<!-- .element: class="fragment fade-in" -->
___
<!-- .slide: style="font-size: 0.9em" -->

## Rozwiązanie 3

```C++
void Gather(std::vector<char>& vec) {
    auto pred {[&](auto& el){
        return el != '*';
    }};

    auto middle = vec.begin() + vec.size() / 2;
    std::stable_partition(vec.begin(), middle, pred);
    std::stable_partition(middle, vec.end(), [&](auto& el){ return !pred(el); });
}

void PrintVec(const std::vector<char>& vec) {
    for (const auto el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<char> vec {'*', '$', '@', '*', '#', '@', '^', '*', '(', ')', '$', '*'};
    PrintVec(vec);
    Gather(vec);
    PrintVec(vec);

    return 0;
}
```

___

## Zadanie 4

Napisz funkcję `GetVec(size_t count)`, która zwróci `std::vector<int>` z wartościami od `10` do `10 + n`, inkrementując je co 1. Następnie napisz drugą funkcję `int Multiply(std::vector<int> vec)`, która zwróci wartość równą iloczynowi każdego elementu `std::vector<int>`.

Input: `GetVec(7)`
<!-- .element: class="fragment fade-in" -->

Output: `{10, 11, 12, 13, 14, 15, 16}`
<!-- .element: class="fragment fade-in" -->

Input: `Multiply(vec)`
<!-- .element: class="fragment fade-in" -->

Output: `57657600`
<!-- .element: class="fragment fade-in" -->

___

## Rozwiązanie 4

```C++
std::vector<int> GetVec(size_t count) {
    std::vector<int> vec(count);
    std::iota(begin(vec), end(vec), 10);
    return vec;
}

int Multiply(const std::vector<int>& vec) {
    return std::accumulate(begin(vec), end(vec), 1, std::multiplies<int>());
}

int main() {
    std::cout << Multiply(GetVec(7)) << '\n';

    return 0;
}
```

___

## Q&A
