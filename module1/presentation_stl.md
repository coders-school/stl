<!-- .slide: data-background="#111111" -->

# STL

## Krótkie przypomnienie

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## STL - Standard template library

* <!-- .element: class="fragment fade-in" --> Zawiera biblioteki dla kontenerów takich jak <code>std:vector&lt;T&gt;</code>, <code>std::list&lt;T&gt;</code>, <code>std::map&lt;K, V&gt;</code>
* <!-- .element: class="fragment fade-in" --> Zawiera biblioteki umożliwiające wykonywanie wielu algorytmów, takich jak <code>std::max</code>, <code>std::sort</code>
* <!-- .element: class="fragment fade-in" --> Jest napisana na szablonach, zatem jest uniwersalna dla wielu typów
* <!-- .element: class="fragment fade-in" --> Aby móc korzystać z algorytmów STL należy dołączyć do projektu bibliotekę <code>&lt;algorithm&gt;</code>
* <!-- .element: class="fragment fade-in" --> Istnieje też druga biblioteka <code>&lt;numeric&gt;</code>, która zawiera algorytmy numeryczne jak <code>std::accumulate</code>
* <!-- .element: class="fragment fade-in" --> Algorytmy można wykonywać na kontenerach takich jak <code>std:vector&lt;T&gt;</code>, <code>std::list&lt;T&gt;</code>, o ile spełnione są pewne warunki
* <!-- .element: class="fragment fade-in" --> Kontenery są zaimplementowane tak, by iterowanie po nich odbywało się poprzez iteratory
* <!-- .element: class="fragment fade-in" --> Iterator <code>begin()</code> wskazuje na początek kontenera, iterator <code>end()</code> na miejsce za ostatnim elementem w kontenerze

___

## Jak czytać dokumentację

### [https://en.cppreference.com](https://en.cppreference.com)

___

## Q&A
