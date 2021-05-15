<!-- .slide: data-background="#111111" -->

# POD - Plain old data

___

## POD - Plain old data

POD is a class/structure without a constructor, destructor and virtual methods.

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

## POD - Plain old data # 2

But that's not a POD anymore.

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

## Saving POD to a file

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
    Pod matthew;
    matthew.SetName("Matthew");
    matthew.SetIndex(123456);
    matthew.SetAverage(5.0);

    // or
    // Pod matthew{"Matthew", 123456, 5.0};

    std::fstream student("Student.txt", student.binary | student.out);
    if (student.is_open()) {
        student.write(reinterpret_cast<char*>(&matthew), sizeof(Pod));
        student.close();
    }
}
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Reading POD

```C++
    student.open("Student.txt", student.binary | student.in);
    Pod matthew_read;
    if (student.is_open()) {
        student.read(reinterpret_cast<char*>(&matthew_read), sizeof(Pod));
        std::cout << "Name: " << matthew_read.GetName() << '\n';
        std::cout << "Index: " << matthew_read.GetIndex() << '\n';
        std::cout << "Average: " << matthew_read.GetAverage() << '\n';
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
Name: Matthew
Index: 123456
Average: 5
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## stringstream - how to use `std::string` conveniently as a stream

Divide `std::string` into single words. Unfortunately, we cannot do this in such a simple way for characters other than spaces.

```C++
std::string str {"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."};
std::istringstream iss(str);
std::vector<std::string> vec {std::istream_iterator<std::string>(iss), {}};
std::copy(begin(vec), end(vec), std::ostream_iterator<std::string>(std::cout, "\t"));
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
Lorem   ipsum   dolor   sit     amet,   consectetur     adipiscing      elit,   sed     do      eiusmod tempor  incididunt      ut      labore  et      dolore  magna   aliqua.
```
<!-- .element: class="fragment fade-in" -->

`std::ostream_iterator` allows us to enter data into `std::cout` in a convenient way.
<!-- .element: class="fragment fade-in" -->

___

## stringstream -> how to convert to string

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

```cpp []
str: End of passion play, crumbling away
I'm your source of self-destruction
Veins that pump with fear, sucking darkest clear
Leading on your deaths' construction
```
<!-- .element: class="fragment fade-in" -->

___

## Q&A
