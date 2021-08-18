<!-- .slide: data-background="#111111" -->

# Pytania

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Pytanie #1

Jaka jest złożoność poniższego algorytmu?
<!-- .element: class="fragment fade-in" -->

```cpp
int vectorMax(Vector<int> &v){
    int currentMax = v[0];
    int n = v.size();
    for (int i = 1; i < n; i++) {
        if (currentMax < v[i]) {
            currentMax = v[i];
        }
    }
    return currentMax;
}
```
<!-- .element: class="fragment fade-in" -->

### Złożoność liniowa `O(n)`
<!-- .element: class="fragment fade-in" -->

___

## Pytanie #2

Jaka jest złożoność poniższego algorytmu?
<!-- .element: class="fragment fade-in" -->

```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if (it == res.end()) {
            res.push_back(nums[i]);
        } else {
            *it = nums[i];
        }
    }
    return res.size();
}
```
<!-- .element: class="fragment fade-in" -->

### Złożoność liniowo-logarytmiczna `O(nlogn)`
<!-- .element: class="fragment fade-in" -->

___

## Pytanie #3

Jaka jest złożoność poniższego algorytmu?
<!-- .element: class="fragment fade-in" -->

```cpp
int mysteryFunc(int number) {
    if (number <= 1) {
        return number;
    }
    return mysteryFunc(number - 2) + mysteryFunc(number - 1);
};
```
<!-- .element: class="fragment fade-in" -->

### Złożoność wykładnicza - `O(2^n)`
<!-- .element: class="fragment fade-in" -->

To algorytm na obliczanie n-tej liczby ciągu fibonacciego.
<!-- .element: class="fragment fade-in" -->

___

## Pytanie #4

Jaka jest złożoność w notacji dużego O dla tej funkcji?
<!-- .element: class="fragment fade-in" -->

```text
20n^3 + 10n*log n + 5
```
<!-- .element: class="fragment fade-in" -->

### Złożoność wielomianowa - `O(n^3)`
<!-- .element: class="fragment fade-in" -->

___

## Pytanie #5

Jaka jest złożoność w notacji dużego O dla tej funkcji?
<!-- .element: class="fragment fade-in" -->

```text
2000logn + 7n*logn + 5
```
<!-- .element: class="fragment fade-in" -->

### Złożoność liniowo-logarytmiczna - `O(nlogn)`
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.7em" -->

## Pytanie #6

Jaka jest złożoność tego kodu?
<!-- .element: class="fragment fade-in" -->

```cpp
void searchVector(Vector<int> &vec, int numToFind) {
    int low = 0;
    int high = vec.size() - 1;
    int mid;
    int numCompares = 0;
    bool found = false;
    while (low <= high) {
        numCompares++;
        mid = low + (high - low) / 2; // to avoid overflow
        if (vec[mid] > numToFind) {
            high = mid - 1;
        }
        else if (vec[mid] < numToFind) {
            low = mid + 1;
        } else {
            found = true;
            break;
        }
    }
    cout << "Found? " << (found ? "True" : "False") << ", "
         << "Number of compares: " << numCompares << endl;
}
```
<!-- .element: class="fragment fade-in" -->

### Złożoność logarytmiczna - `O(logn)`
<!-- .element: class="fragment fade-in" -->

To algorytm wyszukiwania binarnego.
<!-- .element: class="fragment fade-in" -->
