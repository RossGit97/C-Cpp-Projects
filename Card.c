#include <stdio.h>

typedef enum {
    CLUBS, DIAMONDS, HEARTS, SPADES
} Suit;

typedef enum {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE
} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

void initialize_deck(Card deck[], int size) {
    int card_count = 0;
	int s,r;
    for (s = CLUBS; s <= SPADES; s++) {
        for (r = TWO; r <= ACE; r++) {
            if (card_count < size) {
                deck[card_count].suit = (Suit)s;
                deck[card_count].rank = (Rank)r;
                card_count++;
            }
        }
    }
}

int main(void) {
    Card deck[52];

    initialize_deck(deck, 52);

    /* Optional: simple verification */
    int i;
    for (i = 0; i < 52; i++) {
        printf("Card %2d: suit=%d, rank=%d\n",
               i + 1, deck[i].suit, deck[i].rank);
    }

    return 0;
}

