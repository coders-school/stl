<!-- .slide: data-background="#111111" -->

# Złożoność obliczeniowa

<img src="https://res.cloudinary.com/practicaldev/image/fetch/s--NR3M1nw8--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://thepracticaldev.s3.amazonaws.com/i/z4bbf8o1ly77wmkjdgge.png">

___

## Definicja

Złożoność obliczeniowa - oszacowanie czasu wykonania algorytmu. Mierzymy liczbę operacji, następnie szukamy funkcji opisującej liczbę operacji w zależności od danych wejściowych. Notacja O jest szacowaniem z góry. Ponieważ chcemy tylko przybliżyć wartość, pomijamy wszelkiego rodzaju stałe, które nie mają znaczenie przy dużych n. Zatem `Ο(2n + 5)`, `Ο(2n)` i `Ο(n)` są uznawane za złożoność obliczeniową `O(n)`.

___

## Złożoność `O(1)`

Jest to tzw. złożoność stała, która jest niezależna od liczby danych wejściowych. Przy obliczeniu sumy ciągu arytmetycznego (kod poniżej), nie iterujemy po wszystkich elementach tablicy, zatem czas wykonania jest stały i niezależny od wielkości tablicy.

```C++
int sum(std::vector<int> vec) {
    if (vec.empty())
        return 0;

    return (vec.front() + vec.back()) * vec.size() / 2;
}

int main() {
    std::cout << sum({1, 2, 3, 4, 5, 6}) << std::endl;

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

Output: `21`
<!-- .element: class="fragment fade-in" -->
___
<!-- .slide: style="font-size: 0.9em" -->

## Złożoność `O(logn)`

Wyobraźmy sobie, że szukamy numeru telefonu naszego kolegi Andrzeja. Bierzemy książkę telefoniczną i otwieramy ją na środku i patrzymy, że wypada nam osoba o imieniu Kornelia. Wiemy, że Andrzej jest w pierwszej połowie książki adresowej, gdyż litera K jest dużo dalej w alfabecie niż litera A. Zatem znów otwieramy na środku pierwszej połowy i patrzymy, że widnieje tam imię Dominik. Więc powtarzamy nasze szukanie natrafiając w kolejnej części na Bartka, aż w końcu trafiamy na Andrzeja. Takie przeszukiwanie, w którym za każdym razem odrzucamy połowę zakresu jest właśnie zapisywane w notacji `O(logn)`.

```C++
std::vector<int> vec{1, 2, 3, 4, 5, 6};
std::cout << std::boolalpha
            << std::binary_search(begin(vec), end(vec), 2) << std::endl;
std::cout << std::boolalpha
            << std::binary_search(begin(vec), end(vec), 0) << std::endl;
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
true
false
```
<!-- .element: class="fragment fade-in" -->

___

## Złożoność `O(n)`

Wyboraźmy sobie teraz sytuację, że w książce adresowej szukamy numeru Żanety. Jednak nie będziemy teraz przeszukiwać binarnie, tylko sprawdzimy ile zajmie nam to, gdy będziemy szukać osoba po osobie. Więc zaczynamy od litery A i 4 dni później znajdujemy w końcu numer Żanety 🙂. Taka złożoność, gdzie sprawdzamy po kolei każdy element jest złożonością `O(n)`.

<!-- brak miejsca - dzielę na dwa -->
___
<!-- .slide: style="font-size: 0.85em" -->

## Złożoność `O(n)` - przykład

```C++
constexpr size_t samples = 1000000000;
constexpr size_t search_num = 987654321;
std::vector<int> vec(samples);
std::iota(begin(vec), end(vec), 0);

auto start = std::chrono::high_resolution_clock::now();
std::binary_search(begin(vec), end(vec), search_num);
auto stop = std::chrono::high_resolution_clock::now();
std::cout << "O(logn): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";

