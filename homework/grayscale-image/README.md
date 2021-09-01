# `compressGrayscale()` && `decompressGrayscale()`

## `compressGrayscale()`

Zadaniem będzie kompresja obrazka w odcieniach szarości o wymiarach 240x160 pikseli. Każdy piksel może mieć wartość od 0 (kolor czarny) do 255 (kolor biały). Im większa wartość tym jaśniejszy odcień piksel reprezentuje. Przykład małego obrazka o rozmiarach 6x4 piksele:

<img width="300px" src="https://github.com/coders-school/stl/raw/master/img/example.png" alt="Przykład pikseli" class="plain">

```cpp
255 255 0   255 0   255   // 0xFF 0xFF 0x00 0xFF 0x00 0xFF
128 0   128 0   128 0     // 0x80 0x00 0x80 0x00 0x80 0x00
64  64  64  64  64  64    // 0x40 0x40 0x40 0x40 0x40 0x40
255 192 128 64  0   0     // 0xFF 0xB0 0x80 0x40 0x00 0x00
```

Aby otrzymać z tego plik w formacie PGM wystarczy tylko dodać mu odpowiedni nagłówek.

___
<!-- .slide: style="font-size: 0.9em" -->

## `compressGrayscale()` - opis

Napisz funkcję `compressGrayscale()`.
Powinna ona przyjąć jeden argument typu `std::array<std::array<uint8_t, 240>, 160>` określający rozkład odcieni szarości na obrazku 2D (który w dalszej części nazywać będziemy bitmapą) i zwróci `std::vector<std::pair<uint8_t, uint8_t>>` zawierający skompresowaną bitmapę.

Kompresja powinna przebiegać w następujący sposób:

* Bitmapę rysujemy od górnego lewego rogu przechodząc w prawo, następnie poziom niżej.
* Jeżeli obok siebie występuje ten sam kolor więcej niż 1 raz, funkcja powinna wrzucić do  `std::vector<>` wartość tego koloru (liczba z przedziału 0 – 255) jako pierwszy element pary oraz ilość jego powtórzeń jako drugi element pary.
* Jeżeli obok siebie występują różne odcienie to funkcja powinna wypełnić `std::vector<> ` wartością odcienia oraz liczbą wystąpień równą 1 (w tym przypadku pogarszamy optymalizację, gdyż przechowujemy 2x tyle danych, jednak najczęściej te same kolory są położone obok siebie).

___
<!-- .slide: style="font-size: 0.9em" -->

## `compressGrayscale()` - przykład

```cpp
input: {{0 0 0 1 1 2 3 0 0 0},
        {0 0 4 4 4 1 1 1 1 1},
        {2 2 2 2 2 1 2 2 2 2}}
output: {{0, 3}, {1, 2}, {2, 1}, {3, 1}, {0, 3}, {0, 2}, {4, 3}, {1, 5}, {2, 5}, {1, 1}, {2, 4}}
```

W przypadku powyższej konwersji zamiast 30 bajtów (wymiary 10x3) zużyjemy 22 (11x2). Więc skompresowaliśmy dane o 26,7%.

Nie przejmujemy się na razie tym jak `uint_8` będzie zamieniany na kolor. Ważne w tym zadaniu jest, aby poćwiczyć korzystanie z kontenerów oraz wykonywania na nich różnych operacji.

___

## `decompressGrayscale()`

Napisz funkcję `decompressGrayscale()`, która zdekompresuje obrazek skompresowany w zadaniu 3 za pomocą funkcji `compressGrayscale()`.

Jako argument funkcja `decompressGrayscale()` przyjmie `std::vector<std::pair<uint8_t, uint8_t>>` natomiast zwróci `std::array<std::array<uint8_t, 240>, 160>` i przeprowadzi operacje mające na celu rekonstrukcję pierwotnego formatu bitmapy.

___

## Implementacja

