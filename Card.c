#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---- Enums ---- */

typedef enum {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
    SUIT_COUNT
} Suit;

typedef enum {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    RANK_COUNT
} Rank;

/* ---- String representations ---- */

static const char *SUIT_NAMES[SUIT_COUNT] = {
    "Clubs", "Diamonds", "Hearts", "Spades"
};

static const char *RANK_NAMES[RANK_COUNT] = {
    "Two", "Three", "Four", "Five", "Six", "Seven",
    "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
};

/* ---- Struct ---- */

typedef struct {
    Suit suit;
    Rank rank;
} Card;

/* ---- Functions ---- */

void initialize_deck(Card deck[]) {
    int s,r,card_count = 0;

    for (s = 0; s < SUIT_COUNT; s++) {
        for (r = 0; r < RANK_COUNT; r++) {
            deck[card_count].suit = s;
            deck[card_count].rank = r;
            card_count++;
        }
    }
}

void print_deck(const Card deck[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%s of %s\n",
               RANK_NAMES[deck[i].rank],
               SUIT_NAMES[deck[i].suit]);
    }
}

/* ---- Fisher-Yates Shuffle ---- */
void shuffle_deck(){
	Card deck[SUIT_COUNT * RANK_COUNT];
	initialize_deck(deck);
	Card temp;
	int size, random_index;
	for(size = 51; size > 0; size--){
		random_index = rand()%size;
		temp = deck[random_index];
		deck[random_index] = deck[size];
		deck[size] = temp;
	}
	print_deck(deck, 52);
}

/* ---- Main ---- */

int main(void) {
	srand(time(NULL));
    Card deck[SUIT_COUNT * RANK_COUNT];

    initialize_deck(deck);
    //print_deck(deck, SUIT_COUNT * RANK_COUNT);
	shuffle_deck();
    return 0;
}

