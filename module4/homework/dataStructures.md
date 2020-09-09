 ![](https://miro.medium.com/max/875/1*KpDOKMFAgDWaGTQHL0r70g.png)
# Struktury Danych
---
Hej dzisiaj przedstawie Wam trochę informacji o strukturach danych. Czym są struktury danych? Większość z Was zapewne już wie, że jest to nic innego jak sposób przechowywania danych w pamięci komputera. Struktury danych niemal zawsze współistnieją z algorytmami. Naszym zadaniem, będąc programistą jest dobranie takiej strutkury, aby optymalizowała złożoność obliczeniową naszego alogrytmu. Przykładami struktur danych mogą być takie abstrakcyjne tworki jak:
- tablica
- lista
- drzewo
- graf
- stos
- kolejka

Oczywiście istnieją także inne struktury danych. Ciekawskich odsyłam [tutaj](https://www.geeksforgeeks.org/data-structures/).Dzisiaj zajmiemy się tylko liniowymi strukturami danych. Omówimy sobie dokładnie: 
- stos (ang. stack)
- kolejkę (ang queue)
- kolejkę priorytetową (ang. priority queue)

Wyjaśnijmy sobie najpierw czym są liniowe struktury danych. Liniowe struktury danych to tak naprawde taki twór, taka struktura, w której każdy element poza pierwszym i ostatnim ma dostęp tylko do swojego następnego i poprzedniego elementu! Jest to oczywiście intuicyjne, ponieważ ostatni element nie ma swojego następnego elementu, a pierwszy element nie ma swojego poprzedniego elementu. Ci, którzy tego nie widzą niech zerkną poniżej.

![](https://cdn.programiz.com/sites/tutorial2program/files/c-arrays.jpg)

Jak widzimy komórka tablicy z indeskem [0] nie posiada elementu poprzedniego, natomiast komórka tablicy z indeksem [4] nie posiada elementu następnego! Komórka tablicy z indeksem [2] ma dostęp do poprzedniego i następnego elementu, kolejno komórki: [1], [3]. Z góry przepraszam, za taki przydługi wstęp, myślę natomiast, że teraz definicja liniowej struktury danych stała się jasna :). No to do roboty!

# Stos (ang. Stack)
---
Czymże jest stos? Zapytał Mateusz, student pierwszego roku politechniki. Zawsze przeciez kojarzył on mu się, ze średniowiecznym zwyczajem "opalania" czarownic. Dużo się nie pomylił, gdyż jest tam pewna analogia, ale nie bądźmy tacy brutalni :). Do rzeczy. Stos to liniowa struktura danych, w której takie dane możemy dokładać na wierzch stosu lub z tego wierzchu je ściągać czyli pobierać. Jest to bufor typu LIFO (Last In First Out) bądź alternatywnie nazywany FILO (First In Last Out). Idee stosu prezentuje poniższy obrazek. 
![](https://cdn.programiz.com/sites/tutorial2program/files/stack.png)
Łatwo możemy sobie taką wizję stosu przeniść na świat rzeczywisty. Wyobraźmy sobie stos takich książek lub nawet stos talerzy w szafce. Podczas zmywania, talerze układamy do szafki. Nadchodzi wtedy czas obiadu. Zdejmujemy talerze. W jakiej kolejności? A no w odwrotnej kolejności! Ostatni umyty talerz, będzie naszym pierwszym, który ściągniemy, aby przygotować stół do obiadu! Tak, to jest takie łatwe :).

## Operacje na stosie
---
Przechodzimy do konkretów. Mamy kilka podstawowych operacji na stosie. Są nimi:
- push() - operacja odpowiedzialna za dodanie elementu na wierzch stosu. Jeśli stos jest pełny otrzymamy popularny komunikat Stack Overflow.
- pop() - operacja odpowiedzialna za usunięcie elementu z wierzchu stosu. Próba usunięca elementu z pustego stosu to tak zwany Stack Underflow. 
- top() - operacja odpowiedzialna za zwrócenie elementu znajdującego się na wierzchołku stosu. Rzadziej nazywana peek().
- empty() - operacja sprawdzająca czy nasz stos jest pusty. Jeśli jest to zwraca: true. W przeciwnym wypadku zwraca: falase.
## Złożoność czasowa
---

Ponieważ implementacje operacji stosu nie zawierają żadnych pętl ich wykonywanie jest błyskawiczne!

| Operacja | Złożoność czasowa |
| ------ | ------ |
| push() | O(1) |
| pop() | O(1) |
| top() | O(1) |
| empty() | O(1) |

## Implementacje
---
Występują dwie popularne ścieżki, aby taki stos zaimplementować. Obie mają swoje wady i zalety. Pierwszym sposobem jest użycie tablicy. Drugim natomiast jest użycie listy. Oczywiście możemy użyc także innych kontenerów np. std::vector. Poniżej zaprezentuje implemtnacje stosu wykorzystując std::array. Dla ciekawskich implementacja stosu za pomocą listy znajduje się [tutaj](https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/).

| Stos za pomocą tablicy | Stos za pomocą listy |
| ------ | ------ |
| + Oszczędność pamięci, brak dodatkowych wskaźników| + Jest dynamiczna. Rośnie lub maleje, w zależności od potrzeb |
| - Nie jest dynamiczna. Stały rozmiar | - Większe zużycie pamięci, ponieważ używa dodatkowych wskażników  |

## Implementacja stosu za pomocą std::array
---
```
#include <array>
#include <iostream>
constexpr int MAX_STACK_SIZE = 100;
class Stack {
    int top_;
public:
    std::array<int, MAX_STACK_SIZE> stackArray_;
    Stack() { top_ = -1; }
    bool push(int value);
    int pop();
    int top();
    bool isEmpty();
};
bool Stack::push(int value) {
    if (top_ >= (MAX_STACK_SIZE - 1)) {
        std::cout << "Stack Overflow" << '\n';
        return false;
    }
    stackArray_[++top_] = value;
    std::cout << value << " Pushed into stack" << '\n';
    return true;
}
int Stack::pop() {
    if (top_ < 0) {
        std::cout << "Stack is underflow" << '\n';
        return 0;
    }
    int value = stackArray_[top_--];
    std::cout << value << " Popped from stack" << '\n';
    return value;
}
int Stack::top() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << '\n';
        return 0;
    }
    int value = stackArray_[top_];
    std::cout << "Current value on stack is: " << value << '\n';
    return value;
}
bool Stack::isEmpty() {
    return (top_ < 0);
}
int main() {
    Stack stack;
    stack.push(5);
    stack.push(2);
    stack.top();
    stack.pop();
    stack.pop();
    stack.top();
    return 0;
}
```

### Output
---
```
5 Pushed into stack
2 Pushed into stack
Current value on stack is: 2
2 Popped from stack
5 Popped from stack
Stack is empty
```
## Stos w STL 
---
Biblioteka standardowa oddaje nam do użytku własną implementację stosu zdefiniowaną w headerze *<stack>*. Jest to tak zwany adapter stosu, który stadnardowo jest wrapperem na std::deque. To tyle z suchej teorii. Wszystkie metody, operatory, kontruktor, destruktor itd. tej bibilioteki znajdziesz [tutaj](https://en.cppreference.com/w/cpp/container/stack). My zajmiemy się omówieniem nawajżniejszych metod tej biblioteki. Analogicznie stos znajdujący się w bibliotece standardowej zawiera metody takie jak:
- push()
- pop()
- top()
- empty()

Ich funckjonalnosć oraz złożonośc czasowa jest identyczna jak tych omówionych powyżej w punktach:  "Operacje na stosie" oraz "Złożoność czasowa". Nowe metody, które warto znać to:
- size()  - zwraca nam ilość elementów, które znajdują się na stosie.
- swap() - umożliwa nam zamianę stosów, które mają ten sam typ, lecz różnią sie rozmiarem.
- emplace() - robi to samo co push, złożoność obliczeniowa ta sama, ale... push() powoduje skopiowanie przekazanego elementu, a emplace() tworzy ten element w odpowiednim miejscu na podstawie przekazanych elemetnów. Podobnie jak w wektorze push_back() vs emplace_back().

Trzy powyższe metody mają złożoność czasową O(1). Demonstracja korzystania z STL'owego stosu znajduję się w zadaniu na końcu działu poświęconego stosowi.

## Wykorzystanie
---
Jedną z implementacja stosu jako struktury danych jest obszar w pamięci wydzielony dla danego wątku, służący do przechowywania adresów powrotu i zmiennych loklanych. Możemy, również korzystać z tej struktury w innych sytuacjach! Zaprezentuje Wam idealny przykład użycia stosu dla kurstantów C++, dla których zmorą jest niedomknięcie klamr, nawiasów. Program, który sprawdzi czy nawiasy są zrównoważone!

### Zadanie z klamrami
---
Napiszemy program, w którym użytkownik poda ciąg nawiasów, a program sprawdzi czy takie nawiasy są zrównoważone. Program będzie oparty na liniowej strukturze danych, stosie.

#### Implementacja
---
```
#include <iostream>
#include <stack>
#include <string>
bool areParanthesisBalanced(std::string& input) {
    std::stack<char> stack;
    char character;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
            // Kladziemy element na stos
            stack.push(input[i]);
            continue;
        }
        // Jesli obecny znak nie jest nawiasem otwierajacym to
        // musi byc zamykajacym, czyli stos nie moze byc teraz pusty
        if (stack.empty()) {
            return false;
        }
        switch (input[i]) {
        case ')':
            // przechowujemy obecna wartosc wierzcholka w zmiennej charackter
            character = stack.top();
            stack.pop();
            if (character == '{' || character == '[') {
                return false;
            }
            break;
        case '}':
            character = stack.top();
            stack.pop();
            if (character == '(' || character == '[') {
                return false;
            }
            break;
        case ']':
            character = stack.top();
            stack.pop();
            if (character == '(' || character == '{') {
                return false;
            }
            break;
        }
    }
    // Sprawdzamy czy stos jest pusty
    return (stack.empty());
}
int main() {
    std::string input;
    std::cout << "Program that check if paranthiesis are balanced\n"
              << "Type 'q' to quit\n";
    while (true) {
        getline(std::cin, input);
        if (input == "q") {
            break;
        }
        if (areParanthesisBalanced(input)) {
            std::cout << "Balanced\n";
        } else {
            std::cout << "Not Balanced\n";
        }
    }
    return 0;
}
```

### Output
---
```
Program that check if paranthiesis are balanced
Type 'q' to quit
()  
Balanced
[()]
Balanced
{{([])}}
Balanced
{(]
Not Balanced
]([
Not Balanced
q
```
# Kolejka (ang. Queue)
---
Nasi rodzice i dziadkowie wspominają często komunę. My będziemy wspominali Covida. Co łączyło te dwie rzeczy? Kolejki. Wyobraź sobie, że po całej nocy imprezowania wchodzisz do lokalu z kebabem. Stajesz w kolejce i czekasz na swoją kolej. Wyczekujesz tej chwili, aż w końcu zostajesz obsłużony i dostajesz do ręki ciepłą torille, a życie staje się piękniejsze. Pewnie zapytasz teraz "Co to ma wspólnego ze strukturami danych do cholery?!". No właśnie wiele. Nauczyłeś się właśnie jak działa nasza kolejna struktura danych - kolejka (ang. queue). Gratulacje ;) Konkretnie liniowa struktura danych. W naszej struktórce nowe dane dopisywane są na końcu kolejki, a z początku kolejki pobierane są dane do dalszego przetwarzania. Kolejka posiada tzw. bufor FIFO (First In, First Out). 

![](https://www.studytonight.com/code/python/ds/images/queue-basic.png)

Kolejka składa się z początku  (Front, Head) oraz końca (Back, Tail). Operacje związane z kolejką to Enqueue ("zakolejkuj") oraz Dequeue ("odkolejkuj"). Nowy element dodawany zawsze jest na końcu, analogia do klienta na końcu kolejki. Usunięcie z kolejki to analogia do obsłużonego klienta, który taką kolejke opuszcza. Osoba ta czekała najdłużej (tj. znajduję się na początku kolejki, czyli musiala już troche postać :) ). 
## Implementacja
---
Poniżej umieszczam dwie implementacje kolejki:
- implemtnacja kolejki używając stosu znajduje się [tutaj](https://www.geeksforgeeks.org/queue-using-stacks/)
- implemtnacja kolejki używając kontenera deque znajduje się [tutaj](https://www.geeksforgeeks.org/implement-stack-queue-using-deque/?ref=lbp)

## Kolejka w STL.
---

Tym razem omówimy wszystkie cechy kolejki, korzystając z zdefinowanych metod kolejki w bibliotece standardowej. Znajdują się one w headerze *<queue>*. Jest to tak zwany adapter kolejki, który domyślnie jest wrapperem na std::deque. 
## Operacje udostępnione nam przez bibilioteke standardową
---
Operacje, które udostępnia nam bibliotek standardowa to:
- empty() - zwraca true jeśli nasza kolejka jest pusta, zwraca false jeśli nie jest pusta.
- size() - zwraca liczbe elementów znajdujących się w naszej kolejce.
- front() - zwraca wartość zmiennej znajdującej się na początku kolejki.
- back() - zwraca wartość zmiennej znajdującej się na końcu kolejki.
- push() - dodaje wartość na końcu kolejki.
- emplace() - robi to samo co push, złożoność obliczeniowa ta sama, ale... push() powoduje skopiowanie przekazanego elementu, a emplace() tworzy ten element w odpowiednim miejscu na podstawie przekazanych elemetnów. 
- pop() - usuwa wartość z początku kolejki.
- swap() - zamienia zawartość kolejek

Po więcej informacji zapraszam do [dokumentacji](https://en.cppreference.com/w/cpp/container/queue)

## Złożoność czasowa
---
Podobnie jak w przypadku stosu. Operacje te są natychmiastowe!
| Operacja | Złożoność czasowa |
| ------ | ------ |
| push() | O(1) |
| pop() | O(1) |
| emplace() | O(1) |
| front() | O(1) |
| back() | O(1) |
| size() | O(1) |
| empty() | O(1) |
| swap() | O(1) |

## Przykład użycia
---
```
#include <iostream>
#include <queue>
int main() {
    std::queue<int> myQueue;
    for (int i = 0; i < 5; i++) {
        myQueue.push(i);
    }
    std::cout << "Queue front value: " << myQueue.front()
              << " Queue back value:" << myQueue.back() << '\n';
    std::cout << "NOW WE CALL pop()\n";
    myQueue.pop();
    std::cout << "Queue front value: " << myQueue.front()
              << " Queue back value:" << myQueue.back() << '\n';
    return 0;
}
```

## Output
---
```
Queue front value: 0 Queue back value: 4
NOW WE CALL pop()
Queue front value: 1 Queue back value: 4
```
Możemy łatwo zaobserwować, że zawołanie metody pop(), spowodowało usunięcie wartości ,0' z naszej kolejki. Teraz początek naszej kolejki stanowi wartość 1.

## Wykorzystanie
---
Zastosowanie kolejki możemy bardzo często zauważyć w sytuacjach związanych z obsługą zdarzeń. Możemy także natrafić na wykorzystanie jej podczas przesyłu asynchornicznego między dwoma procesami np. bufory IO, potoki, pliki IO itd.

# Kolejka Priorytetowa (ang. Priority Queue)
---
Znacie to uczucie? Jesteście chorzy. Umawiacie się na wizytę do lekarza. Jutro godzina 8:00. Mniej lub bardziej uradowani tym faktem planujecie co do godziny przyszły dzień. Kładziecie się spać i wyczekujecie godziny zero, odwiedzenia przychodni. Wchodzicie równitko o 8:00, zaspani otwieracie gabinet swojego lekarza, a wtedy unosi sie nagły krzyk. "Panie, co Pan!? Pan dopiero co przyszedl, my tu już z Halinką od godziny czekamy!!!". Wiecie, że jesteście umówieni, ale wtedy zadajecie ostateczny cios, wyciągacie legitymacje honorowego dawcy krwi i ostentacyjnie bez tłumaczeń wchodzicie do gabinetu. Dlaczego tak? Bo macie priorytet. Czy to sie komuś podoba czy nie. Tak działa nasza kolejna struktura danych, która jest tak naprawdę modyfikacją poprzedniej. Tą struktuą jest kolejka priorytetowa. Poniżej omówimy sobie działanie takiej kolejki.

![](https://cdn.softwaretestinghelp.com/wp-content/qa/uploads/2019/07/Java-Implementation-for-priority-queue.png)










