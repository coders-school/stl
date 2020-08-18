# Złożonośc obliczeniowa

<img src="https://res.cloudinary.com/practicaldev/image/fetch/s--NR3M1nw8--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://thepracticaldev.s3.amazonaws.com/i/z4bbf8o1ly77wmkjdgge.png">

___

## Definicja

Złożoność obliczeniowa- oszacowanie czasu wykonania algorytmu. Mierzymy liczbę operacji, następnie szukamy funkcji opisującej liczbę operacji w zależności od danych wejściowych. Notacja O jest szacowaniem z góry. Ponieważ chcemy tylko przybliżyć wartość, pomijamy wszelkiego rodzaju stałe, które nie mają znaczenie przy dużych n. Zatem Ο(2n + 5), Ο(2n) i Ο(n) są uznawane za złożoność obliczeniową O(n).

___

## Złożoność O(1)

Jest to tzw. złożoność stała, która jest niezależna od liczby danych wejściowych. Przy obliczeniu sumy ciągu arytmetyczneo (kod poniżej), nie iterujemy po wszystkich elementach tablicy, zatem czas wykonania jest stały i niezależny od wielkości tablicy.

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

Output: `21`
___

## Złożoność O(logn)

Wyboraźmy sobie, że szukamy numeru telefonu naszego kolegi Andrzeja. Bierzemy ksiązę telefoniczną i otwieramy ją na środku i patrzymy, że wypada nam osoba o imieniu Kornelia. Wiemy, że Andrzej jest w pierwszej połowie ksążki adresowej, gdyż litera K jest dużo dalej w alfabecie niż litera A. Zatem znów otwieramy na środku pierwszej połowy i patrzymy, że widnieje tam Imie Dominik. Więc powtarzamy nasze szukanie natrafiając w kolejnej części na Bartka, aż w końcu trafiamy na Andrzeja. Takie przeszukiwanie w którym za każdym razem odrzucamy połowe zakresu jest własnie zapisywane w notacji O(logn).

```C++
std::vector<int> vec{1, 2, 3, 4, 5, 6};
std::cout << std::boolalpha
            << std::binary_search(begin(vec), end(vec), 2) << std::endl;
std::cout << std::boolalpha
            << std::binary_search(begin(vec), end(vec), 0) << std::endl;
```

Output:

```C++
true
false
```

___

## Złożoność O(n)

Wyboraźmy sobie teraz sytuację, że w ksążce adresowej szukamy szunemru Żanety. Jednak nie będziemy teraz przeszukiwać binarnie, tylko sprawdzimy ile zajmie nam to, gdy będziey szukać osoba po osobie. Więc zaczynamy Od litery A i 4 dni później znajdujemy w końcu numer Żanety :) Taka złożoność, gdzie sprawdzamy po kolei każdy element jest złożonością O(n).

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

```C++
O(logn): 0 ns
O(n): 6949430300 ns
```

___

## Złożoność O(nlog(n))

Jest to tzw. złożoność liniowo-logarytmiczna, której czas wykonania jest wprost proporcjonalny do iloczynu danychwejściowych i ich logarytmu.
Wyobraźmy sobię teraz sytuację, próbujemy znaleźć numer Andrzeja w książce telefonicznej, ale nasz kolega zrobił nam psikuj i pozamieniał strony. Teraz musimy ją posortować, zależy nam na czasie, więc chcemy to zrobić wydajnie. Dlatego wyrywamy kolejno strony z książki telefonicznej i wstawiamy je do nowej w zgodnej kolejnośći. Nie dość, że musimy zrobić taką operację dla `n` stron to jescze musimy wstawiać je alfabetycznie co zajmie nam `logn` czasu. Dlatego cały proces to `nlogn`.

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

Possible output: `O(nlogn): 499694684900 ns`
Previous slides otput: `O(n): 6949430300 ns`

___

## Złożoność O(n^2)

Jest to tzw. złożoność kwadratowa, której czas wykonania jest wprost proporcjonalny do kwadratu ilości danych wejściowych. Wybraźmy sobie teraz inną sytuację. Udało nam się zaleźć numer Andrzeja i postanawaimy również zrobić psikus naszemu koledze, ale chcemy odwdzięczyć się z nawiązką. Dlatego drukujemy nową książke telefoniczną, ale do każdego numeru dodajemy cyferkę 8 na początku numeru. Teraz nasz kolega nie dość, że musi poprawić każdą stronę `n` to jescze sprawdzić i poprawić każdy numer na podstawie oryginalnej książki. Taka złożonośc obliczeniowa to `O(n^2)`. Przykładem złożonośći `O(n^2)` jest popularne sorotwanie bąbelkowe.

___

## Złożoność O(n^2) Przykład

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

Possible output:

```C++
O(n^2): 9974800 ns
O(n^2): 83777600 ns
O(n^2): 810269600 ns
```

___

## Złożoność O(x^n)

Jest to tzw. złożoność wykładnicza, czas wykonania rośnie wykładniczo względem ilości danych wejściowych. Wybraźmy sobie sytuację, w której nie dość, że książka zawiera błedy które wcześniej celowo wprowadziliśmy ale ktoś postanowił ją wydrukować w olbrzymim nakładzie i teraz musimy porawić wszystkie książki w kórych już czas poprawiania błeów wynosił n^2. Dla takiej kombinacji mówimy, że złożonośc jest n^n. Czyli rośnie wykładniczo wraz ze wzrostem liczby książek (próbek). Przykładem może być algorytm DFS (deep-first graph), jeżeli danymi wejściowymi będzie macierz. Ponieważ za każdym razem musimy przejść cały rząd aż znajdziemy interesujący nas element. Więc wykonamy n^n kroków. Żadko spotykane, więć jest formą ciekawostki :)

___

## Złożoność O(n!)

Jest to złożoność typu silnia, czas wykonania rośnie z szybkością silni względem ilości danych wejściowych. Przykładem problemu jest problem komiwojażera, należy znaleźć najkrótszą trasę rozpoczynając od miasta A przechodzącą jednokrotnie przez wszystkie pozostałe miasta i wracającą do miasta A. Od wielu lat analitycy głowią się, jak poprawić ten algorytm. Wciąż mamy pole do popisu :) Nię będe tutaj wklejał kodu, ale zaintersowanych odsyłam do wyszukania sobie algorytmu komiwojażera.

___

## Złożoność O(n * n!)

Jeden z najgorszych scenariuszy jaki możemy wykonać dla algorytmu. Wybraźmy sobię sytuację, że nasz kolega postanowił pokazać nam, że nie warto z nim zadzierać i skraży się waszemu przełożonemu, że namieszaliście w książe telefonicznej. Teraz za karę musicie napisać program do robota układającego książki na półkach waszego kolegi w kolejności alfabetycznej. Jednak Wy postanwaiacie zrobić mu kolejny (najgorszy) psikus, i piszecie robota, kóry będzie układał książki losowo, następnie sprawdzał, czy może udało się je ułozyc poprawnie a jak nie, to ponownie je sciągął i znów układał na nowo. W ten sposób Robot będzie układał ksążki kilka tygodni lub miesięcy, lecz w końcu mu sie to uda :)
W ten spoób napisaliśmy idealnie nieoptymalny algorytm sootwania o złożonośći O(n * n)!. Przykładem takie sorotewania jest bogosort.

___

## Złożoność O(n * !n) Przykład

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

Possible output:

```C++
O(n * n!): 35938300 ns
O(n * n!): 85772000 ns
O(n * n!): 899885600 ns
O(n * n!): 2603326600 ns
O(n * n!): 145608700 ns
```

___

## Q&A

___
