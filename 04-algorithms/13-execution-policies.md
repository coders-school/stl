<!-- .slide: data-background="#111111" -->

# Bonus

## Sposoby wykonania

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

From C++17 you can use parallel or unsequential versions of STL algorithms. You need to provide an additional `std::execution_policy` as the first argument.

```cpp
std::vector<int> v(1'000'000);
std::generate(std::execution::par,
              begin(v),
              end(v),
              [n = 0]() mutable { return n++; });
```

___

## `std::execution`

* `seq` = sequential
* `par` = parallel
* `par_unseq` = parallel unsequential
* `unseq` = unsequential

They are used to specify the execution policy of parallel algorithms - i.e., the kinds of parallelism allowed. Usually linking against `-litbb` (Intel Threading Building Blocks) is required.
