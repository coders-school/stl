<!-- .slide: data-background="#111111" -->

# Algorytmy

___

## Typy algorytmów

Podaj, jakie znasz algorytmy:

* Niemodyfikujące sekwencji?
* Modyfikujące sekwencje?
* Partycjonujące?
* Sortujące?
* Przeszukujące binarnie?
* Operujące na kopcu (ang. Heap)?
* Min/max?
* Porównujące?
* Dokonujące permutacji?
* Numeryczne?

___

## Quiz

Korzystając z `cppreferece` odpowiedz na pytania:
* Jaką złożoność ma `std::sort()`?
* Jaki algorytm użyjesz dla połączenia 2 kontenerów naprzemiennie?
* Jaki algorytm użyjesz, aby zsumować wszystkie elementy w `std::vector`?
* Jaki algorytm użyjesz, aby pomnożyć 2 kontenery ze sobą?
* Jaki algorytm użyjesz, aby usunąć liczby parzyste?
* Jaki algorytm użyjesz, aby wypełnić strukturę wartościami od 0 do n?
* Jaki algorytm użyjesz, aby zawsze na 1. miejscu (0 index) znajdował się największy element?
* Jaki algorytm użyjesz, by wyszukać czy dana liczba znajduje się w posortowanym kontenerze?
* Jaki algorytm użyjesz, aby podzielić kontener na 2 zakresy, zawierające mniejsze i większe wartości niż 10?
* Jaki algorytm użyjesz, aby zmienić kolejność 2 elementów w kontenerze?

___

## std::rotate

https://youtu.be/W2tWOdzgXHA?t=560

___

## Zadanie 1

Napisz funkcję, która przyjmie `std::vector<int>&`, zmienną `int value`, oraz zmienną `int new_pos`. Funkcja powinna odnaleźć `value` w `std::vector<int>` i jeżeli ją znajdzie wstawić ją na nowe miejsce `new_pos`, odpowiednio przesuwając resztę elementów by nie zaburzyć ich sekwencji. Następnie zwróć true, jeżeli proces się udał, lub false, jeżeli nie dało się zmienić kolejności (np. nie istnieje wartość).

`bool ChangePos(std::vector<int>& vec, int value, int new_pos)`

___

## Rozwiązanie 1

```C++
bool ChangePos(std::vector<int>& vec, int value, int new_pos) {
    if (new_pos >= vec.size())
        return false;

    auto begin = vec.begin();
    auto end = vec.end();
    auto it = std::find(begin, end, value);
    if (it == end)
        return false;

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

https://youtu.be/W2tWOdzgXHA?t=798

___

## Zadanie 2

Napisz funkcję, która przyjmie dwa `std::vector<int>` oraz zmienną `int`. Pierwszy `std::vector<int>` zawiera kontener na którym operujemy, drugi zawiera wartości jakie chcemy przenieść, a wartość `int` to numer indexu, na który chcemy przenieść wartości.

`void ChangePos(std::vector<int>& vec, const std::vector<int>& values, int position)`

___

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

Input : `std::vector<char> vec {'*', '$', '@', '*', '#', '@', '^', '*', '(', ')', '$', '*'};`
Output: `$ @ # @ * * * * ^ ( ) $`
___

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

Napisz funkcję `GetVec(size_t count)`, która zwróci `std::vector<int>` z wartościami `od 10 do 10 + n`, inkrementując je co 1. Następnie napisz drugą funkcję `int Multiply(std::vector<int> vec)`, która zwróci wartość równą iloczynowi każdego elementu `std::vector<int>`.

Input: `GetVec(7)`
Output: `{10, 11, 12, 13, 14, 15, 16}`
Input: `Multiply(vec)`
Output: `57657600`

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

Q&A
