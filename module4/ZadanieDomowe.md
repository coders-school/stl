# Zadanie domowe

___

## Zadanie 1 #1

Napisz funckję, która umożliwi zapisywanie nowych przepisów w pliku recipes.txt. Zwróć false, jeżeli nie uda się zapisać przepisu.

* Funkjca za 1 argument przyjmuje dane w `std::vector<std::string>`, który zawiera kolejne kroki przepisu.
* Funckja za 2 argument przyjmuje `std::list<std::string>` zawierającą nazwe składników.
* Funkjca za 3 argument przyjmuje dane w `std::deque<std::pair<size_t, char>>` zawierające informacje o ilości składnika i jego reprezentacji `g` -> gramy `m` mililirty, `s` -> szklanki.
  
```C++
bool AppendNewRecipe(std::vector<std::string> steps,
                          const std::list<std::string>& ingredients,
                          const std::deque<std::pair<size_t, char>>& amount);
```

___

## Zadanie1 #2

Input:

```C++
std::vector<std::string> steps{"Wsypać do miski 20 gram cukru",
                                "Dorzucić 1 szklankę mąki",
                                "Dokładnie wymieszać",
                                "Nalać 40ml rumu do kieliszka",
                                "Wypić kieliszek",
                                "Wysypać zawartość miski"};
std::list<std::string> ingredients{"cukru", "mąki", "rumu"};
std::deque<std::pair<size_t, char>> amount{
    {20, 'g'},
    {1, 's'},
    {40, 'm'}};
```

Oczekiwany format:

```note
Składniki:
20 gram cukru,
1 szklanka(i) mąki,
40ml rumu,

Kroki:
1) Wsypać do miski 20 gram cukru.
2) Dorzucić 1 szklankę mąki.
3) Dokładnie wymieszać.
4) Nalać 40ml rumu do kieliszka.
5) Wypić kieliszek.
6) Wysypać zawartość miski.
__________________________________
```

___

## Zadanie1 #3

Pomocnicze funkcje:

```C++
std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                          const std::deque<std::pair<size_t, char>>& amount);
```

każdy rekord wektora powinien zawierać gotową sekcje jednego składnika np: `20 gram cukru` lub `1 szklanka(i) mąki`.

```C++
std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);
```

Oczekujemy gotowego formatu, który można odrazu zapisać.

___

## Zadanie2

Poczytaj i stwórz krótką notatkę oraz przykład wykorzystania nastepujących adapetrów:

* stack
* queue
* priority_queue

Najciekawsze opracowanie nagordzę 30xp. drugie miejsce otrzyma 20xp a trzecie 10xp.

___
