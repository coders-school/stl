<!-- .slide: data-background="#111111" -->

# Kontenery sekwencyjne

## Podsumowanie

<a href="https://coders.school">
    <img width="500px" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Co pamiętasz z kontenerów sekwencyjnych?

### Zapisz w notatkach do tej lekcji jak najwięcej na poniższe tematy

1. <!-- .element: class="fragment fade-in" --> Wymień kontenery sekwencyjne
2. <!-- .element: class="fragment fade-in" --> Które z nich są cache-friendly?
3. <!-- .element: class="fragment fade-in" --> Jakie są złożoności poszczególnych operacji?
4. <!-- .element: class="fragment fade-in" --> Jakie jest zużycie pamięci i układ danych w pamięci?
5. <!-- .element: class="fragment fade-in" --> Które operacje powodują unieważnienie iteratorów?

___

<img width="500" src="../img/sequence_containers.png" alt="Kontenery sekwencyjne" class="plain">

___

<img src="../img/bigO.png" alt="BigO notation" class="plain r-stretch">

___
<!-- .element: style="font-size: 0.8em" -->

## Wskazówki

### Który kontener sekwencyjny wybrać?

* <!-- .element: class="fragment fade-in" --> Używaj <code>std:vector</code> jako domyślny kontener
* <!-- .element: class="fragment fade-in" --> Jeśli z góry znasz rozmiar, użyj <code>std::array</code> (w szczególności zamiast zwykłych tablic)
* <!-- .element: class="fragment fade-in" --> Jeśli często dodajesz lub usuwasz elementy z początku lub końca, użyj <code>std::deque</code>
* <!-- .element: class="fragment fade-in" --> Rozważ <code>std::list</code> zamiast <code>std::deque</code> jeśli wstawiasz lub usuwasz elementy ze środka kontenera
* <!-- .element: class="fragment fade-in" --> Zawsze preferuj <code>std::forward_list</code> niż <code>std::list</code>
* <!-- .element: class="fragment fade-in" --> Nie używaj <code>std::list/std::forward_list</code> jeśli potrzebujesz swobodnego dostępu do dowolnego elementu
* <!-- .element: class="fragment fade-in" --> Ogólnie preferuj <code>std::vector</code> niż <code>std::list</code> (pamięć cache)
* <!-- .element: class="fragment fade-in" --> Jeśli wszystkie elementy będą wymagać dużo pamięci, to raczej nie używaj  <code>std::array</code> z powodu ograniczenia wielkości stosu
* <!-- .element: class="fragment fade-in" --> Jeśli kopiowanie elementów jest bardzo kosztowne, a wstawianie będzie częste, rozważ użycie <code>std::list/std::forward_list</code>
* <!-- .element: class="fragment fade-in" --> Im mniejsze elementy, tym bardziej prawdopodobne, że <code>std::vector</code> to dobry wybór
* <!-- .element: class="fragment fade-in" --> Im większe elementy, tym większe prawdopodobieństwo, że <code>std::list/std::forward_list</code> mogą okazać się lepsze
* <!-- .element: class="fragment fade-in" --> Ale zawsze... mierz, czy po zmianie faktycznie jest szybciej! ZAWSZE MIERZ!
