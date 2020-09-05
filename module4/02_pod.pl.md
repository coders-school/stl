<!-- .slide: data-background="#111111" -->

# POD - Plain old data

___

## POD - Plain old data

Czyli klasa/struktura bez konstruktora, destruktora i metod wirtualnych.

```C++
class Pod {
public:
    void DoSth() {}
    bool ReturnTrue() { return true; }
    bool ReturnFalse() { return false; }

private:
    size_t index_;
    const char name_[15];
    double average_;
};
```
<!-- .element: class="fragment fade-in" -->

___

## POD - Plain old data #2

Ale to już nie jest POD.

```C++
class Pod {
public:
    void DoSth() {}
    bool ReturnTrue() { return true; }
    bool ReturnFalse() { return false; }

private:
    size_t index_;
    std::string name_; // std::string has constructor!
    double average_;
};
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Zapisywanie POD

```C++
class Pod {
public:
    void DoSth() {}
    bool ReturnTrue() { return true; }
    bool ReturnFalse() { return false; }

    void SetName(std::string name) { strncpy(name_, name.data(), 15); }
    void SetIndex(size_t index) { index_ = index; }
    void SetAverage(double average) { average_ = average; }

    std::string GetName() const { return name_; }
    size_t GetIndex() const { return index_; }
    double GetAverage() const { return average_; }

private:
    char name_[15];
    size_t index_;
    double average_;
};

int main() {
    Pod mateusz;
    mateusz.SetName("Mateusz");
    mateusz.SetIndex(123456);
    mateusz.SetAverage(5.0);

    // or
    // Pod mateusz{"Mateusz", 123456, 5.0};

    std::fstream student("Student.txt", student.binary | student.out);
    if (student.is_open()) {
        student.write(reinterpret_cast<char*>(&mateusz), sizeof(Pod));
        student.close();
    }
}
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Odczyt POD

```C++
    student.open("Student.txt", student.binary | student.in);
    Pod mateusz_read;
    if (student.is_open()) {
        student.read(reinterpret_cast<char*>(&mateusz_read), sizeof(Pod));
        std::cout << "Name: " << mateusz_read.GetName() << '\n';
        std::cout << "Index: " << mateusz_read.GetIndex() << '\n';
        std::cout << "Average: " << mateusz_read.GetAverage() << '\n';
        student.close();
    }
```
<!-- .element: class="fragment fade-in" -->

Hexdump:
<!-- .element: class="fragment fade-in" -->

```C++
0000000 614d 6574 7375 007a 0000 0000 0000 0000
0000010 e240 0001 0000 0000 0000 0000 0000 4014
0000020
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
Name: Mateusz
Index: 123456
Average: 5
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## stringstream - jak wygodnie używać `std::string` jako strumień

Podzielenie `std::string` na pojedyncze słowa. Niestety nie możemy tego w tak prosty sposób zrobić dla innch znaków niż spacja.

```C++
std::string str {"Ala ma kota, a kot ma ale, ale to nie to samo, co Sierotka ma rysia."};
std::istringstream iss(str);
std::vector<std::string> vec {std::istream_iterator<std::string>(iss), {}};
std::copy(begin(vec), end(vec), std::ostream_iterator<std::string>(std::cout, "\t"));
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
Ala     ma      kota,   a       kot     ma      ale,    ale     to      nie     to      samo,   co      Sierotka        ma      rysia.
```
<!-- .element: class="fragment fade-in" -->

`std::ostream_iterator` pozwala nam wpisywać dane do `std::cout`, w wygodny sposób.
<!-- .element: class="fragment fade-in" -->

___

## stringstream -> jak skonwertować na string

```C++
std::stringstream ss;
ss << "End of passion play, crumbling away\n";
ss << "I'm your source of self-destruction\n";
ss << "Veins that pump with fear, sucking darkest clear\n";
ss << "Leading on your deaths' construction\n";
std::string str = ss.str();
std::cout << "str: " << str;
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
str: End of passion play, crumbling away
I'm your source of self-destruction
Veins that pump with fear, sucking darkest clear
Leading on your deaths' construction
```
<!-- .element: class="fragment fade-in" -->

___

## Q&A
