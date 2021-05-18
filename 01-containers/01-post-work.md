<!-- .slide: data-background="#111111" -->

# STL containers

## Post-work

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Task Description

`interval_map<K,V>` is a data structure that efficiently associates intervals of keys of type K with values of type V.

`interval_map<K, V> `is implemented on top of `std::map`.

Each key-value-pair (`k`,`v`) in the `interval_map` means that the value `v` is associated with the interval from `k` (including) to the next key (excluding).

___

### Example

```cpp
std::map m = {{0,'A'}, {3,'B'}, {5,'A'}};
```

represents the mapping

```text
0 -> 'A'
1 -> 'A'
2 -> 'A'
3 -> 'B'
4 -> 'B'
5 -> 'A'
6 -> 'A'
7 -> 'A'
... all the way to numeric_limits<int>::max()
```

The representation in the map must be canonical, that is, consecutive map entries must not have the same value: `..., (0,'A'), (3,'A'), ...` is not allowed.

Initially, the whole range of K is associated with a given initial value, passed to the constructor of the `interval_map<K,V>` data structure.

___

### [Download the code](https://replit.com/@ziobron/interval-map#main.cpp)

Your task is to implement the assign member function of this data structure.

___

## Post-test

[STL containers post-test](https://forms.gle/hSXkmHxrRrPBvsbT7)

The link will be sent in the next week with all materials.
