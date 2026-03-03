// ***
// *** DO NOT modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shuffle.h"

int main(int argc, char ** argv)
{
  char deck[MAX_SIZE] =
    {'A', '2', '3', '4', '5', '6', '7',
     '8', '9', 'T', 'J', 'Q', 'K'};

  if (argc != 3)
    {
      return EXIT_FAILURE;
    }

  int size = (int) strtol(argv[1], NULL, 10);
  int round = (int) strtol(argv[2], NULL, 10);
  // if size is k and round is r
  // shuffle k cards r rounds
  if ((size <= 0) || (size > MAX_SIZE))
    {
      return EXIT_FAILURE;
    }

  if ((round <= 0) || (round > 7))
    {
      // shuffle a deck of 52 cards 7 times are "sufficiently
      // random"
      return EXIT_FAILURE;
    }

  // initialize attributes
  CardDeck origDeck = 
    {
      .size = MAX_SIZE,
      .cards = {0} // set everything to zero right now
    };

  origDeck.size = size;
  memcpy(origDeck.cards, deck, MAX_SIZE * sizeof(origDeck.cards[0]));

  shuffle(origDeck, round);
  
  return EXIT_SUCCESS;
}

