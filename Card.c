#include <stdio.h>
#include <string.h>

typedef enum {
	CLUB
	DIAMOND,
	HEART,
	SPADE
} Suit;

typedef enum {
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King
} Rank;

typedef struct {
	Suit cardSuit;
	Rank cardRank;
} Card;



int main(void){
	
}
