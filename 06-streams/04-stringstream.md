<!-- .slide: data-background="#111111" -->

# `stringstream`

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.9em" -->

## `std::string` jako strumień

`std::string` można łatwo podzielić na pojedyncze słowa. Niestety nie możemy tego zrobić w prosty sposób dla znaków innych niż spacja.

```cpp
std::string str {"Ala ma kota, a kot ma ale, ale to nie to samo, co Sierotka ma rysia."};
std::istringstream iss(str);
std::vector<std::string> vec {std::istream_iterator<std::string>(iss), {}};
std::copy(begin(vec), end(vec), std::ostream_iterator<std::string>(std::cout, "\t"));
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
Ala     ma      kota,   a       kot     ma      ale,    ale     to      nie     to      samo,   co      Sierotka        ma      rysia.
```
<!-- .element: class="fragment fade-in" -->

`std::ostream_iterator` pozwala nam wpisywać dane do `std::cout`, w wygodny sposób.
<!-- .element: class="fragment fade-in" -->

___

## Szybka konwersja na `string`

```cpp
std::stringstream ss;
ss << "Some text\n";
ss << "Result: " << 42 << '\n';
ss << "Some double: " << 123.456 << '\n';
std::string str = ss.str();
std::cout << "str: " << str;
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```txt
str: Some text
Result: 42
Some double: 123.456
```
<!-- .element: class="fragment fade-in" -->
