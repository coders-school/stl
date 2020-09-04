<!-- .slide: data-background="#111111" -->

# STL #2

## Functors, lambdas, algorithms

### Summary

<a href="https://coders.school">
    <img width="500px" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## What was easy to understand?

## What do you want to repeat in the Q&A session?
<!-- .element: class="fragment fade-in" -->

### Save and upload to channel #powtórka on Discord :)
<!-- .element: class="fragment fade-in" -->

___

## Homework

### Post-work

* Task 1 - continuation of the previous task 3 - `grayscaleImages` (6 points)
* Exercise 2 - `insensitivePalindrom` (6 points)
* Exercise 3 - `transformContainers` (6 points)

Also submit PR to the branch `master` in the repo `coders-school/stl`, but make sure to add in the title `STL#2`. You can have any branch in your repo.

#### Bonuses

* 2 points for every task delivered before 21 June 2020 (Sunday) by 23:59
* 3 points for group work for each person in the group. We recommend groups of 3 (like last time)

#### [Repo jobs](https://github.com/coders-school/stl/tree/master/module2/homework)

___

### Pre-work

* Prepare a list of questions for the Q&A session :)
* Make sure your microphone is working and you can talk on Discord
* If you have doubts or broken implementations and want to consult them - send the repo link on #powtórka channel on Discord.
  * You can mark questions with comments in the code
  * You can also write questions in the commentary to the PR
  * You can also ask additional questions live later while discussing the code

___

### Task 1 - `grayscaleImages` cont.

Upgrade the program `grayscaleImages` from previous STL#1 classes (compression, decompression of pictures), so that algorithms are used instead of loops. Operate on your version of the implementation of this task.

You won't find any code in the repo in module2/homework/grayscaleImages. Work on module1/homework/grayscaleImages. If you don't want to overwrite PR with that homework, just create a new branch from this state (but don't forget to merge to it `coders/master` to have these current tasks). If it's complicated - just copy your program `grayscaleImages` to the module2 directory ;)

___

### Task 2 - `insensitivePalindrom`

Write a program that checks if a given string of words is a palindrome. The program should ignore special characters like `,.?()[]`, whitespace such as spaces and newlines and should be case insensitive.

Here, conclude from the tests how to name the function. Create your own source and header files and add them to CMakeLists.txt to build themselves. Details in README.md for this task.

___

### Task 3 - `transformContainers`

1. Write a function `transformContainers` which will accept `std::list<std::string>` and `std::deque<int>`
2. It will remove duplicates from both containers
3. Finally it will convert it to `std::map<int, std::string>` and return it. Use `std::transform`.

Here, conclude from the tests how to name the function. Create your own source and header files and add them to CMakeLists.txt to build themselves. Details in README.md for this task.

___

### Collaboration

Suggestion on how to create a branch for this homework:

```git
git checkout homework1      # homework1 is the name of your branch with homework from STL#1
git checkout -b homework2   # create branch homework2 from current state
git pull coders master      # download and merge changes from coders-school/master, to get module2 directory. There should not be any conflicts
git push origin homework2   # push new branch on your fork
```

Now you can start working (preferably in a group) on the homework2 branch
