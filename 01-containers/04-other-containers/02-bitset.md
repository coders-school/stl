<!-- .slide: data-background="#111111" -->

# `std::bitset<N>`

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::bitset<N>` traits

* <!-- .element: class="fragment fade-in" --> The class for representing and manipulating arrays of bits
* <!-- .element: class="fragment fade-in" --> It supports testing if any/all/none bits are set
* <!-- .element: class="fragment fade-in" --> It supports setting/resetting/flipping single bits
* <!-- .element: class="fragment fade-in" --> It keeps all elements on stack
* <!-- .element: class="fragment fade-in" --> <code>std::vector&lt;bool&gt;</code> is an alternative, but it keeps elements on heap and does not provide fancy functions

___

## `std::bitset<N>` methods

##### [`std::bitset<N>` on cppreference.org](https://en.cppreference.com/w/cpp/utility/bitset)

___

## Example

```cpp
std::bitset<4> b{"0011"};
std::cout << "bitset" << b << '\n';

// bitset supports bitwise operations:
b |= 0b0100;                    assert(b == 0b0111);
b &= 0b0011;                    assert(b == 0b0011);
b ^= std::bitset<4>{0b1100};    assert(b3 == 0b1111);

// operations on the whole set:
b3.reset();                     assert(b3 == 0);
b3.set();                       assert(b3 == 0b1111);

// operations on individual bits:
b3.set(1, true);                assert(b3 == 0b0010);
b3.set(1, false);               assert(b3 == 0);
b3.flip(2);                     assert(b3 == 0b0100);
b3.reset(2);                    assert(b3 == 0);

// subscript operator[] is supported:
b3[2] = true;                   assert(true == b3[2]);
```
