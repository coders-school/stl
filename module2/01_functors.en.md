<!-- .slide: data-background="#111111" -->

# Functors

## Function objects

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.9em" -->

## What is a functor - a function object

A functor is an object that can be called like a normal function. Each class and structure that has a defined `operator()` can act as a functor.
An alternative name for a functor is a function object.

```cpp
struct Functor {
    void operator() () {
        std::cout << "I'm a functor!\n";
    }
};

int main() {
    Functor funct;
    funct();      // obiekt nazwany (linię wyżej)
    Functor{}();  // obiekt tymczasowy

    return 0;
}
```

output:

```text
I'm a functor!
I'm a functor!
```

___

## What is a functor - function

The function is also treated as a functor because we can also call it with `()`.

```cpp
void function() {
    std::cout << "I'm a functor!\n";
}

int main() {
    function();

    return 0;
}
```

output: `I'm a functor!`

___

## The use of functors

We can use functors in STL algorithms. For example, the algorithm `for_each` for each element it calls the passed functor. The functor itself must take as its only argument the type of element in the range it is working on.

```cpp
struct Functor {
    void operator()(int el) {
        std::cout << el << ' ';
    }
};

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::for_each(begin(vec), end(vec), Functor{});
    std::cout << '\n';

    return 0;
}
```

output: `1 2 3 4 5`

___

## Q&A
