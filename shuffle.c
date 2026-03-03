#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do NOT modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  int k = origDeck.size;

  // splits each deck at a midpoint based on i
  for (int i = 0; i < k - 1; i++) {
    int leftSize = i + 1;
    int rightSize = k - leftSize;

    leftDeck[i].size = leftSize;
    rightDeck[i].size = rightSize;

    // fills in the left deck with its required amount of cards, then puts the rest in the right
    memcpy(leftDeck[i].cards, origDeck.cards, leftSize * sizeof(char));
    memcpy(rightDeck[i].cards, &origDeck.cards[leftSize], rightSize * sizeof(char));}
}

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.

void interleaveHelper(CardDeck left, int leftIdx, CardDeck right, int rightIdx, CardDeck result, int resIdx, int round) {
    // base case of both hands being empty
    if (leftIdx == left.size && rightIdx == right.size) {
        shuffle(result, round);
        return;
    }

    // tries to take a card from the left
    if (leftIdx < left.size) {
        result.cards[resIdx] = left.cards[leftIdx];
        interleaveHelper(left, leftIdx + 1, right, rightIdx, result, resIdx + 1, round);
    }

    // tries to take a card from the right
    if (rightIdx < right.size) {
        result.cards[resIdx] = right.cards[rightIdx];
        interleaveHelper(left, leftIdx, right, rightIdx + 1, result, resIdx + 1, round);
    }
}

void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
{
  // creates a result deck to store the combinations
  CardDeck result;
  result.size = leftDeck.size + rightDeck.size;

  // use recursion of helper function
  interleaveHelper(leftDeck, 0, rightDeck, 0, result, 0, round);
}

// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck, int round)
{
  // account for number of shuffles now
  if (round == 0) {
      printDeck(origDeck);
      return;
  }

  // # of ways the deck can be split
  int numSplits = origDeck.size - 1;

  // initializes arrays to contain a max sized split
  CardDeck * leftDecks = malloc(numSplits * sizeof(CardDeck));
  CardDeck * rightDecks = malloc(numSplits * sizeof(CardDeck));

  // divides deck into its constituent split decks
  divide(origDeck, leftDecks, rightDecks);

  for (int i = 0; i < numSplits; i++) {
    // add the number of rounds to the interleave function so the whole code will know how many rounds to iterate
    interleave(leftDecks[i], rightDecks[i], round - 1);
  }

  // freeing memory
  free(leftDecks);
  free(rightDecks);
}