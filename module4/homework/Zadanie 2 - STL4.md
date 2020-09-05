# Zadanie 2 - STL4
## `std::stack`
---
### Cechy
- adapter stosu
- LIFO (last-in, first-out)
- standardowo jest wrapperem na `std::deque`
- dostęp możliwy jest tylko do elementu na wierzchołku stosu
### Operacje
- dostęp do elementu na szczycie: `top()` - **O(1)**
- sprawdzanie czy stos jest pusty: `empty()`
- dodawanie elementu na szczyt stosu: `push()`, `emplace()` - **O(1)**
- usuwanie elementu na szczycie: `pop()` - **O(1)**
### Przykład użycia `top()`, `pop()` i `push()`
```cpp
std::stack<int> s;
s.push(1);
s.push(2);
std::cout << s.top() << '\n';
s.pop();
std::cout << s.top() << '\n';
```
Output:
```
2
1
```
### Przykład tworzenia `std::stack` na bazie istniejącego kontenera
```cpp
std::deque<int> deq{1, 2, 3, 4, 5};
std::stack<int> s{deq};
std::cout << s.top() << ' ' << s.size() << '\n';
```
Output:
```
5 5
```
Analogicznie możemy tworzyć `std::stack` na bazie `std::vector` oraz `std::list`

## `std::queue`
---
### Cechy
- adapter kolejki
- FIFO (first-in, first-out)
- standardowo jest wrapperem na `std::deque`
- dostęp możliwy jest tylko do elementów na początku i końcu kolejki
### Operacje
- dostęp do elementu na początku/końcu kolejki: `front()`, `back()`
- sprawdzanie czy kolejka jest pusty: `empty()`
- dodawanie elementu na końcu kolejki: `push()`, `emplace()`
- usuwanie elementu na początku kolejki: `pop()`
### Przykład użycia `std::queue`
```cpp
std::queue<int> q;
q.push(1);
q.push(2);
q.push(3);
std::cout << q.front() << ' ' << q.back() << '\n';
q.pop();
std::cout << q.front() << ' ' << q.back() << '\n';
```
Output:
```
1 3
2 3
```

## `std::priority_queue`
---
### Cechy
- adapter kolejki priorytetowej
- FIFO (first-in, first-out)
- domyślnie elementy uporządkowane nierosnąco
- dostęp do elementu na początku kolejki
### Operacje
- dostęp do pierwszego elementu: `top()`
- sprawdzanie czy kolejka jest pusta: `empty()`
- dodawanie elementów: `push()`, `emplace()`
- usuwanie pierwszego elementu: `pop()`
### Przykład użycia `std::priority_queue`
```cpp
std::priority_queue<int> pq;
pq.push(4);
pq.push(1);
pq.push(3);
pq.push(2);
while (!pq.empty()) {
    std::cout << pq.top() << ' ';
    pq.pop();
}
```
Output:
```
4 3 2 1
```
### Przykład tworzenia `std::priority_queue` (elementy uporządkowane niemalejąco, użycie `std::vector` zamiast `std::dequeue`)
```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
```