start = std::chrono::high_resolution_clock::now();
for (const auto el : vec) {
    if (el == search_num)
        break;
}
stop = std::chrono::high_resolution_clock::now();
std::cout << "O(n): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";

```

Example Output:
<!-- .element: class="fragment fade-in" -->

```C++
O(logn): 0 ns
O(n): 6949430300 ns
```
<!-- .element: class="fragment fade-in" -->

___

## Złożoność `O(nlog(n))`

Jest to tzw. złożoność liniowo-logarytmiczna, której czas wykonania jest wprost proporcjonalny do iloczynu danych wejściowych i ich logarytmu.
Wyobraźmy sobie teraz sytuację: próbujemy znaleźć numer Andrzeja w książce telefonicznej, ale nasz kolega zrobił nam psikus i pozamieniał strony. Teraz musimy ją posortować, zależy nam na czasie, więc chcemy to zrobić wydajnie. Dlatego wyrywamy kolejno strony z książki telefonicznej i wstawiamy je do nowej w zgodnej kolejności. Nie dość, że musimy zrobić taką operację dla `n` stron, to jeszcze musimy wstawiać je alfabetycznie, co zajmie nam `logn` czasu. Dlatego cały proces to `nlogn`.

___

## Złożoność `O(nlog(n))` - przykład

```C++
constexpr size_t samples = 1000000000;
std::vector<int> vec(samples);
std::iota(begin(vec), end(vec), 0);
std::random_device rd;
std::mt19937 gen(rd());

//Here our colleague mixed up phone book.
std::shuffle(begin(vec), end(vec), gen);
auto start = std::chrono::high_resolution_clock::now();
std::sort(begin(vec), end(vec));
auto stop = std::chrono::high_resolution_clock::now();
std::cout << "O(nlogn): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";
```
<!-- .element: class="fragment fade-in" -->

Possible output: `O(nlogn): 499694684900 ns`
<!-- .element: class="fragment fade-in" -->
Previous slides output: `O(n): 6949430300 ns`
<!-- .element: class="fragment fade-in" -->

___

## Złożoność `O(n^2)`

Jest to tzw. złożoność kwadratowa, której czas wykonania jest wprost proporcjonalny do kwadratu ilości danych wejściowych. Wyobraźmy sobie teraz inną sytuację. Udało nam się znaleźć numer Andrzeja i postanawiamy również zrobić psikus naszemu koledze, ale chcemy odwdzięczyć się z nawiązką. Dlatego drukujemy nową książkę telefoniczną, ale do każdego numeru dodajemy cyferkę '8' na początku numeru. Teraz nasz kolega nie dość, że musi poprawić każdą stronę `n` to jeszcze sprawdzić i poprawić każdy numer na podstawie oryginalnej książki. Taka złożoność obliczeniowa to `O(n^2)`. Przykładem złożoności `O(n^2)` jest popularne sortowanie bąbelkowe.

___
<!-- .slide: style="font-size: 0.7em" -->

## Złożoność `O(n^2)` - przykład

```C++
constexpr size_t samples = 1000000;
std::vector<int> vec(samples);
std::iota(begin(vec), end(vec), 0);
auto start = std::chrono::high_resolution_clock::now();
BubleSort(vec);
auto stop = std::chrono::high_resolution_clock::now();
std::cout << "O(n^2): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";

constexpr size_t samples2 = 10000000;  // size is 10 times higher.
std::vector<int> vec2(samples2);
std::iota(begin(vec2), end(vec2), 0);
start = std::chrono::high_resolution_clock::noaw();
BubleSort(vec2);
stop = std::chrono::high_resolution_clock::now();
std::cout << "O(n^2): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";