Stwórz odpowiedni plik nagłówkowy (hpp) oraz źródłowy (cpp).

W pliku nagłówkowym zdefiniuj stałe dotyczące rozmiaru w taki sposób:

```cpp
constexpr size_t width = 32;
constexpr size_t height = 32;
```

Dzięki temu będzie Ci łatwiej zmienić rozmiar obrazka w celach testowych, bo wystarczy to zrobić tylko w jednym miejscu.
W testach też są używane takie same nazwy stałych.

___

## ASCII art

Dla chętnych polecamy także napisać sobie funkcję `printMap()`, która wyświetli obrazek.
Domyślnie `std::cout` potraktuje `uint8_t` jako `unsigned char`, dlatego też możecie sobie wypisać mapę z kodów ASCII.

<img width="450px" src="https://github.com/coders-school/stl/raw/master/img/ascii_art_mug.jpg" alt="ASCII art z kubkiem" class="plain">

Jeśli chcesz zrobić to zadanie (nie ma za nie dodatkowych punktów) to zaimplementuj zakomentowaną w main.cpp funkcję `printMap()`. Jej implementację wrzuć do pliku z funkcjami `compressGrayscale()` i `decompressGrayscale()`. Jej prawidłowa implementacja i odpalenie funkcji `main()` poprzez wywołanie `./grayscale-image` powinna wyświetlić ninję na ekranie :)

```text
          $**********$
          488888888883
         +@DDDDDDDDDD@/
     !]=.9W]]]]]]]]]]]]]L
      5GOQ������������W4
      !K[k�������������Y"
     !]=Z����=������p]�d"
 Wq   /+e��������������d"    vX
 UpH'  #\��������������Y"   9�k
 )@�P  #,333333333337;B1"  a�Q6
   Nil #,333333333337;B1" yyk*
   -]g**,333333333337;B1=Z�sB
    ,>M6,333333333337;B1_�L+
      <FC+2333333349>=,DHD
      )>@2/////////369=C=)
       1::-**********3M?/
         *1333699>BBB>*
        #/.033466:==869&
       #,3,-3333369900B1"
       #,3,-3333334900B1"
       #,3,-3333334900B1"
       #,3,-333333490/@0"
       #,3,-333333490.9."
        #/.033466:==869&
       #,3,-3333369900B1"
       #,3,-3333334900B1"
       #,3,-3333334900B1"
       #,3,-333333490/@0"
       #,3,-333333490.9."
       #+,*<UUUUUUUV<+.+"
        "");R\XRRRSU<(""
          %-3YM3335B3$
          %-3YM3369B3$
          %-3LC336:B3$
          %-333336:B3$
          %-33/++3:B3$
          %,//(  )38/$
          $)))    )))$
```

___

### Refaktoryzacja testów

Jest to zadanie dla chętnych (bez dodatkowych punktów).

Napisz nową funkcję, która zastąpi te brzydkie pętle w testach:

```cpp
for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width / 4; ++j)
        arr[i][j] = 0;
    for (int j = width / 4; j < width / 2; ++j)
        arr[i][j] = 1;
    for (int j = width / 2; j < width / (4.0 / 3.0); ++j)
        arr[i][j] = 2;
    for (int j = width / (4.0 / 3.0); j < width; ++j)
        arr[i][j] = 3;
}
```

Wystarczy zauważyć zależność, że w zależności od tego, jaka część linii jest wypełniania to pętle przyjmują określoną strukturę.
Ma to być jedna uniwersalna funkcja, która będzie używa w testach `ShouldCompressWholeLine`, `ShouldCompressHalfLine`, `ShouldCompressQuaterLine`, itd.
Ma to działać podobnie jak funkcja `getBitmap()`.
Po wydzieleniu i refaktoringu (czyli upiększeniu, aby kod był czytelniejszy i lepszy do ponownego użycia) funkcji generującej, postaraj się dopisać także przypadki dla 1/16, 1/32 i 1/64 mapy.
