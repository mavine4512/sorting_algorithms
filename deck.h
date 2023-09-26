#ifndef DECK_H
#define DECK_H
#include <stdlib.h>

/**
 * enum kind_e - A function that enumerates cards
 * @SPADE: spades
 * @HEART: hearts
 * @CLUB: club
 * @DIAMOND: diamonds
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - A function for playing cards
 * @value: The value of the card
 * From "Ace" to "King"
 * @kind: kind of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;

} card_t;

/**
 * struct deck_node_s - Program function for deck nodes
 * @card: pointer to card
 * @prev: pointer to previous node
 * @next: pointer to next node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
#endif