constexpr size_t samples3 = 100000000;  // size is 100 times higher.
std::vector<int> vec3(samples3);
std::iota(begin(vec3), end(vec3), 0);
start = std::chrono::high_resolution_clock::now();
BubleSort(vec3);
stop = std::chrono::high_resolution_clock::now();
std::cout << "O(n^2): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";
```
<!-- .element: class="fragment fade-in" -->

Possible output:

```C++
O(n^2): 9974800 ns
O(n^2): 83777600 ns
O(n^2): 810269600 ns
```
<!-- .element: class="fragment fade-in" -->

___

## Złożoność `O(x^n)`

Jest to tzw. złożoność wykładnicza, czas wykonania rośnie wykładniczo względem ilości danych wejściowych. Wyobraźmy sobie sytuację, w której nie dość, że książka zawiera błędy, które wcześniej celowo wprowadziliśmy, ale ktoś postanowił ją wydrukować w olbrzymim nakładzie i teraz musimy poprawić wszystkie książki, w których już czas poprawiania błędów wynosił `n^2`. Dla takiej kombinacji mówimy, że złożoność jest `n^n`. Czyli rośnie wykładniczo wraz ze wzrostem liczby książek (próbek). Przykładem może być algorytm DFS (deep-first graph), jeżeli danymi wejściowymi będzie macierz. Ponieważ za każdym razem musimy przejść cały rząd, aż znajdziemy interesujący nas element, więc wykonamy `n^n` kroków. Rzadko spotykane, więc jest formą ciekawostki 🙂

___

## Złożoność `O(n!)`

Jest to złożoność typu silnia, czas wykonania rośnie z szybkością silni względem ilości danych wejściowych. Przykładem problemu jest problem komiwojażera, należy znaleźć najkrótszą trasę rozpoczynając od miasta A przechodzącą jednokrotnie przez wszystkie pozostałe miasta i wracającą do miasta A. Od wielu lat analitycy głowią się, jak poprawić ten algorytm. Wciąż mamy pole do popisu 🙂. Nię będę tutaj wklejał kodu, ale zainteresowanych odsyłam do wyszukania sobie algorytmu komiwojażera.

___

## Złożoność `O(n * n!)`

Jeden z najgorszych scenariuszy jaki możemy wykonać dla algorytmu. Wybraźmy sobie sytuację, że nasz kolega postanowił pokazać nam, że nie warto z nim zadzierać i skarży się waszemu przełożonemu, że namieszaliście w książce telefonicznej. Teraz za karę musicie napisać program do robota układającego książki na półkach waszego kolegi w kolejności alfabetycznej. Jednak Wy postanawiacie zrobić mu kolejny (najgorszy) psikus, i piszecie robota, który będzie układał książki losowo, a następnie sprawdzał, czy może udało się je ułożyć poprawnie a jak nie, to ponownie je ściągał i znów układał na nowo. W ten sposób robot będzie układał książki kilka tygodni lub miesięcy, lecz w końcu mu się to uda 🙂

W ten sposób napisaliśmy idealnie nieoptymalny algorytm sortowania o złożoności `O(n * n)!`. Przykładem takiego sortowania jest bogosort.

___
<!-- .slide: style="font-size: 0.65em" -->

## Złożoność `O(n * !n)` Przykład

```C++
std::random_device rd;
std::mt19937 generator(rd());

void BogoSort(std::vector<int>& vec) {
    while (!std::is_sorted(vec.begin(), vec.end())) {
        std::shuffle(vec.begin(), vec.end(), generator);
    }
}

int main() {
    constexpr size_t samples = 10;  // Only 10 elements! Try it for 100 :)
    std::vector<int> vec(samples);
    std::iota(begin(vec), end(vec), 0);
    std::shuffle(vec.begin(), vec.end(), generator);
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        BogoSort(vec);
        auto stop = std::chrono::high_resolution_clock::now();
        std::cout << "O(n * n!): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";
    }

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

Possible output:
<!-- .element: class="fragment fade-in" -->

```C++
O(n * n!): 35938300 ns
O(n * n!): 85772000 ns
O(n * n!): 899885600 ns
O(n * n!): 2603326600 ns
O(n * n!): 145608700 ns
```
<!-- .element: class="fragment fade-in" -->

___

## Q&A
