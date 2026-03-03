# Homework 8: Card Shuffling using Riffle Shuffling (Part 2)

                            _____           |^ ^ ^||^ ^ ^|
                    _____  |K  WW|          |____8||^ ^ ^|
            _____  |Q  ww| | ^ {)|                 |____6|
     _____ |J  ww| | ^ {(| |(.)%%| _____
    |10 ^ || ^ {)| |(.)%%| | |%%%||A .  |
    |^ ^ ^||(.)% | | |%%%| |_%%%>|| /.\ |
    |^ ^ ^|| | % | |_%%%O|        |(_._)|
    |^ ^ ^||__%%[|                |  |  |
    |___0I|                       |____V|

## Goals

This is the second part of two assignments.  This part asks you to
shuffle a deck of cards **multiple times**. Again, 
we always assume that the original deck of cards is ordered, that is, **{A, 2, 3, 4, 5, 6, ...}**, 
and we only consider numbers (not Jokers, or the four colors).
In other words, HW8 has the same setting and background as HW7, 
the only difference is in HW8 is that you'll shuffle the cards **multiple times**.

You will learn:

* Use recursion to solve a problem.
* Understand how to modify a program (you wrote) for a slightly different problem

## What do you need to do?

You will need to implement riffle shuffling of k cards **multiple time** in shuffle.c. 
Your program should take two arguments: total number of cards in the original deck *k*, and number of rounds *r*, 
and output all the possible sequences by shuffling these k cards r rounds.
You can assume r is not greater than 7, (since shuffling 52 cards 7 rounds is sufficiently enough random).

### 1. Why is there no `ifdef` and `endif` in shuffle.c?

This assignment requires only one function `shuffle`. Thus, there is
no need using `ifdef` and `endif`. It is likely that you need to add
additional functions called by `shuffle` (feel free to use the functions you implemented in HW7).

### 2. Testing your code

The testing in HW8 is similar to HW7, so you can reuse most of your Makefile from HW7 to test HW8.
**Remember** to use `valgrind` to check memory leak.

We provide the expected output for four testcases in the `expected` directory:
* k = 3, r = 1 (shuffling 3 cards with 1 round)
* k = 3, r = 2 (shuffling 3 cards with 2 rounds)
* k = 4, r = 2 (shuffling 4 cards with 2 rounds)
* k = 6, r = 2 (shuffling 6 cards with 2 rounds)

HW7 tells you to use `sort` to order outputs so
that they can be compared.  You can extend this further by going
through multiple programs. After `sort`, you can use `uniq` to keep
only unique lines.  

`./hw8 4 2 | sort | uniq`

gives you the unique lines. You need to use `sort` before `uniq`
because `uniq` merge agencent identical lines.  If two identical lines
are not adjacent, `uniq` does not merge them.

You can add `wc` to count the number of lines.

`./hw8 6 2 | sort | uniq | wc`

tells you how many unique lines are generated.

## Grading
You will lose 1 point for every 1 byte of memory leak. In other words, if your program leaks 100 or more bytes, you will **receive zero**.

## Submission
Only submit the following file(s)
1. shuffle.c
